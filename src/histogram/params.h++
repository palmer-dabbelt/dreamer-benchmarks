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

#ifndef HISTOGRAM__PARAMS_HXX
#define HISTOGRAM__PARAMS_HXX

#include <cstdint>
#include <cstdlib>

/* The number of bins to target with our histogram. */
#define BINS 128

/* The number of input words (and the size of an input word) that we
 * want to sum up. */
#define INPUT_WORDS (1ULL << 30)
#define ARRAY_SIZE  (1ULL << 30)
typedef uint32_t word_t;

/* The number of times to run the calculation in order to warm up
 * everything. */
#define WARMUP_RUNS 8

/* The number of times to average the output. */
#define AVERAGE_RUNS 16

#endif
