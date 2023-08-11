#include "parser.h"

int main() {
  // C++
  data_t parse_data = {0};
  char* pathtofile =
      "/Users/eusebiaa/Projects/3DViewer-in-C-QT/src/assets/square.obj";
  // char* pathtofile = "assets/test.obj";
  // char* pathtofile =
  // "/home/qni/Brodichgit/3DViewer-in-C-QT/src/assets/test.obj";

  get_parse_data(&parse_data, pathtofile);

  polygon_t polygons;       // free
  double* vertices = NULL;  // free

  FILE* fd;
  fd = fopen(pathtofile, "r");

  get_vertices(fd, parse_data.amount_vertices, &vertices);
  get_polygons(fd, parse_data.amount_polygons, &polygons);

  fclose(fd);

  printf("amount_vertices: %d\n", parse_data.amount_vertices);
  printf("amount_polygons: %d\n", parse_data.amount_polygons);

  ft_print_vertices(vertices, parse_data.amount_vertices);
  printf("numbers_of_vertices_in_facets: %d\n",
         polygons.numbers_of_vertices_in_facets);
  ft_print_polygons(polygons, polygons.numbers_of_vertices_in_facets);

  if (vertices) {
    free(vertices);
  }
  if (polygons.vertices) {
    free(polygons.vertices);
  }

  return (0);
}

void get_polygons(FILE* fd, int amount_polygons, polygon_t* polygons) {
  int vertex = 0;
  Error_e flag = SUCCESS;
  int first_vertex_polygon = 0;
  int i = 0;
  size_t length = 512;
  char* line = (char*)calloc(SIZE_BUFFER, sizeof(char));
  polygons->vertices = (int*)malloc(sizeof(int) * 1);
  char* pt_line = NULL;
  int vertex_in_facet = 0;
  int index_vertex = 1;

  polygons->numbers_of_vertices_in_facets = 0;
  while (i < amount_polygons) {
    getline(&line, &length, fd);
    pt_line = line;
    if (line[0] == 'f' && line[1] == ' ') {
      // printf("- ");
      // printf("pt %s\n", pt_line);
      vertex_in_facet = get_count_vertex_polygon(line);
      polygons->numbers_of_vertices_in_facets += vertex_in_facet;
      if (polygons->numbers_of_vertices_in_facets > 0)
        polygons->vertices = (int*)realloc(
            polygons->vertices,
            polygons->numbers_of_vertices_in_facets * sizeof(int));
      // printf("ptline |%s\n", pt_line);
      while (*pt_line != 0) {
        if (*pt_line >= '0' && *pt_line <= '9') {
          polygons->vertices[vertex] = strtol(pt_line, &pt_line, 10) - 1;

          if (flag == SUCCESS) {
            first_vertex_polygon = polygons->vertices[vertex];
            flag = FAIL;
          } else if (index_vertex < vertex_in_facet) {
            polygons->vertices[vertex + 1] = polygons->vertices[vertex];
            index_vertex++;
            vertex++;
          }
          index_vertex++;
          vertex++;
          // fix
          while (*pt_line != ' ' && *pt_line != '\0' && *pt_line != '\n') {
            pt_line++;
          }
          //
        }
        pt_line++;
      }
      polygons->vertices[vertex] = first_vertex_polygon;
      vertex++;
      // printf("indexver %d\n", index_vertex);
      index_vertex = 1;
      flag = SUCCESS;
      i++;
    }
  }
  free(line);
}

int get_vertices(FILE* fd, int amount_vertices, double** vertices) {
  Error_e code = SUCCESS;
  size_t length = 512;
  char* line = (char*)calloc(SIZE_BUFFER, sizeof(char));
  (*vertices) = (double*)malloc(sizeof(double) * 1);
  char* pt_line = NULL;
  int size = 1;
  int i = 0;
  int j = 0;
  while (i < amount_vertices) {
    getline(&line, &length, fd);
    pt_line = line;
    if (line[0] == 'v' && line[1] == ' ') {
      int xyz = 0;
      size += 3;
      (*vertices) = (double*)realloc((*vertices), size * sizeof(double));
      while (xyz != 3 && *pt_line != '\n') {
        if (*pt_line >= '0' && *pt_line <= '9') {
          (*vertices)[j] = strtod(pt_line, &pt_line);
          // matrix->matrix[row][xyz] = strtod(pt_line, &pt_line); // f 1/1/0
          // 3/2/1 4/4/2
          xyz++;
          j++;
        }
        pt_line++;
      }
      if (xyz != 3) {
        code = FAIL;
        // printf("Error");
      }
      i++;
    }
  }
  free(line);
  return (code);
}

// f 1 2 4 -> 12 24 41 = 6 symbols
int get_count_vertex_polygon(char* pt_str) {
  // printf("str2 |%s\n", pt_str);
  int count = 0;
  while (*pt_str != 0 && *pt_str != '\n' && *pt_str != -1) {
    // printf("pt str %c\n", *pt_str);
    if (*pt_str >= '0' && *pt_str <= '9') {
      // printf("check");
      count++;
      while (*pt_str != ' ' && *pt_str != '\0') {
        pt_str++;
      }
      pt_str--;
    }
    pt_str++;
  }
  if (count > 2) {
    count *= 2;
  }
  return (count);
}

void get_parse_data(data_t* parse_data, const char* pathtofile) {
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
      parse_data->amount_vertices++;
    } else if (line[0] == 'f' && line[1] == ' ') {
      parse_data->amount_polygons++;
    }
  }
  free(line);
  fclose(fd);
}

void ft_print_vertices(double* vertices, int amount_polygons) {
  int i = 0;
  int j = 0;
  int z = 0;
  while (i < amount_polygons) {
    printf("(%d)", i);
    while (j < 3) {
      printf(" %.16f ", vertices[z]);
      z++;
      j++;
    }
    printf("\n");
    j = 0;
    i++;
  }
}

/// @brief output in terminal all polygons, index start from 1, index 0 = trash
/// @param polygons
/// @param amount_vertices_to_connect count
void ft_print_polygons(polygon_t polygons, int amount_vertices_to_connect) {
  int i = 0;
  int j = 0;
  // polygons.numbers_of_vertices_in_facets
  while (i < polygons.numbers_of_vertices_in_facets) {
    if (j == amount_vertices_to_connect) {
      printf("\n");
      j = 0;
    }
    printf("%d ", polygons.vertices[i]);

    j++;
    i++;
  }
}
