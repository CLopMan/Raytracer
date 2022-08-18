#ifndef RAY3_H

#define RAY3_h

#include "vec3.h"

typedef struct {
    Vec3 origin;
    Vec3 dir;
} Ray3;

Ray3 newRay();

Ray3 newRay_fromData(Vec3 origin, Vec3 vector);

Vec3 Ray3_origin(Ray3 ray);

Vec3 Ray3_dir(Ray3 ray);

Vec3 Ray3_at(Ray3 ray, double t);

double dotLine_distance();

#endif