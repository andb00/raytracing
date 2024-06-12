//
// Created by Andrew Betancourt on 5/30/24.
//

#include "hittable.h"

#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

class sphere : public hittable {
public:
    sphere() {}
    sphere(point3 cen, double r) : center(cen), radius(r) {};

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override
    {
        vec3 oc = center - r.origin();
        auto a = r.direction().length_squared();
        auto h = dot(r.direction(), oc);
        auto c = oc.length_squared() - radius*radius;

        auto discriminant = h*h - a*c;
        if (discriminant < 0) return false;
        auto sqrtd = sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (h - sqrtd) / a;
        if (!ray_t.surrounds(root)) {
            root = (h + sqrtd) / a;
            if (!ray_t.surrounds(root))
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);
        rec.normal = (rec.p - center) / radius;

        return true;
    }

private:
    point3 center;
    double radius;
};


#endif //RAYTRACING_SPHERE_H
