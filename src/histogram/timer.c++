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

#include "timer.h++"

timer::timer(void)
{
}

unsigned long long timer::usec(void) const
{
    return nsec() / 1000;
}

unsigned long long timer::nsec(void) const
{
    unsigned long long dsec = _stop.tv_sec - _start.tv_sec;
    unsigned long long dnsec = dsec * 1000 * 1000 * 1000;
    return dnsec + _stop.tv_nsec - _start.tv_nsec;
}
