#include <stdio.h>
#include <math.h>
#include "vec3.h"
#include "color.h"
#include "ray.h"

Color ray_color(Ray r){return (Color){0,0,0};}

int main(){

    double aspect_ratio = 16.0/9.0;
    int image_width = 256;

    int image_height = (int)(image_width / aspect_ratio);
    if(image_height < 1){image_height = 1;}

    //camera values
    double focal_length = 0.0;
    double viewport_height = 0.0;
    double viewport_width = viewport_height*((double)(image_width/image_height));
    Vec3 centerpoint = {0,0,0};

    Vec3 viewport_horizontal = {viewport_width,0,0};
    Vec3 viewport_vertical = {0,viewport_height*-1.0,0};

    //standard ppm viewer
    printf("P3\n%d %d\n255\n",image_width,image_height);

    for(int i = 0; i < image_height; i++){
        for(int x = 0; x < image_width; x++){
            double r = (double)x / (image_width-1);
            double g = (double)i / (image_height-1);
            double b = 0.0;

            Color pixel_color = {r,g,b};

            int ir = (int)(255.999*pixel_color.x);
            int ig = (int)(255.999*pixel_color.y);
            int ib = (int)(255.999*pixel_color.z);

            //this is printing each row of pixels for colors. expect a sweet gradien t
            printf("%d %d %d\n",ir,ig,ib);
        }
    }

    //gcc main.c -o main
    //./main > display.ppm

    return 0;
}