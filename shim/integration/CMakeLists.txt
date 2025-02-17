#
# Copyright (C) 2020 Assured Information Security, Inc.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

include(${CMAKE_CURRENT_LIST_DIR}/../../cmake/function/microv_add_integration.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../../cmake/function/microv_add_vm_cross_compile.cmake)

list(APPEND HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/support/integration_utils.hpp
)

microv_add_vm_cross_compile(vms)

microv_add_shim_integration(kvm_create_vcpu HEADERS)
microv_add_shim_integration(kvm_create_vm HEADERS)
#microv_add_shim_integration(kvm_emulate_interrupts HEADERS)
microv_add_shim_integration(kvm_get_regs HEADERS)
microv_add_shim_integration(kvm_get_sregs HEADERS)
microv_add_shim_integration(kvm_get_vcpu_mmap_size HEADERS)
microv_add_shim_integration(kvm_run HEADERS)
microv_add_shim_integration(kvm_set_regs HEADERS)
microv_add_shim_integration(kvm_set_sregs HEADERS)
microv_add_shim_integration(kvm_set_user_memory_region HEADERS)
microv_add_shim_integration(kvm_get_api_version HEADERS)