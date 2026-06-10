#include <stdio.h>
#include <math.h>
#include "vec3.h"

int main(){
    int image_height = 256;
    int image_width = 256;

    //standard ppm viewer
    printf("P3\n%d %d\n255\n",image_width,image_height);

    for(int i = 0; i < image_height; i++){
        for(int x = 0; x < image_width; x++){
            double r = (double)x / (image_width-1);
            double g = (double)i / (image_height-1);
            double b = 0.0;

            int ir = (int)(255.999*r);
            int ig = (int)(255.999*g);
            int ib = (int)(255.999*b);

            //this is printing each row of pixels for colors. expect a sweet gradien t
            printf("%d %d %d\n",ir,ig,ib);
        }
    }

    //gcc main.c -o main
    //./main > display.ppm

    return 0;
}