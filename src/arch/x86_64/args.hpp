/*
  EbbRT: Distributed, Elastic, Runtime
  Copyright (C) 2013 SESA Group, Boston University

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as
  published by the Free Software Foundation, either version 3 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Affero General Public License for more details.

  You should have received a copy of the GNU Affero General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef EBBRT_ARCH_ARGS_HPP
#error "Don't include this file directly"
#endif

#include <cstdint>

#include "lrt/trans.hpp"

namespace ebbrt {
  class Args {
  public:
    inline uint64_t& this_pointer() {
#ifdef __linux__
      if (rdi == reinterpret_cast<uintptr_t>(lrt::trans::default_rep)) {
        return rdi;
      }
      return rsi;
#elif __ebbrt__
      if (rdi > lrt::trans::LOCAL_MEM_VIRT_BEGIN &&
          rdi < lrt::trans::LOCAL_MEM_VIRT_END) {
        return rdi;
      }
      return rsi;
#else
#error "Unsupported Platform"
#endif
    }
    uint64_t rdi;
    uint64_t rsi;
    uint64_t rdx;
    uint64_t rcx;
    uint64_t r8;
    uint64_t r9;
    uint64_t r10;
    uint64_t rax;
    uint64_t fx[64];
    uint64_t ret;
    uint64_t stack_args[0];
  };
}