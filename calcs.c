#include "input-output.h"
#include <stdio.h>

float perimeter(float radius)
{
    float p;
    p = 2 * pi * radius;
    return p;
}

float square(float radius)
{
    float s;
    s = pi * radius * radius;
    return s;
}
