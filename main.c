#include "input-output.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const size_t max_figures_count = 100;

int main() {
  Circles circleData[max_figures_count];

  getDataFromFile(circleData);
  printCircle(circleData);

  return 0;
}
