#include <stdio.h>
#include "color.h"
#include <math.h>
#include "vec3.h"
#include "ray3.h"
#include <stdbool.h>
#include "sphere.h"
#define RESOLUTION 400

Color ray_color(Ray3 ray, Sphere* spheres, int len) {
    double min_p = 200.0;
    Color color = Color_fromData(0.0, 0.0, 1.0);
    for (int i = 0; i < len; ++i){
        Ray3HitRecord rec;
        if (sphere_hit(spheres[i], ray, 0.0, 200.0, &rec)) {
            //return Color_fromData(distanceOgToSp/(double) 1, 0.0, 0.0);
            //fprintf(stderr, "%f %f %f\n", normal.x, normal.y, normal.z);
            //fprintf(stderr, "%f\n", rec.distance);
            if (rec.distance < min_p) {
                color = Vec3_times(Color_fromData(Vec3_x(rec.normal) + 1, Vec3_y(rec.normal) + 1, Vec3_z(rec.normal) + 1), 0.5);;
                min_p = rec.distance;
            }
        }
    }
    return color;
}

int main() {

    // lista esferas
    Sphere spheres[4];
    spheres[0] = sphere_fromData(Vec3_fromData(0, -0.25, -1.0), 0.3);
    spheres[1] = sphere_fromData(Vec3_fromData(-0.5, 0.0, -1.5), 0.4);
    spheres[2] = sphere_fromData(Vec3_fromData(0.3, 0.1, -1.2), 0.35);
    spheres[3] = sphere_fromData(Vec3_fromData(0.0, -10001.0, -10.0), 10000);
    // Image
    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = RESOLUTION;
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
            Color pixel_color = ray_color(r, spheres, 4);

            Color_output(stdout, pixel_color);
        }
    }
        fprintf(stderr, "\nDone.\n");

}