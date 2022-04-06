//
//  snap.c
//  CF.snap
//
//  Created by Alan Sampson on 6/22/20.
//  Copyright © 2020 Alan @ FreeShell. All rights reserved.
//

#include "snap.h"

//  MARK: - Implementation.
/*
 *  MARK: snap()
 *  SVC 51 (0A33)
 */
int snap(FILE * fp, void const * opvar, size_t op_l) {

  octet const * op = (octet const *) opvar;
  int chr_ct = 0;

  size_t const LL = 0x20; //  snap line length (32)
  size_t const GP = 0x08; //  distance between print gaps
  octet const * op_end = op + op_l;
  octet const * op_now = op;

  chr_ct += fprintf(fp, "%p:\n", op);
  while (op_now < op_end) {
    octet const * hex_p = op_now;
    octet const * chr_p = op_now;

    chr_ct += fprintf(fp, "%04" PRIxPTR ": ", hex_p - op);
    for (size_t xc = 0, sp = 1; xc < LL; ++xc) {
      octet const * loc = hex_p++;
      if (loc < op_end) {
        octet x_ = *loc;
        chr_ct += fprintf(fp, "%02" PRIx8 "%s", x_, (sp++ % GP == 0) ? " " : "");
      }
      else {
        chr_ct += fprintf(fp, "  %s", (sp++ % GP == 0) ? " " : "");
      }
    }
    chr_ct += fprintf(fp, " ");

    for (size_t cc = 0, sp = 1; cc < LL; ++cc) {
      octet const * loc = chr_p++;
      octet c_ = loc < op_end ? *loc : ' ';
      chr_ct += fprintf(fp, "%c%s", isprint(c_) ? c_ : '.', (sp++ % GP == 0) ? " " : "");
    }
    chr_ct += fprintf(fp, "\n");
    op_now += LL;
  }
  chr_ct += fprintf(fp, "\n");

  return chr_ct;
}
