#include "parser.h"

void translateX(int amount_vertices, double** vertices, double value) {
	int i = 0;
	int j = 0;
	while (i < amount_vertices) {
		(*vertices)[j] += value;
		j += 3;
		i++;
	}
}

void translateY(int amount_vertices, double** vertices, double value) {
	int i = 0;
	int j = 1;
	while (i < amount_vertices) {
		(*vertices)[j] += value;
		j += 3;
		i++;
	}
}

void translateZ(int amount_vertices, double** vertices, double value) {
	int i = 0;
	int j = 2;
	while (i < amount_vertices) {
		(*vertices)[j] += value;
		j += 3;
		i++;
	}
}

void rotateX(int amount_vertices, double** vertices, double angle) {
	int i = 0;
	int xyz = 0;
    double rot = angle * M_PI / 180;
	while (i < amount_vertices) {
		while (xyz < 3) {
			if (xyz == 1) { // y 
                (*vertices)[(i * 3) + xyz] = (*vertices)[(i * 3) + 1] * cos(rot) - (*vertices)[(i * 3) + 2] * sin(rot);
			} else if (xyz == 2) { // z
                (*vertices)[(i * 3) + xyz] = -(*vertices)[(i * 3) + 1] * sin(rot) + (*vertices)[(i * 3) + 2] * cos(rot);
			}
			xyz++;
		}
		xyz = 0;
		i++;
	}
}

void scale_shape(int amount_vertices, double** vertices, int scale) {
	double scaled = (double)scale / 10.0;
	int i = 0;

	while (i < amount_vertices * 3) {
		(*vertices)[i] = (*vertices)[i] * scaled;
		i++;
	}
	
}
