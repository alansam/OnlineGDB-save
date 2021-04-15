
#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
  double radius;

public:
  Circle(void);
  void set_radius(double rad);
  double area();
  double circum();
};

#endif /* CIRCLE_H */
