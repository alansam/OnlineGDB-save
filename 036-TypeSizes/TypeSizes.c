/*

     sizes.c
     Displays the size in bytes for each type.
     Written by Matthew Campbell.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

int main( void )
{
     printf( "\n" );
     
     printf( "            sizeof( char ): %2" PRIuPTR "\n"
             "          sizeof( char * ): %2" PRIuPTR "\n",
             sizeof( char ), sizeof( char * ) );

     printf( "       sizeof( short int ): %2" PRIuPTR "\n"
             "     sizeof( short int * ): %2" PRIuPTR "\n",
             sizeof( short int ), sizeof( short int * ) );

     printf( "             sizeof( int ): %2" PRIuPTR "\n"
             "           sizeof( int * ): %2" PRIuPTR "\n",
             sizeof( int ), sizeof( int * ) );

     printf( "            sizeof( long ): %2" PRIuPTR "\n"
             "          sizeof( long * ): %2" PRIuPTR "\n",
	     sizeof( long ), sizeof( long * ) );

     printf( "        sizeof( long int ): %2" PRIuPTR "\n"
             "      sizeof( long int * ): %2" PRIuPTR "\n",
	     sizeof( long int ), sizeof( long int * ) );

     printf( "   sizeof( long long int ): %2" PRIuPTR "\n"
             " sizeof( long long int * ): %2" PRIuPTR "\n",
	     sizeof( long long int ), sizeof( long long int * ) );

     printf( "           sizeof( float ): %2" PRIuPTR "\n"
             "         sizeof( float * ): %2" PRIuPTR "\n",
	     sizeof( float ), sizeof( float * ) );

     printf( "          sizeof( double ): %2" PRIuPTR "\n"
             "        sizeof( double * ): %2" PRIuPTR "\n",
	     sizeof( double ), sizeof( double * ) );

     printf( "     sizeof( long double ): %2" PRIuPTR "\n"
             "   sizeof( long double * ): %2" PRIuPTR "\n",
	     sizeof( long double ), sizeof( long double * ) );

     printf( "          sizeof( size_t ): %2" PRIuPTR "\n"
             "        sizeof( size_t * ): %2" PRIuPTR "\n",
	     sizeof( size_t ), sizeof( size_t * ) );

     printf( "       sizeof( ptrdiff_t ): %2" PRIuPTR "\n"
             "     sizeof( ptrdiff_t * ): %2" PRIuPTR "\n",
	     sizeof( ptrdiff_t ), sizeof( ptrdiff_t * ) );

     printf( "\n" );

     return 0;
}

/*
            sizeof( char ):  1
          sizeof( char * ):  8
       sizeof( short int ):  2
     sizeof( short int * ):  8
             sizeof( int ):  4
           sizeof( int * ):  8
            sizeof( long ):  8
          sizeof( long * ):  8
        sizeof( long int ):  8
      sizeof( long int * ):  8
   sizeof( long long int ):  8
 sizeof( long long int * ):  8
           sizeof( float ):  4
         sizeof( float * ):  8
          sizeof( double ):  8
        sizeof( double * ):  8
     sizeof( long double ): 16
   sizeof( long double * ):  8
          sizeof( size_t ):  8
        sizeof( size_t * ):  8
       sizeof( ptrdiff_t ):  8
     sizeof( ptrdiff_t * ):  8
 */
