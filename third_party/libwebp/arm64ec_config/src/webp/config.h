/*
 * Copyright 2026 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

// libwebp config used only for Windows ARM64EC builds (HAVE_CONFIG_H is defined
// by //third_party/libwebp:libwebp_defines when current_cpu == "arm64ec").
//
// ARM64EC predefines _M_X64, which makes libwebp's cpu.h select its SSE2/SSE4.1
// code paths. Those intrinsics are not available when compiling ARM64EC code.
// With HAVE_CONFIG_H set, cpu.h only enables x86 SIMD when WEBP_HAVE_SSE2 /
// WEBP_HAVE_SSE41 are defined, so leaving them undefined disables them.
// NEON is still compiled in by cpu.h's _MSC_VER path (clang-cl defines
// _MSC_VER; that path checks _M_ARM64EC directly), and the replacement
// cpu_arm64ec.c makes libwebp pick it at runtime.

#ifndef WEBP_ARM64EC_CONFIG_H_
#define WEBP_ARM64EC_CONFIG_H_

// With HAVE_CONFIG_H, libwebp no longer auto-detects these. Without them,
// clang (which also predefines __x86_64__ on ARM64EC) would use x86 inline
// "bswap" asm in src/utils/endian_inl_utils.h.
#define HAVE_BUILTIN_BSWAP16 1
#define HAVE_BUILTIN_BSWAP32 1
#define HAVE_BUILTIN_BSWAP64 1

#endif  // WEBP_ARM64EC_CONFIG_H_
