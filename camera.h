#ifndef CAMERA_H
#define CAMERA_H

#include "random.h"
#include "vec3.h"
#include "ray3.h"


typedef struct {
    Vec3 origin;
    Vec3 horizontal;
    Vec3 vertical;
    Vec3 lower_left_corner;
} Camera;

Camera Camera_new();

Ray3 get_ray(Camera camera, double u, double v);

#endif