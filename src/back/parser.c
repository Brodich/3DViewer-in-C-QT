#include "viewer.h"


int main() {

    data_t parse_data = {0};
    char* pathtofile = "/Users/ngocgrag/Brodich/3DViewer-in-C-QT/src/assets/test.obj";

    get_parse_data(&parse_data, pathtofile);

    matrix_t matrix; // free
    polygon_t* polygons; // free
    st_create_matrix(parse_data.count_of_vertexes, 3, &matrix);
    polygons = (polygon_t*) calloc(parse_data.count_of_facets, sizeof(polygon_t));

    FILE* fd;
    fd = fopen(pathtofile, "r");
    get_matrix(fd, parse_data.count_of_vertexes, &matrix);
    get_polygon(fd, parse_data.count_of_facets, &polygons);

    printf("z %d\n", parse_data.count_of_vertexes);
    printf("z %d\n", parse_data.count_of_facets);

    ft_print_matrix(matrix);
    ft_print_polygons(polygons, parse_data.count_of_facets);
    return (0);
}

void get_polygon(FILE* fd, int count_of_facets, polygon_t** polygons) {
    int vertex = 0;
    Error_e flag = SUCCESS;
    int first_vertex_polygon = 0;
    int i = 0;
    size_t length = 512;
    char* line = (char*)calloc(SIZE_BUFFER, sizeof(char));
    char* pt_line = NULL;
    while (i < count_of_facets) {
      getline(&line, &length, fd);
      pt_line = line;
      if (line[0] == 'f' && line[1] == ' ') {
        (*polygons)[i].numbers_of_vertexes_in_facets = get_count_vertex_polygon(line);
        (*polygons)[i].vertexes = (int*)calloc((*polygons)[i].numbers_of_vertexes_in_facets, sizeof(int));
        while (*pt_line != 0) {
          // printf("ptline |%s|\n", pt_line);
          if (*pt_line >= '0' && *pt_line <= '9') {
            (*polygons)[i].vertexes[vertex] = strtol(pt_line, &pt_line, 10);
            if (flag == SUCCESS) {
              first_vertex_polygon = (*polygons)[i].vertexes[vertex];
              flag = FAIL;
            }
            else if (vertex < (*polygons)[i].numbers_of_vertexes_in_facets){
              (*polygons)[i].vertexes[vertex + 1] = (*polygons)[i].vertexes[vertex];
              vertex++;
            }
            vertex++;
          }
          (*polygons)[i].vertexes[vertex] = first_vertex_polygon;
          pt_line++;
        }
        vertex = 0;
        flag = SUCCESS;
        i++;
      }
    }
    free(line);
}

void get_matrix(FILE* fd, int count_of_vertexes, matrix_t* matrix) {
  int i = 0;
  size_t length = 512;
  char* line = (char*)calloc(SIZE_BUFFER, sizeof(char));
  char* pt_line = NULL;
  int row = 0;
  int xyz = 0;
  while (i < count_of_vertexes) {
    getline(&line, &length, fd);
    pt_line = line;
    if (line[0] == 'v' && line[1] == ' ') {
      while (xyz != 3 && *pt_line != '\n') {
        if (*pt_line >= '0' && *pt_line <= '9') {
            matrix->matrix[row][xyz] = strtod(pt_line, &pt_line);
            xyz++;
        }
        pt_line++;
      }
      xyz = 0;
      row++;
      i++;
    }
  }
  free(line);
}

// f 1 2 4 -> 12 24 41 = 6 symbols
int get_count_vertex_polygon (char* pt_str) {
    // printf("str2 |%s\n", pt_str);
    int count = 0;
    while (*pt_str != 0 && *pt_str != '\n' && *pt_str != -1) {
        // printf("pt str %c\n", *pt_str);
        if(*pt_str >= '0' && *pt_str <= '9'){
            // printf("check");
            count++;
            while((*pt_str >= '0' && *pt_str <= '9') || (*pt_str == '.')) {
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
    fclose(fd);
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

void ft_print_matrix(matrix_t mat) {
  int i = 0;
  int j = 0;
  while (i < mat.rows) {
    printf("(%d)", i);
    while (j < mat.columns) {
      printf(" %.16f ", mat.matrix[i][j]);
      j++;
    }
    printf("\n");
    j = 0;
    i++;
  }
}

/// @brief output in terminal all polygons, index start from 1, index 0 = trash
/// @param polygons 
/// @param count_of_facets count 
void ft_print_polygons(polygon_t* polygons, int count_of_facets) {
    int i = 0;
    int j = 0;
    int count_of_facets_in_one_polygon = 0;
    while (i < count_of_facets) {
        count_of_facets_in_one_polygon = polygons[i].numbers_of_vertexes_in_facets;
        j = 0;
        printf("(f%d) ", i);
        while (j < count_of_facets_in_one_polygon) {
            printf("%d ", polygons[i].vertexes[j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
