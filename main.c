#include <stdio.h>
#include "color.h"
#include <math.h>
#include "vec3.h"
#include "ray3.h"
#include <stdbool.h>
#include "sphere.h"
#include "camera.h"
#define RESOLUTION 400

#define ARRAY_LEN 4

Color ray_color(Ray3 ray, Sphere* spheres, int len) {
    Color color = Color_fromData(232.0/255.9999, 217.0/255.9999, 217.0/255.9999);
    bool hitDeteted = false;
    Ray3HitRecord closest;
    closest.distance = 999999999.0;
    for (int i = 0; i < len; ++i){
        Ray3HitRecord rec;
        if (sphere_hit(spheres[i], ray, 0.0, 200.0, &rec)) {
            //fprintf(stderr, "%i\n", i);
            //return Color_fromData(distanceOgToSp/(double) 1, 0.0, 0.0);
            //fprintf(stderr, "%f %f %f\n", normal.x, normal.y, normal.z);
            //fprintf(stderr, "%f\n", rec.distance);
            hitDeteted = true;
            if (rec.distance < closest.distance) {
                //color = Vec3_times(Color_fromData(Vec3_x(rec.normal) + 1, Vec3_y(rec.normal) + 1, Vec3_z(rec.normal) + 1), 0.5);
                closest = rec;
            }
        }
    }
    if (hitDeteted) {
        Ray3 r;
        Vec3 newDir = Vec3_add(closest.normal, Vec3_random_unit_vector());
        r = newRay_fromData(closest.point, newDir);
        return Vec3_times(ray_color(r, spheres, ARRAY_LEN), 0.5);
    }
    return color;
}

int main() {
    const int samples_per_pixel = 64;
    // lista esferas
    Sphere spheres[ARRAY_LEN];
    //spheres[1] = sphere_fromData(Vec3_fromData(0.0, -1.7, -3.5), 1.0);
    //spheres[0] = sphere_fromData(Vec3_fromData(0.0, -90.0, -3.5), 88.5);
    /*spheres[3] = sphere_fromData(Vec3_fromData(-0.5, 0.0, -1.5), 0.4);
    spheres[4] = sphere_fromData(Vec3_fromData(0.3, 0.1, -1.2), 0.35);*/
    spheres[0] = sphere_fromData(Vec3_fromData(0.0, -10001.0, 0.0), 10000.0);
    spheres[1] = sphere_fromData(Vec3_fromData(-0.6, -1.3, -3.0), 0.3);
    spheres[2] = sphere_fromData(Vec3_fromData(1.9, -1.0, -2.5), 0.4);
    spheres[3] = sphere_fromData(Vec3_fromData( 0.0, -0.5, -1.7), 0.5);
    //Sphere_fromData(Vec3_fromData( 0.3,  0.0, -7.0), 0.6)
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
                color_pixel = Vec3_add(color_pixel, ray_color(r, spheres, ARRAY_LEN));
            }
            color_pixel = Vec3_times(color_pixel, 1/(double) samples_per_pixel);
            Color_output(stdout, color_pixel);
        }
    }
        fprintf(stderr, "\nDone.\n");

}