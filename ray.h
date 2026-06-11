#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct {Vec3 origin; Vec3 direction;}Ray;

Ray ray_create(Vec3 origin, Vec3 direction);
Vec3 ray_at(Ray r, double t);

#endif