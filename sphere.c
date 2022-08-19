#include "sphere.h"
#include "ray3.h"
#include "vec3.h"
#include "math.h"
#include <stdbool.h>

Sphere sphere_fromData(Vec3 center, double radius) {
    Sphere sphere;
    sphere.center = center;
    sphere.radius = radius;
    return sphere;
}

Vec3 sphere_center(Sphere self) {
    return self.center;
}

double sphere_radius(Sphere self) {
    return self.radius;
}
// min_d -> distancia mínima a la que renderiza, max_d -> distancia máxima a la que renderiza
bool sphere_hit(Sphere self, Ray3 ray, double min_d, double max_d, Ray3HitRecord* rec) {
    // vetor from ray.origin to sphere.center
    Vec3 roToSphereCenter = Vec3_sub(self.center, Ray3_origin(ray));
    // distance between ceter and point T of the ray (ortogonal intersection radius and ray)
    double tDistance = Vec3_dotProduct(roToSphereCenter, Ray3_dir(ray));
    Vec3 t = Ray3_at(ray, tDistance);
    //distance squared from center to T
    double d = Vec3_lenghtSquared(Vec3_sub(self.center, t));
    if (d < self.radius*self.radius) {
        // distance from T to the intersection
        double x = sqrt(self.radius*self.radius - d);
        // distance from origin to intersection point
        double interDistance = tDistance - x;
        if (max_d > interDistance && interDistance > min_d) {
            Vec3 intersection = Ray3_at(ray, interDistance);
            Vec3 normal = unit_v3(Vec3_sub(intersection, self.center));
            double origin_to_intersection = tDistance - x;
            rec->normal = normal;
            rec->point = intersection;
            rec->distance = origin_to_intersection;
            return true;
        }
    }
    return false;
}
