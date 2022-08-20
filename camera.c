#include "camera.h"
#include "vec3.h"
#include "ray3.h"

Camera Camera_new() {
    double aspect_ratio = 16.0 / 9.0;
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 2.0;

    Camera camera;
    camera.origin = Vec3_fromData(0.0, 0.0, 0.0);
    camera.horizontal = Vec3_fromData(viewport_width, 0.0, 0.0);
    camera.vertical = Vec3_fromData(0.0, viewport_height, 0.0);
    camera.lower_left_corner = Vec3_sub(Vec3_sub(Vec3_sub(camera.origin, Vec3_times(camera.horizontal, 1/2.0)), Vec3_times(camera.vertical, 1/2.0)), Vec3_fromData(0, 0, focal_length));
    return camera;
}

Ray3 get_ray(Camera camera, double u, double v) {
    Vec3 dir = Vec3_times(camera.horizontal, u);
    dir = Vec3_add(dir, Vec3_times(camera.vertical, v));
    dir = Vec3_add(dir, camera.lower_left_corner);
    dir = Vec3_sub(dir, camera.origin);
    Ray3 ray = newRay_fromData(camera.origin, dir);
    return ray;
}