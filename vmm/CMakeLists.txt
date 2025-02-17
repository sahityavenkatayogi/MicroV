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

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/config/default.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/function/microv_target_source.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/write_constants.cmake)

# ------------------------------------------------------------------------------
# Executable
# ------------------------------------------------------------------------------

add_executable(microv)

# ------------------------------------------------------------------------------
# Includes
# ------------------------------------------------------------------------------

if(HYPERVISOR_TARGET_ARCH STREQUAL "AuthenticAMD" OR HYPERVISOR_TARGET_ARCH STREQUAL "GenuineIntel")
    if(HYPERVISOR_TARGET_ARCH STREQUAL "AuthenticAMD")
        target_include_directories(microv PRIVATE
            include/x64/amd
            src/x64/amd
            ../hypercall/include/x64/amd
        )
    endif()

    if(HYPERVISOR_TARGET_ARCH STREQUAL "GenuineIntel")
        target_include_directories(microv PRIVATE
            include/x64/intel
            src/x64/intel
            ../hypercall/include/x64/intel
        )
    endif()

    target_include_directories(microv PRIVATE
        include/x64
        src/x64
        ../hypercall/include/x64
    )
endif()

target_include_directories(microv PRIVATE
    include
    src
    ../hypercall/include
)

# ------------------------------------------------------------------------------
# Headers
# ------------------------------------------------------------------------------

list(APPEND HEADERS
)

if(HYPERVISOR_TARGET_ARCH STREQUAL "AuthenticAMD" OR HYPERVISOR_TARGET_ARCH STREQUAL "GenuineIntel")
    list(APPEND HEADERS
    )

    if(HYPERVISOR_TARGET_ARCH STREQUAL "AuthenticAMD")
        list(APPEND HEADERS
        )
    endif()

    if(HYPERVISOR_TARGET_ARCH STREQUAL "GenuineIntel")
        list(APPEND HEADERS
        )
    endif()
endif()

# ------------------------------------------------------------------------------
# Sources
# ------------------------------------------------------------------------------

microv_target_source(microv src/main.cpp ${HEADERS})

if(HYPERVISOR_TARGET_ARCH STREQUAL "AuthenticAMD" OR HYPERVISOR_TARGET_ARCH STREQUAL "GenuineIntel")
    microv_target_source(microv src/x64/intrinsic_cpuid_impl.S ${HEADERS})
    microv_target_source(microv src/x64/intrinsic_xrstr_impl.S ${HEADERS})
    microv_target_source(microv src/x64/intrinsic_xsave_impl.S ${HEADERS})
    microv_target_source(microv src/x64/pause.S ${HEADERS})
endif()

# ------------------------------------------------------------------------------
# Definitions
# ------------------------------------------------------------------------------

target_compile_definitions(hypervisor INTERFACE
    MICROV_MAX_PP_MAPS=${MICROV_MAX_PP_MAPS}_umx
    MICROV_MAX_VMS=${MICROV_MAX_VMS}_umx
    MICROV_MAX_VCPUS=${MICROV_MAX_VCPUS}_umx
    MICROV_MAX_GPA_SIZE=${MICROV_MAX_GPA_SIZE}_umx
    MICROV_MAX_SLOTS=${MICROV_MAX_SLOTS}_umx
    MICROV_INTERRUPT_QUEUE_SIZE=${MICROV_INTERRUPT_QUEUE_SIZE}_umx
)

# ------------------------------------------------------------------------------
# Libraries
# ------------------------------------------------------------------------------

target_link_libraries(microv PRIVATE
    runtime
    bsl
    loader
    syscall
    lib
)

# ------------------------------------------------------------------------------
# Install
# ------------------------------------------------------------------------------

if(CMAKE_BUILD_TYPE STREQUAL RELEASE OR CMAKE_BUILD_TYPE STREQUAL MINSIZEREL)
    add_custom_command(TARGET microv POST_BUILD COMMAND ${CMAKE_STRIP} microv)
endif()

install(TARGETS microv DESTINATION bin)
