/*
 * Copyright (C) 2014 Palmer Dabbelt
 *   <palmer.dabbelt@eecs.berkeley.edu>
 *
 * This file is part of dreamer-benchmarks.
 * 
 * dreamer-benchmarks is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * dreamer-benchmarks is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with dreamer-benchmarks.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "input.h++"
#include "output.h++"
#include "params.h++"
#include "timer.h++"
#include <cstdio>
#include <cstdlib>
#include <pthread.h>
#include <vector>
#include <thread>

static void init(void) __attribute__((cold));
static void compute(const input* i, output* o) __attribute__((hot));

int main(int argc, char **argv __attribute__((unused)))
{
    if (argc != 1) {
        std::printf("histogram-intel: Parallel histogram\n");
        return 1;
    }

    input input;
    std::vector<output> outputs(WARMUP_RUNS + AVERAGE_RUNS);
    std::vector<timer> timers(WARMUP_RUNS + AVERAGE_RUNS);

    for (size_t i = 0; i < WARMUP_RUNS + AVERAGE_RUNS; ++i) {
        init();
        timers[i].start();
        compute(&input, &outputs[i]);
        timers[i].stop();
    }

    unsigned long long min = timers[0].usec();
    unsigned long long max = timers[0].usec();
    unsigned long long sum = 0;
    for (int i = WARMUP_RUNS; i < WARMUP_RUNS + AVERAGE_RUNS; ++i) {
        printf("%llu us\n", timers[i].usec());

        if (min > timers[i].usec())
            min = timers[i].usec();
        if (max < timers[i].usec())
            max = timers[i].usec();

        sum += timers[i].usec();
    }

    printf("# MIN  %llu us\n", min);
    printf("# MAX  %llu us\n", max);
    printf("# MEAN %llu us\n", sum / AVERAGE_RUNS);
    printf("# BW   %llu MBps\n", (AVERAGE_RUNS * sizeof(word_t) * INPUT_WORDS) / sum);
}

#if CORE_COUNT == 1
void init(void)
{
}

void compute(const input* input, output* output)
{
    for (size_t index = 0; index < INPUT_WORDS; index += 1) {
        auto i = input->word(index);
        auto bin = i / ((word_t)(-1) / BINS);
        output->inc(bin);
    }
}
#else
static void* compute_main(void *tid_as_ptr);

static pthread_t tids[CORE_COUNT];
static const input* g_input;
static volatile bool barrier;
static output outputs[CORE_COUNT];

void init(void)
{
    barrier = true;

    for (intptr_t i = 0; i < CORE_COUNT; ++i)
        pthread_create(&tids[i], NULL, &compute_main, (void*)i);
}

void compute(const input* input, output* output)
{
    if (input == NULL)
        abort();
    if (output == NULL)
        abort();

    g_input = input;

    barrier = false;

    for (size_t i = 0; i < CORE_COUNT; ++i) {
        pthread_join(tids[i], NULL);
        output->accum(outputs[i]);
    }
}

void* compute_main(void *tid_as_ptr)
{
    while (barrier == true);

    intptr_t tid = (intptr_t)tid_as_ptr;
    const size_t stride = INPUT_WORDS / CORE_COUNT;
    const size_t start = (tid + 0) * stride;
    const size_t end   = (tid + 1) * stride;

    for (size_t index = start; index < end; index += 1) {
        auto i = g_input->word(index);
        auto bin = i / ((word_t)(-1) / BINS);
        outputs[tid].inc(bin);
    }

    return NULL;
}
#endif
