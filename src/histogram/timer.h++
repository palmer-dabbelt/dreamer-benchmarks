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

#ifndef HISTOGRAM__TIMER_HXX
#define HISTOGRAM__TIMER_HXX

#include <cstdint>
#include <time.h>

/* Stores a single timer, which can calculate the difference between
 * two times and store it for later calculation. */
class timer {
private:
    struct timespec _start, _stop;

public:
    timer(void);

public:
    /* These measure the interval over which the timer should run. */
    void start(void) { clock_gettime(CLOCK_MONOTONIC, &_start); }
    void stop(void) { clock_gettime(CLOCK_MONOTONIC, &_stop); }

    /* Returns the internal in micro-seconds that it took for this
     * timer to run. */
    unsigned long long usec(void) const __attribute__((pure));
    unsigned long long nsec(void) const __attribute__((pure));
};

#endif
