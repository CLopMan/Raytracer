#include "ray3.h"
#include "vec3.h"


typedef struct Ray3HitRecord {
    Vec3 point;
    Vec3 normal;
    double t;
} Ray3HitRecord;