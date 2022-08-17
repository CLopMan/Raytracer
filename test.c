#include <stdio.h>
#include "color.h"
#include "vec3.h"
int main() {

    // Image

    const int image_width = 256;
    const int image_height = 256;

    // Render

    printf("P3\n%d %d\n255\n", image_width, image_height);
    for (int j = image_height-1; j >= 0; --j) {        
        fprintf(stderr, "\rScanlines remaining: %i\n", j);
        for (int i = 0; i < image_width; ++i) {
            double r = i / (double) (image_width-1);
            double g = j / (double) (image_height-1);
            double b = 0.5;
            Color color = Vec3_fromData(r, g, b);

            Color_output(stdout, color);
        }
    }
        fprintf(stderr, "\nDone.\n");

}