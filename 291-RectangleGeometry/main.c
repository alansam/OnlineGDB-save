
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct point point;
struct point {
  double X;
  double Y;
};

typedef struct rectangle rectangle;
struct rectangle {
  point u_l;
  point l_r;
};

char const * point_to_string(char * out, point const pt) {
  sprintf(out, "X: %8.3f, Y: %8.3f", pt.X, pt.Y);

  return out;
}

double rectangle_area(rectangle const rec) {
  double len = rec.l_r.X - rec.u_l.X;
  double hgt = rec.u_l.Y - rec.l_r.Y;
  double area = len * hgt;
  printf("L=%f, H=%f, A=%f\n", len, hgt, area);
  return area;
}

point rectangle_centre(rectangle const rec) {
  double hlen = (rec.l_r.X - rec.u_l.X) / 2.0;
  double hhgt = (rec.u_l.Y - rec.l_r.Y) / 2.0;
  printf(".5H=%f, .5H=%f\n", hlen, hhgt);
  point ctr = { .X = (rec.u_l.X - hlen), .Y = (rec.l_r.Y - hhgt), };
  return ctr;
}

bool rectangle_is_inside(rectangle rec, point pt) {
  bool is_inside = false;
  if ((pt.X >= rec.u_l.X && pt.X <= rec.l_r.X)
  &&  (pt.Y >= rec.l_r.Y && pt.Y <= rec.u_l.Y)) {
    is_inside = true;
  }
  return is_inside;
}

void rectangle_deets(rectangle const rec) {
    char out[30];
    point find = { .X = 0., .Y = 0., };
    puts("----+----|----+----|----+----|----+----|----+----|----+----|----+----|----+----|");
    printf("Upper Left  - %s\n", point_to_string(out, rec.u_l));
    printf("Lower Right - %s\n", point_to_string(out, rec.l_r));
    printf("Centre      - %s\n", point_to_string(out, rectangle_centre(rec)));
    printf("Area        - %11.3f\n", rectangle_area(rec));
    printf("Find point  - %s\n", point_to_string(out, find));
    printf(" is inside? - %s\n", rectangle_is_inside(rec, find) ? "true" : "false");
    find.X = 3;
    find.Y = 3;
    printf("Find point  - %s\n", point_to_string(out, find));
    printf(" is inside? - %s\n", rectangle_is_inside(rec, find) ? "true" : "false");
    find.X = -3;
    find.Y = -3;
    printf("Find point  - %s\n", point_to_string(out, find));
    printf(" is inside? - %s\n", rectangle_is_inside(rec, find) ? "true" : "false");
    putchar('\n');
}

int main() {
  rectangle rs[] = {
    { .u_l = { .X =  2., .Y = 2., }, .l_r = { .X =  4., .Y =  0., }, },
    { .u_l = { .X = -1., .Y = 1., }, .l_r = { .X =  1., .Y = -1., }, },
    { .u_l = { .X =  2., .Y = 5., }, .l_r = { .X =  4., .Y =  1., }, },
    { .u_l = { .X = -2., .Y = 5., }, .l_r = { .X =  4., .Y = -2., }, },
  };
  size_t rs_sz = sizeof rs / sizeof *rs;

  for (size_t r_ = 0ul; r_ < rs_sz; ++r_) {
    rectangle_deets(rs[r_]);
  }

  return 0;
}
