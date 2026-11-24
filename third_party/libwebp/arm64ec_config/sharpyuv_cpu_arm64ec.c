/*
 * Copyright 2026 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

// ARM64EC replacement for libwebp's sharpyuv/sharpyuv_cpu.c. That file
// #includes src/dsp/cpu.c with VP8GetCPUInfo renamed to SharpYuvGetCPUInfo;
// this does the same with the ARM64EC implementation. See
// cpu_info_arm64ec.inc.

#include "sharpyuv/sharpyuv_cpu.h"

#include "cpu_info_arm64ec.inc"
