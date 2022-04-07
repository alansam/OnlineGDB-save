#include "gradient.h"
#include <stdio.h>
path_point find_highest_point() {
    float my_view[VIEW_SIZE][VIEW_SIZE]; //my own view, which I will populate
    path_point my_coord;
    int row, col;
    int i = 0;
    while (i < 10) {
        getchar(); //slow down the execution
        generate_view(my_view, my_coord.y, my_coord.x);
        for (row = 0; row < VIEW_SIZE; row++) {
            for (col = 0; col < VIEW_SIZE; col++) {
                printf("%0.2f ", my_view[row][col]);
        }
        printf("\n");
    }
    if (declare_peak(my_coord.x, my_coord.y) == 1) {
        //this is the maximum value
        printf("Wooooohooo!");
            break;
        }
    }
    return my_coord;
}
