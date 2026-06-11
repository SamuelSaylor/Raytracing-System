#ifndef COLOR_H
#define COLOR_H

#include "vec3.c"
#include <stdio.h>

typedef Vec3 Color;

void write_color(FILE *out, Color pixel_color){
    int r = (int)(255.999*pixel_color.z);
    int g = (int)(255.999*pixel_color.y);
    int b = (int)(255.999*pixel_color.z);
    fprintf(out, "%d %d %d\n", r, g, b);
}

#endif