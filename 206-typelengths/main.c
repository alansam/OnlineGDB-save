#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

int f1(void);
int f2(void);

int main(int argd, char const * argv[]) {
  f1();
  f2();

  return 0;
}

int f1(void) {
  printf( "Size of C data types:\n\n"                                  );
  printf( "Type               Bytes\n\n"                               );
  printf( "--------------------------------\n"                         );
  printf( "char                 %2zu\n" , sizeof( char )               );
  printf( "int8_t               %2zu\n" , sizeof( int8_t )             );
  printf( "unsigned char        %2zu\n" , sizeof( unsigned char )      );
  printf( "uint8_t              %2zu\n" , sizeof( uint8_t )            );
  printf( "short                %2zu\n" , sizeof( short )              );
  printf( "int16_t              %2zu\n" , sizeof( int16_t )            );
  printf( "uint16t              %2zu\n" , sizeof( uint16_t )           );
  printf( "int                  %2zu\n" , sizeof( int )                );
  printf( "unsigned             %2zu\n" , sizeof( unsigned )           );
  printf( "long                 %2zu\n" , sizeof( long )               );
  printf( "unsigned long        %2zu\n" , sizeof( unsigned long )      );
  printf( "int32_t              %2zu\n" , sizeof( int32_t )            );
  printf( "uint32_t             %2zu\n" , sizeof( uint32_t )           );
  printf( "long long            %2zu\n" , sizeof( long long )          );
  printf( "int64_t              %2zu\n" , sizeof( int64_t )            );
  printf( "unsigned long long   %2zu\n" , sizeof( unsigned long long ) );
  printf( "uint64_t             %2zu\n" , sizeof( uint64_t )           );
  printf( "float                %2zu\n" , sizeof( float )              );
  printf( "double               %2zu\n" , sizeof( double )             );
  printf( "long double          %2zu\n" , sizeof( long double )        );
  printf( "_Bool                %2zu\n" , sizeof( _Bool )              );
  printf( "bool                 %2zu\n" , sizeof( bool )               );
  putchar('\n');

  return 0;
}

int f2(void) {
  printf( "Ranges for integer data types in C\n\n" );
  printf( "------------------------------------------------------------\n");
  printf( "int8_t    %20d  %20d\n"     , SCHAR_MIN , SCHAR_MAX  );
  printf( "int16_t   %20d  %20d\n"     , SHRT_MIN  , SHRT_MAX   );
  printf( "int32_t   %20d  %20d\n"     , INT_MIN   , INT_MAX    );
  printf( "int64_t   %20lld  %20lld\n" , LLONG_MIN , LLONG_MAX  );
  printf( "uint8_t   %20d  %20d\n"     , 0         , UCHAR_MAX  );
  printf( "uint16_t  %20d  %20d\n"     , 0         , USHRT_MAX  );
  printf( "uint32_t  %20d  %20u\n"     , 0         , UINT_MAX   );
  printf( "uint64_t  %20d  %20llu\n"   , 0         , ULLONG_MAX );
  printf( "\n" );
  printf( "============================================================\n\n");
  printf( "Ranges for real number data types in C\n\n" );
  printf( "------------------------------------------------------------\n");
  printf( "flaot        %14.7g  %14.7g\n"   , FLT_MIN  , FLT_MAX  );
  printf( "double       %14.7g  %14.7g\n"   , DBL_MIN  , DBL_MAX  );
  printf( "long double  %14.7Lg  %14.7Lg\n" , LDBL_MIN , LDBL_MAX );
  printf( "\n" );
  return 0;
}
