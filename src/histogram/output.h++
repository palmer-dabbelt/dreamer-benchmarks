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

#ifndef HISTOGRAM__OUTPUT_HXX
#define HISTOGRAM__OUTPUT_HXX

#include "params.h++"
#include <vector>

/* Stores the output of a histogram run, for later verification. */
class output {
private:
    std::vector<word_t> _bins;

public:
    output(void);

public:
    std::vector<word_t>& bins(void) { return _bins; }
    void inc(size_t index) { _bins[index]++; }
    void accum(const output& that);
};

#endif
