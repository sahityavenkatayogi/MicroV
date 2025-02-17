/**
 * @copyright
 * Copyright (C) 2020 Assured Information Security, Inc.
 *
 * @copyright
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * @copyright
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * @copyright
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef MV_BIT_SIZE_T_H
#define MV_BIT_SIZE_T_H

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
    /**
     * <!-- description -->
     *   @brief Defines different bit sizes for address, operands, etc.
     */
    enum mv_bit_size_t : int32_t
#else
/**
     * <!-- description -->
     *   @brief Defines different bit sizes for address, operands, etc.
     */
enum mv_bit_size_t
#endif
    {
        /** @brief indicates 8 bits */
        mv_bit_size_t_8 = 0,
        /** @brief indicates 16 bits */
        mv_bit_size_t_16 = 1,
        /** @brief indicates 32 bits */
        mv_bit_size_t_32 = 2,
        /** @brief indicates 64 bits */
        mv_bit_size_t_64 = 3,
    };

/** @brief integer version of mv_bit_size_t_8 */
#define BIT_SIZE_8 ((int32_t)mv_bit_size_t_8)
/** @brief integer version of mv_bit_size_t_16 */
#define BIT_SIZE_16 ((int32_t)mv_bit_size_t_16)
/** @brief integer version of mv_bit_size_t_32 */
#define BIT_SIZE_32 ((int32_t)mv_bit_size_t_32)
/** @brief integer version of mv_bit_size_t_64 */
#define BIT_SIZE_64 ((int32_t)mv_bit_size_t_64)

#ifdef __cplusplus
}
#endif

#endif
