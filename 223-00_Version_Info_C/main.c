
#ifdef __cplusplus
#include <iostream>
#else
#include <stdio.h>
#endif

#include "version_info.h"
#include "identify.h"

int main(int argc, char const * argv[]) {
#ifdef __cplusplus
  std::cout << "Version_Info_C++\n\n";

  using namespace avi;
#else
  printf("Version_Info_C\n\n");
#endif

  version_details();
  identify();

  return 0;
}
