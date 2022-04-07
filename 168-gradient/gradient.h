
#ifndef __GRADIENT_H__
#define __GRADIENT_H__
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef struct {
    int x;
    int y;
}path_point;
// Odd-numbered size for the view so we have a proper center
#define VIEW_SIZE 11
#define VIEW_RADIUS 5
path_point find_highest_point();
void generate_view(float view[VIEW_SIZE][VIEW_SIZE], int center_y, int center_x);
int declare_peak(int x, int y);
#endif
