#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "vec3.h"
#include "color.h"
#include "ray.h"

//Choose whatever colors you want here, scale 0-1
int red = 1; 
int green = 0;
int blue = 0.2;

/*
a=d⋅d
b=−2d⋅(C−Q)
c=(C−Q)⋅(C−Q)−r^2
*/
double hit_sphere(Vec3 center, double radius, Ray r){
    Vec3 cen = vec3_sub(center,r.origin);
    
    double a = vec3_dot(r.direction,r.direction);
    double b = -2.0 * vec3_dot(r.direction,cen);
    double c = vec3_dot(cen,cen) - radius*radius;

    double ret = b*b - 4*a*c;

    if(ret<0){return -1.0;}
    else{return (-b - sqrt(ret))/(2.0*a);}
}

//blendedValue=(1−a)⋅startValue+a⋅endValue
Color ray_color(Ray r){
    double check = hit_sphere((Vec3){0,0,-1},0.5,r);
    if(check>0.0){
        Vec3 ret = vec3_normalize(vec3_sub(ray_at(r, check), (Vec3){0, 0, -1}));
        return vec3_scale(vec3_add(ret, (Vec3){red, green, blue}), 0.5);
    }

    Vec3 unit_direction = vec3_normalize(r.direction);
    double a = 0.5 * (unit_direction.y + 1.0);
    return vec3_add(vec3_scale((Vec3){1.0, 1.0, 1.0}, 1.0 - a), vec3_scale((Vec3){0.5, 0.7, 1.0}, a));
}

int main(){

    double aspect_ratio = 16.0/9.0;
    int image_width = 256;

    int image_height = (int)(image_width / aspect_ratio);
    if(image_height < 1){image_height = 1;}

    //camera values
    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * ((double)image_width / (double)image_height);
    Vec3 centerpoint = {0,0,0};

    Vec3 viewport_horizontal = {viewport_width,0,0};
    Vec3 viewport_vertical = {0,viewport_height*-1.0,0};

    Vec3 horizontal_delta = {viewport_horizontal.x/image_width, viewport_horizontal.y/image_width, viewport_horizontal.z/image_width};
    Vec3 vertical_delta = {viewport_vertical.x/image_height, viewport_vertical.y/image_height, viewport_vertical.z/image_height};

    Vec3 leftcorner = vec3_sub(
        vec3_sub(
            vec3_sub(centerpoint, (Vec3){0, 0, focal_length}),
            vec3_scale(viewport_horizontal, 0.5)
        ),
        vec3_scale(viewport_vertical, 0.5)
    );
    
    Vec3 pixel00_loc = vec3_add(leftcorner, vec3_scale(vec3_add(horizontal_delta, vertical_delta), 0.5));

    //standard ppm viewer
    printf("P3\n%d %d\n255\n",image_width,image_height);

    for(int i = 0; i < image_height; i++){
        for(int x = 0; x < image_width; x++){
            Vec3 pixel_center = vec3_add(vec3_add(pixel00_loc, vec3_scale(horizontal_delta, x)), vec3_scale(vertical_delta, i));
            Vec3 ray_direction = vec3_sub(pixel_center, centerpoint);
            Ray r = ray_create(centerpoint, ray_direction);

            Color pixel_color = ray_color(r);

            //this is printing each row of pixels for colors. expect a sweet gradien t
            write_color(stdout, pixel_color);
        }
    }

    //gcc main.c vec3.c ray.c -o raytracer -lm
    //./main > display.ppm

    return 0;
}