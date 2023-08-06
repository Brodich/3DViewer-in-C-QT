#ifndef PARSER_H
#define PARSER_H

// commmon.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


void get_parse_data (data_t* parse_data, char const* pathtofile);
int get_vertices(FILE* fd, int count_of_vertexes, double** vertices);
void get_polygons(FILE* fd, int count_of_facets, polygon_t* polygons);
int get_count_vertex_polygon (char* pt_str);

void ft_print_vertices(double* vertices, int count_of_facets);
void ft_print_polygons(polygon_t polygons, int vertex_in_facet);

typedef enum Code_errors {
    SUCCESS = 1,
    VERTEX_MISS = -1,
	INCORRECT_MATRIX = -1,
	FAIL = -1
} Error_e;

#endif
