#ifndef VEC3_H
#define VEC3_H

typedef struct {
    double x;
    double y;
    double z;
} Vec3;

Vec3 Vec3_new();

Vec3 Vec3_fromData(double x, double y, double z);

double Vec3_x(Vec3 vec);

double Vec3_y(Vec3 vec);

double Vec3_z(Vec3 vec);

Vec3 Vec3_setX(Vec3 self, double x);

Vec3 Vec3_setY(Vec3 self, double y);

Vec3 Vec3_setZ(Vec3 self, double z);

Vec3 Vec3_add(Vec3 self, Vec3 other);

Vec3 Vec3_sub(Vec3 self, Vec3 other);

Vec3 Vec3_times(Vec3 self, double k);

double Vec3_dotProduct(Vec3 self, Vec3 other);

Vec3 Vec3_crossProduct(Vec3 self, Vec3 other);

double Vec3_lenght(Vec3 self);

double Vec3_lenghtSquared(Vec3 self);

#endif