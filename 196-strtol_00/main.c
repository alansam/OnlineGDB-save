#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const * argv[]) {
    char * endptr;
    long val;
    //  with sample input:
    //  -105 10f4 a
    //  output:
    //  105 <> 10 <f4> 0 <a>
    for (size_t i_ = 1ul; i_ < argc; ++i_) {
        printf("%s ", argv[i_]);
    }
    putchar('\n');
    putchar('\n');

    int bases[] = { 2, 4, 8, 10, 16, 36, };
    size_t const bases_sz = sizeof(bases) / sizeof(*bases);
    for (size_t b_ = 0; b_ < bases_sz; ++b_) {
        printf("Using base %2d\n", bases[b_]);
        for (size_t i_ = 1ul; i_ < argc; ++i_) {
            val = strtol(argv[i_], &endptr, bases[b_]);
            char tail[16];
            sprintf(tail, "<%s>", endptr);
            printf("%8ld%9s", val, tail);
        }
        putchar('\n');
        putchar('\n');
    }
    putchar('\n');

    return EXIT_SUCCESS;
}
