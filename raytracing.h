#ifndef __RAYTRACING_H
#define __RAYTRACING_H

#include "objects.h"
#include "make-spiral.h"
#include <stdint.h>

typedef struct thread_arg_the_same {
    uint8_t *pixels;
    double* background_color;
    rectangular_node rectangulars;
    sphere_node spheres;
    light_node lights;
    const viewpoint *view;
	double* u;
    double* v;
    double* w;
	int *factor;
    int width;
	int height;
} THR_ARG_THE_SAME;

typedef struct thread_arg {

	THR_ARG_THE_SAME *same;
	//map_wh * mp;
	//int addNum;
    int height_start;
    int height_end;
} THR_ARG;

void raytracing(uint8_t *pixels, color background_color,
                rectangular_node rectangulars, sphere_node spheres,
                light_node lights, const viewpoint *view,
                int width, int height);


#endif
