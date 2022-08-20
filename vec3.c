#include "vec3.h"
#include <math.h>
#include "random.h"

Vec3 Vec3_new() {
    Vec3 vector;
    vector.x = 0.0;
    vector.y = 0.0;
    vector.z = 0.0;
    return vector;
}

Vec3 Vec3_fromData(double x, double y, double z) {
    Vec3 vector;
    vector.x = x;
    vector.y = y;
    vector.z = z;
    return vector;
}

Vec3 unit_v3(Vec3 vector) {
    return Vec3_times(vector, 1/Vec3_lenght(vector));
}

double Vec3_x(Vec3 vec) {
    return vec.x;
}

double Vec3_y(Vec3 vec) {
    return vec.y;
}

double Vec3_z(Vec3 vec) {
    return vec.z;
}

Vec3 Vec3_setX(Vec3 self, double x) {
    self.x = x;
    return self;
}

Vec3 Vec3_setY(Vec3 self, double y) {
    self.y = y;
    return self;
}

Vec3 Vec3_setZ(Vec3 self, double z) {
    self.z = z;
    return self;
}

Vec3 Vec3_add(Vec3 self, Vec3 other) {
    self.x += other.x;
    self.y += other.y;
    self.z += other.z;
    return self;
}

Vec3 Vec3_sub(Vec3 self, Vec3 other) {
    self.x -= other.x;
    self.y -= other.y;
    self.z -= other.z;
    return self;
}

Vec3 Vec3_times(Vec3 self, double k) {
    self.x *= k;
    self.y *= k;
    self.z *= k;
    return self;
}

double Vec3_dotProduct(Vec3 self, Vec3 other) {
    return self.x*other.x + self.y*other.y + self.z*other.z;
}

Vec3 Vec3_crossProduct(Vec3 self, Vec3 other) {
    Vec3 out = Vec3_fromData(self.y*other.z - self.z*other.y, -(self.x*other.z - self.z*other.x), self.x*other.y - self.y*other.x);
    return out;
}

double Vec3_lenght(Vec3 self) {
    return sqrt(Vec3_lenghtSquared(self));
}

double Vec3_lenghtSquared(Vec3 self) {
    return self.x*self.x + self.y*self.y + self.z*self.z;
}

Vec3 Vec3_random() {
    return Vec3_fromData(random_double(), random_double(), random_double());
}

Vec3 Vec3_random_min_max(double min, double max) {
    return Vec3_fromData(random_min_max(min, max), random_min_max(min, max), random_min_max(min, max));
}

Vec3 Vec3_random_unit_vector() {
    Vec3 out;
    do {
        out = Vec3_random_min_max(0.0, 2.0);
        out = Vec3_sub(out, Vec3_fromData(1.0, 1.0, 1.0));
    } while (Vec3_lenghtSquared(out) > 1);
    return out;
}
