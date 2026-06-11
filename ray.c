#include "ray.h"

Ray ray_create(Vec3 origin, Vec3 direction){
    Ray r;
    r.origin = origin;
    r.direction = direction;
    return r;
}

//gives location of the ra y in 3d space
Vec3 ray_at(Ray r, double t){
    return vec3_add(r.origin,vec3_scale(r.direction,t));
}