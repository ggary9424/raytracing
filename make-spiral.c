#include <stdlib.h>
#include <stdbool.h>

#include "make-spiral.h"

void make_spiral_array(map_wh ** thread_head, int width, int height, int spiral_size, int thread_num){
	spiral_info *spiral = malloc(sizeof(spiral_info));
	spiral->isright = 1;
	spiral->isdown = 1;
	spiral->path_num = 1;
	spiral->turn = 0;

/*
	for(int i=0; i<spiral_size; i++){
		for(int j=0; j<spiral_size; j++){
			array[i][j] = 0;
		}
	}
*/
	int x, y;
	if((spiral_size % 2) == 1){
		x = spiral_size/2;	
		y = x;
	}
	else{
		x = spiral_size / 2 - 1;	
		y = x;
	}
	

//	array[x][y] = 0;
	int count = 1;
	map_wh *thread_array[thread_num];

	for(int i=0; i<thread_num; i++){
		thread_array[i] = malloc(sizeof(map_wh));
		thread_head[i] = thread_array[i];
		thread_head[i]->width_start = -1;
	}

	thread_array[0]->width_start = (x*width)/spiral_size;
	thread_array[0]->height_start = (x*height)/spiral_size;

	while(x > -1 && y > -1 && x < spiral_size && y < spiral_size){
		int n = spiral->path_num;
		if(spiral->turn == 0){			
			if(spiral->isright){
				while(n > 0){
					++x;
					int thread_id = count % thread_num;
					if((thread_head[thread_id])->width_start != -1){
						thread_array[thread_id]->next = malloc(sizeof(map_wh));
						thread_array[thread_id] = thread_array[thread_id]->next;
					}
					thread_array[thread_id]->width_start = (x*width)/spiral_size;
					thread_array[thread_id]->height_start = (y*height)/spiral_size;
					count++;
					n--;
				}
			}
			else{
				while(n > 0){
					--x;
					if(x < 0){
						break;
					}
					int thread_id = count % thread_num;
					if((thread_head[thread_id])->width_start != -1){
						thread_array[thread_id]->next = malloc(sizeof(map_wh));
						thread_array[thread_id] = thread_array[thread_id]->next;
					}
					thread_array[thread_id]->width_start = (x*width)/spiral_size;
					thread_array[thread_id]->height_start = (y*height)/spiral_size;
					count++;
					n--;
				}
			}
			spiral->isright = !(spiral->isright);
			spiral->turn = 1;
		}
		else if(spiral->turn == 1){
			if(spiral->isdown){
				while(n > 0){
					++y;
					int thread_id = count % thread_num;
					if((thread_head[thread_id])->width_start != -1){
						thread_array[thread_id]->next = malloc(sizeof(map_wh));
						thread_array[thread_id] = thread_array[thread_id]->next;
					}
					thread_array[thread_id]->width_start = (x*width)/spiral_size;
					thread_array[thread_id]->height_start = (y*height)/spiral_size;
					count++;
					n--;
				}
			}
			else{
				while(n > 0){
					--y;
					if(y < 0){
						break;
					}
					int thread_id = count % thread_num;
					if((thread_head[thread_id])->width_start != -1){
						thread_array[thread_id]->next = malloc(sizeof(map_wh));
						thread_array[thread_id] = thread_array[thread_id]->next;
					}
					thread_array[thread_id]->width_start = (x*width)/spiral_size;
					thread_array[thread_id]->height_start = (y*height)/spiral_size;
					count++;
					n--;
				}
			}
			spiral->isdown = !(spiral->isdown);
			spiral->turn = 0;
			spiral->path_num++;
		}
	}
}
