/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#include "quantum.h"

#define LAYOUT( \
    k00, \
    k10, k11, k12, \
    k20, k21, k22, \
    k30, k31, k32, \
    k40, k41, k42 \
) { \
    { k00, k10, k11, k12, k20, k21, k22, k30, k31, k32, k40, k41, k42 }, \
}
