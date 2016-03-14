#ifndef __RAYTRACING_H
#define __RAYTRACING_H

#include "objects.h"
#include <stdint.h>

typedef struct thread_arg {
    uint8_t *pixels;
    double* background_color;
    rectangular_node rectangulars;
    sphere_node spheres;
    light_node lights;
    const viewpoint *view;
    int width;
    int height;
    double* u;
    double* v;
    double* w;
    int *factor;
    int height_start;
    int height_end;
} THR_ARG;

pthread_mutex_t mutex;
void raytracing(uint8_t *pixels, color background_color,
                rectangular_node rectangulars, sphere_node spheres,
                light_node lights, const viewpoint *view,
                int width, int height);


#endif
