//
//  snap.h
//  CF.snap
//
//  Created by Alan Sampson on 6/22/20.
//  Copyright © 2020 Alan @ FreeShell. All rights reserved.
//

#ifndef snap_h
#define snap_h

#ifdef __cplusplus
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cinttypes>
#include <cctype>
#else
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <ctype.h>
#endif

//  MARK: - Definitions.
typedef uint8_t octet;

#ifdef __cplusplus
extern "C"
#endif
int snap(FILE * fp, void const * op, size_t op_l);

#endif /* snap_h */
