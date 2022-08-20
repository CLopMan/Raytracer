#include "Color.h"
#include <math.h>

Color Color_new() {
	return Vec3_new();
}

Color Color_fromData(double r, double g, double b) {
	return Vec3_fromData(r, g, b);
}

double Color_r(Color color) {
	return Vec3_x(color);
}

double Color_g(Color color) {
	return Vec3_y(color);
}

double Color_b(Color color) {
	return Vec3_z(color);
}

Color Color_setR(Color color, double r) {
	return Vec3_setX(color, r);
}

Color Color_setG(Color color, double g) {
	return Vec3_setY(color, g);
}

Color Color_setB(Color color, double b) {
	return Vec3_setZ(color, b);
}

void Color_output(FILE* stream, Color color) {
	fprintf(stream, "%d %d %d\n",
		(int) (255.999 * color.x),
		(int) (255.999 * color.y),
		(int) (255.999 * color.z)
	);
}

Color Color_gamma_correction(Color self, double gamma) {
	self.x = pow(self.x, gamma);
	self.y = pow(self.y, gamma);
	self.z = pow(self.z, gamma);
	return self;
}