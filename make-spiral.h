#ifndef MAKE_SPIRAL
#define MAKE_SPIRAL

#include <stdbool.h>

typedef struct SPIRAL_INFO {
	bool isright;
	bool isdown;
	int path_num;
	int turn;
}spiral_info;

typedef struct MAP_WIDTH_AND_HEIGHT {
	int width_start;
	int height_start;
	struct MAP_WIDTH_AND_HEIGHT *next;
} map_wh;

void make_spiral_array(struct MAP_WIDTH_AND_HEIGHT** thread_head, int width, int height, int spiral_size, int thread_num);

#endif
