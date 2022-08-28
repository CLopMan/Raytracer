#ifndef SPHERE_H
#define SPHERE_H

#include "ray3.h"
#include "vec3.h"
#include <stdbool.h>

typedef struct Sphere {
    Vec3 center;
    double radius;
    Vec3 weights;
    } Sphere;

typedef struct Ray3HitRecord {
    Vec3 point;
    Vec3 normal;
    double distance;
} Ray3HitRecord;

Sphere sphere_fromData(Vec3 center, double radius, Vec3 weights);

Vec3 sphere_center(Sphere self);

double sphere_radius(Sphere self);

bool sphere_hit(Sphere self, Ray3 ray, double min_d, double max_d, Ray3HitRecord* rec);

#endif