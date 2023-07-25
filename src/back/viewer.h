#ifndef VIEWER_H
#define VIEWER_H

// commmon.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

typedef struct facets {
	int* vertexes;
	int numbers_of_vertexes_in_facets;
} polygon_t;

typedef struct data {
	int count_of_vertexes;
	int count_of_facets;
	// matrix_t matrix_3d;
	// polygon_t* polygons;
} data_t;

typedef struct matrix_struct {
  float **matrix;
  int rows;
  int columns;
} matrix_t;



int read_vertex(matrix_t* coordinates_dots, char* str_arr, int* i);
int read_facets(polygon_t* polygons, char* str_arr, int* i);
// int fill_str_from_file(char* str_arr, SDL_RWops* io);
void ft_print_polygons(polygon_t* polygons, int count_of_facets);

typedef enum Code_errors {
    SUCCESS = 1,
    VERTEX_MISS = -1
} Error_e;

#endif