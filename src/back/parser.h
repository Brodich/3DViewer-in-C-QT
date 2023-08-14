#ifndef PARSER_H
#define PARSER_H

// commmon.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define SIZE_BUFFER 512

typedef struct facets {
	int* vertices;
	int number_of_vertices;
} polygon_t;

typedef struct data {
	int amount_vertices;
	int amount_polygons;
	// matrix_t matrix_3d;
	// polygon_t* polygons;
} data_t;


void get_parse_data (data_t* parse_data, char const* pathtofile);
int get_vertices(FILE* fd, int amount_vertices, double** vertices);
void get_polygons(FILE* fd, int amount_polygons, polygon_t* polygons);
int get_count_vertex_polygon (char* pt_str);

void ft_print_vertices(double* vertices, int amount_polygons);
void ft_print_polygons(polygon_t polygons);

int get_max_vector(double* vertices, int amount_polygons);


void translateX(int amount_vertices, double** vertices, double value);
void translateY(int amount_vertices, double** vertices, double value);
void translateZ(int amount_vertices, double** vertices, double value);

typedef enum Code_errors {
    SUCCESS = 1,
    VERTEX_MISS = -1,
	INCORRECT_MATRIX = -1,
	FAIL = -1
} Error_e;

#endif
