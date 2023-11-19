// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

#define LAYOUT( \
    K00, K01, K02, K03,\
    K10, K11, K12, K13, K14, \
    R00, R01,  R10, R11\
  ) \
  { \
    { K00, K01, K02, K03 }, \
    { K10, K11, K12, K13, K14 }, \
    { R00, R01, R10, R11}, \
  }
