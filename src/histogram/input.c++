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

static std::vector<word_t> gen_words(void);

input::input(void)
    : _words(gen_words())
{
}

std::vector<word_t> gen_words(void)
{
    std::vector<word_t> out(ARRAY_SIZE);

    srand(0);
    for (size_t i = 0; i < ARRAY_SIZE; ++i)
        out[i] = rand();

    return out;
}
