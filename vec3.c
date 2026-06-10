#include "vec3.h"
#include <math.h>

/*
Vec3 vec3_add(Vec3 a, Vec3 b);
Vec3 vec3_sub(Vec3 a, Vec3 b);
Vec3 vec3_scale(Vec3 a, double t);
double vec3_dot(Vec3 a, Vec3 b);
double vec3_length(Vec3 a);
Vec3 vec3_normalize(Vec3 a);
Vec3 vec3_cross(Vec3 a, Vec3 b);
Vec3 vec3_negate(Vec3 a);
*/

Vec3 vec3_add(Vec3 a, Vec3 b){
    Vec3 ret;
    ret.x = a.x+b.x;
    ret.y = a.y+b.y;
    ret.z = a.z+b.z;
    return ret;
}

Vec3 vec3_sub(Vec3 a, Vec3 b){
    Vec3 ret;
    ret.x = a.x-b.x;
    ret.y = a.y-b.y;
    ret.z = a.z-b.z;
    return ret;
}

Vec3 vec3_scale(Vec3 a, double t){
    Vec3 ret;
    ret.x = (a.x)*t;
    ret.y = (a.y)*t;
    ret.z = (a.z)*t;
    return ret;
}

//dot product, allignment betwenn tow vectors
double vec3_dot(Vec3 a, Vec3 b){return (double)(a.x*b.x+a.y*b.y+a.z*b.z);}

double vec3_length(Vec3 a){return (double)sqrt(a.x*a.x + a.y*a.y + a.z*a.z);}

Vec3 vec3_normalize(Vec3 a){return vec3_scale(a, 1/vec3_length(a));}

//return vector perpindicular to inputs
Vec3 vec3_cross(Vec3 a, Vec3 b){
    Vec3 ret;
    /*
    (ay*bz - az*by,
    az*bx - ax*bz,
    ax*by - ay*bx)
    */

    ret.x = a.y*b.z - a.z*b.y;
    ret.y = a.z*b.x - a.x*b.z;
    ret.z = a.x*b.y - a.y*b.x;

    return ret;
}

Vec3 vec3_negate(Vec3 a){
    Vec3 ret;
    ret.x = a.x * -1;
    ret.y = a.y * -1;
    ret.z = a.z * -1;
    return ret;
}