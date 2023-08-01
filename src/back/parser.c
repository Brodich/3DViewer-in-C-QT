#include "viewer.h"


int main() {

    data_t parse_data = {0};
    // FILE* fd;
    char* pathtofile = "assets/cube.obj";

    get_parse_data(&parse_data, pathtofile);

    matrix_t matrix; // free
    polygon_t* polygons; // free

    st_create_matrix(parse_data.count_of_vertexes + 1, 3, &matrix);
    polygons = (polygon_t*) calloc(parse_data.count_of_facets, sizeof(polygon_t));

    get_matrix_and_polygon(&matrix, &polygons, pathtofile);


    printf("z %d\n", parse_data.count_of_vertexes);
    printf("z %d\n", parse_data.count_of_facets);

    return (0);
}

void     get_matrix_and_polygon(matrix_t* matrix, polygon_t* polygon, char* pathtofile) {
    FILE* fd;
    fd = fopen(pathtofile, "r");
    size_t length = 512;
    char* line = (char*)calloc(SIZE_BUFFER, sizeof(char));
    char* pt_line = NULL;
    int index_ver = 0;
    int i = 0;
    int row = 1;
    int index_polygon = 1;
    int vertex = 0;
    int count_vertex_polygon = 0;
    Error_e flag = SUCCESS;
    int first_vertex_polygon = 0;

    // while (index_ver < )
    while (getline(&line, &length, fd) != -1) {
        pt_line = line;
        if (line[0] == 'v' && line[1] == ' ') {
            while (i != 3 && *pt_line != '\n') {
                if (*pt_line >= '0' && *pt_line <= '9') {
                    matrix->matrix[row][i] = strtod(pt_line, &pt_line);
                    i++;
                }
                pt_line++;
            }
            row++;
        }
        else if (line[0] == 'f' && line[1] == ' ') {
            polygon[index_polygon].numbers_of_vertexes_in_facets = get_count_vertex_polygon(pt_line);
            polygon[index_polygon].vertexes = (int*)calloc(polygon[index_polygon].numbers_of_vertexes_in_facets, sizeof(int));
            while (*pt_line != '\n') {
                if (*pt_line >= '0' && *pt_line <= '9') {
                    polygon[index_polygon].vertexes[vertex] = strtol(pt_line, &pt_line, 10);
                    if (flag == SUCCESS) {
                        first_vertex_polygon = polygon[index_polygon].vertexes[vertex];
                        flag = FAIL;
                    } else {
                        polygon[index_polygon].vertexes[vertex + 1] = polygon[index_polygon].vertexes[vertex];
                        vertex++;
                    }
                    vertex++;
                }
                pt_line++;
            }
            flag = SUCCESS;
            index_polygon++;
        }
    }
    free(line);
}

// f 1 2 4 -> 12 24 41 = 6 symbols
int get_count_vertex_polygon (char* pt_str) {
    int count = 0;
    while (*pt_str != 0) {
        if(*pt_str >= '0' && *pt_str <= '9'){
            count++;
            while(*pt_str >= '0' && *pt_str <= '9' || *pt_str == '.') {
                pt_str++;
            }
        }
        pt_str++;
    }
    if (count > 2) {
        count *= 2;
    }
    return (count);
}
void get_parse_data (data_t* parse_data, char* pathtofile) {
    FILE* fd;
    fd = fopen(pathtofile, "r");
    if (fd == NULL) {
        printf("Error not have been file \n");
        exit(1);
    }
    size_t length = 512;
    char* line = (char*)calloc(SIZE_BUFFER, sizeof(char));
    while (getline(&line, &length, fd) != -1) {
        if (line[0] == 'v' && line[1] == ' ') {
            parse_data->count_of_vertexes++;
        }
        else if (line[0] == 'f' && line[1] == ' ') {
            parse_data->count_of_facets++;
        }
    }
    free(line);
}



int st_create_matrix(int rows, int columns, matrix_t *result) {
  Error_e code = SUCCESS;
  result->columns = columns;
  result->rows = rows;
  if (rows <= 0 || columns <= 0) {
    code = INCORRECT_MATRIX;
    result->matrix = NULL;
  } else {
    result->matrix = (float **)malloc(rows * sizeof(float *));
    int i = 0;
    while (i < rows) {
      result->matrix[i] = (float *)malloc(columns * sizeof(float));
      i++;
    }
    init_matrix(result);
  }
  return (code);
}

void init_matrix(matrix_t *matrix) {
  int i = 0;
  int j = 0;
  while (i < (matrix)->rows) {
    while (j < (matrix)->columns) {
      (matrix)->matrix[i][j] = 0;
      j++;
    }
    j = 0;
    i++;
  }
}
