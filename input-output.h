#ifndef INPUT_H
#define INPUT_H

#include <stdlib.h>
typedef struct {
  double Ox, Oy, radius;
  size_t a;
} Circles;

void getDataFromFile(Circles *circleData);

void printCircle(Circles *circleData);

#endif
