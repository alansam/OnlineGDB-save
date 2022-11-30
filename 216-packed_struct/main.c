
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
hey guys,

i'm trying to get my head around the following issue:
*/

// #define NOPACK_
#define GLOBALS_

typedef struct
#ifndef NOPACK_
__attribute__((packed))
#endif
{
  // (some data in here)
  uint32_t id;
  uint16_t dp0;
  uint8_t  cp0;
  uint64_t dp1;
  uint8_t  cp1;
  char     name[13];
  uint32_t fl0;
} crsfRcChannel_packed_t;

#ifdef GLOBALS_
extern
crsfRcChannel_packed_t * crsfRcChannel_packed_p, crsfRcChannel_packed;
crsfRcChannel_packed_t * crsfRcChannel_packed_p, crsfRcChannel_packed;
#endif

void show_by_value(crsfRcChannel_packed_t crsfRcChannel_packed);
void show_by_address(crsfRcChannel_packed_t * crsfRcChannel_packed_p);
static
inline
void show_fnuc(char * nm, void * fp) {
  printf("%20s entry point: %p\n", nm, fp);
}

int main() {
#ifndef GLOBALS_
  crsfRcChannel_packed_t * crsfRcChannel_packed_p, crsfRcChannel_packed;
#endif
  crsfRcChannel_packed_p = &crsfRcChannel_packed;

  show_fnuc("main()", &main);
  show_fnuc("show_by_value()", &show_by_value);
  show_fnuc("show_by_address()", &show_by_address);
  show_fnuc("show_fnuc()", &show_fnuc);
  putchar('\n');

  crsfRcChannel_packed.id = 1024u;
  crsfRcChannel_packed.dp0 = 0xffff;
  crsfRcChannel_packed.cp0 = 'a';
  crsfRcChannel_packed.dp1 = 0x7fff;
  crsfRcChannel_packed.cp1 = 'z';
  strcpy(crsfRcChannel_packed.name, "Blobby");
  crsfRcChannel_packed.fl0 = 0xf0;

  show_by_value(crsfRcChannel_packed);
  show_by_address(&crsfRcChannel_packed);

  return 0;
}

void show_by_value(crsfRcChannel_packed_t crsfRcChannel_packed) {
  printf("In fnuction %s()\n", __func__);

  printf("struct addr: %p\n", &crsfRcChannel_packed);

  printf("struct sz: %zu\n\n", sizeof crsfRcChannel_packed);
  printf(".  ID: %6u\n", crsfRcChannel_packed.id);
  printf(". dp0: %6u\n", crsfRcChannel_packed.dp0);
  printf(". cp0: '%c'\n", crsfRcChannel_packed.cp0);
  printf(". dp1: %6lu\n", crsfRcChannel_packed.dp1);
  printf(". cp1: '%c'\n", crsfRcChannel_packed.cp1);
  printf(".name: '%s'\n", crsfRcChannel_packed.name);
  printf(". fl0: %08x\n", crsfRcChannel_packed.fl0);
  putchar('\n');

  return;
}

void show_by_address(crsfRcChannel_packed_t * crsfRcChannel_packed_p) {
  printf("In fnuction %s()\n", __func__);

  printf("struct addr: %p\n", crsfRcChannel_packed_p);

  printf("&  ID: %6u\n", crsfRcChannel_packed_p->id);
  printf("& dp0: %6u\n", crsfRcChannel_packed_p->dp0);
  printf("& cp0: '%c'\n", crsfRcChannel_packed_p->cp0);
  printf("& dp1: %6lu\n", crsfRcChannel_packed_p->dp1);
  printf("& cp1: '%c'\n", crsfRcChannel_packed_p->cp1);
  printf("&name: '%s'\n", crsfRcChannel_packed_p->name);
  printf("& fl0: %08x\n", crsfRcChannel_packed_p->fl0);
  putchar('\n');

  return;
}

/*
the compiler response:

crsfRcChannel_packed_p = &crsfRcChannel_packed;  -> conflicting types for 'crsfRcChannel_packed_p'

and 

crsfRcChannel_packed_t *crsfRcChannel_packed_p, crsfRcChannel_packed; -> previous declaration of 'crsfRcChannel_packed_p' was here

can you give me a hint on what the issue is there?
*/


