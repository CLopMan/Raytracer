#include <stdio.h>
#include "color.h"
#include <math.h>
#include "vec3.h"
#include "ray.h"
#include <stdbool.h>

double ray_hits_sphere(Vec3 center, double radius, Ray3 ray) {
    /*double distance = Vec3_lenght(Vec3_crossProduct(Vec3_sub(center, Ray3_origin(ray)), Ray3_dir(ray)));
    return distance < radius;*/

    // this is asuming dir is an unitary vector
    Vec3 roToSphereCenter = Vec3_sub(center, Ray3_origin(ray));
    double tDistance = Vec3_dotProduct(roToSphereCenter, Ray3_dir(ray));
    Vec3 t = Vec3_add(Ray3_origin(ray), Vec3_times(Ray3_dir(ray), tDistance));
    double d = Vec3_lenghtSquared(Vec3_sub(center, t));
    double x = sqrt(d - radius*radius);
    return x;
    
    
}

Color ray_color(Ray3 ray) {
    if (ray_hits_sphere(Vec3_fromData(0, 0, -1), 0.5, ray)) {
        return Color_fromData(1.0, 0.0, 0.0);
    }
    return Color_fromData(0.0, 0.0, 0.0);
}

int main() {


    // Image
    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = (int) (image_width / aspect_ratio);

    // Camera

    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    Vec3 origin = Vec3_fromData(0, 0, 0);
    Vec3 horizontal = Vec3_fromData(viewport_width, 0, 0);
    Vec3 vertical = Vec3_fromData(0, viewport_height, 0);
    Vec3 lower_left_corner = Vec3_sub(Vec3_sub(Vec3_sub(origin, Vec3_times(horizontal, 1/2.0)), Vec3_times(vertical, 1/2.0)), Vec3_fromData(0, 0, focal_length));


    // Render

    printf("P3\n%d %d\n255\n", image_width, image_height);
    for (int j = image_height-1; j >= 0; --j) {        
        fprintf(stderr, "\rScanlines remaining: %i\n", j);
        for (int i = 0; i < image_width; ++i) {
            double u = i / (double) (image_width-1);
            double v = j / (double) (image_height-1);
            Ray3 r = newRay_fromData(origin, Vec3_sub(Vec3_add(Vec3_add(lower_left_corner, Vec3_times(horizontal, u)), Vec3_times(vertical, v)), origin));
            Color pixel_color = ray_color(r);

            Color_output(stdout, pixel_color);
        }
    }
        fprintf(stderr, "\nDone.\n");

}