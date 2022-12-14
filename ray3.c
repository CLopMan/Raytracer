#include "ray3.h"
#include "vec3.h"

Ray3 newRay() {
    Vec3 vector = Vec3_new();
    return newRay_fromData(vector, vector);
}

Ray3 newRay_fromData(Vec3 origin, Vec3 dir) {
    Ray3 ray;
    ray.dir = unit_v3(dir);
    ray.origin = origin;
    return ray;
}

Vec3 Ray3_origin(Ray3 ray) {
    return ray.origin;
}

Vec3 Ray3_dir(Ray3 ray) {
    return ray.dir;
}

Vec3 Ray3_at(Ray3 ray, double t) {
    return Vec3_add(ray.origin, Vec3_times(ray.dir, t));
}

double dotLine_distance(Vec3 dot, Ray3 ray) {
    return Vec3_lenght(Vec3_crossProduct(Vec3_sub(dot, Ray3_origin(ray)), Ray3_dir(ray)));
}
