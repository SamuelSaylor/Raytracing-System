#ifndef VEC3_H
#define VEC3_H

typedef struct vec3{ double x,y,z; } Vec3;

Vec3 vec3_add(Vec3 a, Vec3 b);
Vec3 vec3_sub(Vec3 a, Vec3 b);
Vec3 vec3_scale(Vec3 a, double t);
double vec3_dot(Vec3 a, Vec3 b);
double vec3_length(Vec3 a);
Vec3 vec3_normalize(Vec3 a);
Vec3 vec3_cross(Vec3 a, Vec3 b);
Vec3 vec3_negate(Vec3 a);

#endif