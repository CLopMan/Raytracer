#include <stdio.h>
#include "color.h"
#include <math.h>
#include "vec3.h"
#include "ray3.h"
#include <stdbool.h>
#include "sphere.h"
#include "camera.h"
#define RESOLUTION 1280

Color ray_color(Ray3 ray, Sphere* spheres, int len) {
    double min_p = 200.0;
    Color color = Color_fromData(0.0, 0.0, 1.0);
    for (int i = 0; i < len; ++i){
        Ray3HitRecord rec;
        if (sphere_hit(spheres[i], ray, 0.0, 200.0, &rec)) {
            //fprintf(stderr, "%i\n", i);
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
    const int samples_per_pixel = 64;
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
    Camera camera;
    camera = Camera_new();

    // Render

    printf("P3\n%d %d\n255\n", image_width, image_height);
    for (int j = image_height-1; j >= 0; --j) {        
        fprintf(stderr, "\rScanlines remaining: %i\n", j);
        for (int i = 0; i < image_width; ++i) {
            Color color_pixel = Color_fromData(0.0, 0.0, 0.0);
            for (int k = 0; k < samples_per_pixel; ++k) {
                double u = (i + random_double()) / (double) (image_width-1);
                double v = (j + random_double()) / (double) (image_height-1);
                //fprintf(stderr, " %f %f\n", u, v);
                Ray3 r = get_ray(camera, u, v);
                color_pixel = Vec3_add(color_pixel, ray_color(r, spheres, 4));
            }
            color_pixel = Vec3_times(color_pixel, 1/(double) samples_per_pixel);
            Color_output(stdout, color_pixel);
        }
    }
        fprintf(stderr, "\nDone.\n");

}