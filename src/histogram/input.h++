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

#ifndef HISTOGRAM__INPUT_HXX
#define HISTOGRAM__INPUT_HXX

#include <vector>
#include "params.h++"

/* Stores the input to this histogram and allows it to be iterated
 * through.  This is pretty simple: create one of these classes to
 * generate the input set, and then just iterate through the words to
 * generate the histogram. */
class input {
private:
    const std::vector<word_t> _words;

public:
    input(void);

public:
    const std::vector<word_t>& words(void) const { return _words; }
    word_t word(size_t i) const { return _words[i % ARRAY_SIZE]; }
};

#endif
