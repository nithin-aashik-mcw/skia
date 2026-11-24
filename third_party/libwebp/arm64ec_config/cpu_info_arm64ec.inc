/*
 * Copyright 2026 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

// Shared body of the ARM64EC replacements for libwebp's src/dsp/cpu.c and
// sharpyuv/sharpyuv_cpu.c. Include after "src/dsp/cpu.h" (directly, or via
// "sharpyuv/sharpyuv_cpu.h", which renames VP8GetCPUInfo).
//
// Upstream cpu.c selects its x86 CPUID path on ARM64EC, because __x86_64__ and
// _M_X64 are predefined there, and that x86 inline asm fails to compile. Even
// if it compiled, x86CPUInfo() would report kNEON as unavailable, so libwebp's
// NEON code would never be used. ARM64EC code always runs on ARM64, which
// always has NEON, so this mirrors upstream's armCPUInfo().

static int Arm64ECCPUInfo(CPUFeature feature) {
  return feature == kNEON;
}

WEBP_EXTERN VP8CPUInfo VP8GetCPUInfo;
VP8CPUInfo VP8GetCPUInfo = Arm64ECCPUInfo;
