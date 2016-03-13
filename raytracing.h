#ifndef __RAYTRACING_H
#define __RAYTRACING_H

#include "objects.h"
#include <stdint.h>

typedef struct thread_arg {
	uint8_t *pixels;
	float* background_color;
    rectangular_node rectangulars;
 	sphere_node spheres;
    light_node lights;
	const viewpoint *view;
    int width;
	int height;
	float* u;
	float* v;
	float* w; 
	float* d;
	int *factor;
	int height_start;
	int height_end;
	int *thread_left;
} THR_ARG;

pthread_mutex_t mutex;
void raytracing(uint8_t *pixels, color background_color,
                rectangular_node rectangulars, sphere_node spheres,
                light_node lights, const viewpoint *view,
                int width, int height);

int parallelCompute(int threadnum, uint8_t *pixels, float* background_color,
                rectangular_node rectangulars, sphere_node spheres,
                light_node lights, const viewpoint *view,
                int width, int height, float* u, float* v, float* w, float* d, int *factor);
#endif
