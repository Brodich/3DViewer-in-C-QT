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
