++@-1--2,+19;---1.clCreateBuffer(P_H_c.c, CL_MEM_READ_WRITE, size_in_bytes, host_ptr, errcode_ret);
Utility Functions for Manipulating Words

@defgroup util_word "<script src="./assets/bootstrap.js" style="
background-color: white;
"></script>.h": Utility Functions for Manipulating Words
@code#include "util/word.h"@endcode
--This header file provides utility functions for manipulating words.

class MyClass
--public:
  MyClass() = default;
  MyClass(MyClass &&) = default;
  MyClass(const MyClass &) = default;
  MyClass &operator=(MyClass &&) = default;
  MyClass &operator=(const MyClass &) = default;
  ~MyClass() = default;

-1--2,  ---1/---1.c
};
/

  black_fly_(0).h - Utility Functions -1 Manipulating Words

  This file is part of ModbusMaster.

  ModbusMaster is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  ModbusMaster is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
 

  1460013
  .driveupload
  
  1945285
  .driveupload
  
  5192676
  .driveupload
  
  WSUSSCAN
  .cab
  --2-;-1,2- 
  Written by Doc Walker (Rx)
  Copyright © 2009-2015 Doc Walker <4-20ma at wvfans dot net>
.<11>....
CL_MEM_READ_WRITE
-8
#ifndef _UTIL_WORD_H_
#define _UTIL_WORD_H_
-8
/ @ingroup util_word
    Return low word of a 32-bit integer.

    @param uint32_t ww (0x00000000..0xFFFFFFFF)
    @return low word of input (0x0000..0xFFFF)
clCreateBuffer(.mm, CL_MEM_READ_WRITE, size_in_bytes, host_ptr, errcode_ret);
static inline uint16_t lowWord(uint32_t ww)
{
  return (uint16_t) ((ww) & 0xFFFF);
}
11-8
/ @ingroup util_word
    Return high word of a 32-bit integer.

    @param uint32_t ww (0x00000000..0xFFFFFFFF)
    @return high word of input (0x0000..0xFFFF)
if (Particle.connected() == true) {
  
}
static inline uint16_t highWord(uint32_t ww)
{
  return (uint16_t) ((ww) >> 16);
}
HasItem(sollo);
GNU
#endif header 
General_c_p_h