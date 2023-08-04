#ifndef PARSER_H
#define PARSER_H

// commmon.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>


#define SIZE_BUFFER 512

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

void init_matrix(matrix_t *matrix);
int st_create_matrix(int rows, int columns, matrix_t *result);
void get_parse_data (data_t* parse_data, char const* pathtofile);
// void     get_matrix_and_polygon(matrix_t* matrix, polygon_t* polygon, char* pathtofile);
int get_vertices(FILE* fd, int count_of_vertexes, double** vertices);
void get_polygon(FILE* fd, int count_of_facets, polygon_t** polygons);
int get_count_vertex_polygon (char* pt_str);
// void get_matrix(FILE* fd, int count_of_vertexes, matrix_t* matrix);

// void ft_print_matrix(matrix_t mat);
void ft_print_vertices(double* vertices, int count_of_facets);


int read_vertex(matrix_t* coordinates_dots, char* str_arr, int* i);
int read_facets(polygon_t* polygons, char* str_arr, int* i);
// int fill_str_from_file(char* str_arr, SDL_RWops* io);
void ft_print_polygons(polygon_t* polygons, int count_of_facets);

typedef enum Code_errors {
    SUCCESS = 1,
    VERTEX_MISS = -1,
	INCORRECT_MATRIX = -1,
	FAIL = -1
} Error_e;

#endif
