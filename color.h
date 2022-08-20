#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <stdio.h>

typedef Vec3 Color;

Color Color_new();

Color Color_fromData(double r, double g, double b);

double Color_r(Color color);

double Color_g(Color color);

double Color_b(Color color);

Color Color_setR(Color color, double r);

Color Color_setG(Color color, double g);

Color Color_setB(Color color, double b);

void Color_output(FILE* stream, Color color);

Color Color_gamma_correction(Color self, double gamma);

#endif
