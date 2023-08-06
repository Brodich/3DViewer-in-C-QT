#include "parser.h"


//int main() {

//// C++
//  data_t parse_data = {0};
//  char* pathtofile = "/Users/ngocgrag/Brodich/3DViewer-in-C-QT/src/assets/test.obj";
//  // char* pathtofile = "assets/test.obj";
//  // char* pathtofile = "/home/qni/Brodichgit/3DViewer-in-C-QT/src/assets/test.obj";

//  get_parse_data(&parse_data, pathtofile);

//  polygon_t polygons; // free
//  double* vertices = NULL; // free

//  FILE* fd;
//  fd = fopen(pathtofile, "r");

//  get_vertices(fd, parse_data.count_of_vertexes, &vertices);
//  get_polygons(fd, parse_data.count_of_facets, &polygons);
    
//  fclose(fd);

//  printf("z %d\n", parse_data.count_of_vertexes);
//  printf("z %d\n", parse_data.count_of_facets);

//  ft_print_vertices(vertices, parse_data.count_of_vertexes);
//  ft_print_polygons(polygons, 6);

//  if (vertices)
//    free(vertices);
//  if (polygons.vertexes)
//    free(polygons.vertexes);

//  return (0);
//}

void get_polygons(FILE* fd, int count_of_facets, polygon_t* polygons) {
    int vertex = 0;
    Error_e flag = SUCCESS;
    int first_vertex_polygon = 0;
    int i = 0;
    size_t length = 512;
    char* line = (char*)calloc(SIZE_BUFFER, sizeof(char));
    polygons->vertexes = (int*)malloc(sizeof(int) * 1);
    char* pt_line = NULL;
    int vertex_in_facet = 0;
    int index_vertex = 1;

    polygons->numbers_of_vertexes_in_facets = 0;
    while (i < count_of_facets) {
      getline(&line, &length, fd);
      pt_line = line;
      if (line[0] == 'f' && line[1] == ' ') {
                    // printf("pt %s\n", pt_line);
        vertex_in_facet = get_count_vertex_polygon(line);
        polygons->numbers_of_vertexes_in_facets = polygons->numbers_of_vertexes_in_facets + vertex_in_facet;
          if (polygons->numbers_of_vertexes_in_facets > 0)
        polygons->vertexes = (int*)realloc(polygons->vertexes, polygons->numbers_of_vertexes_in_facets * sizeof(int));
                  // printf("ptline |%s\n", pt_line);
        while (*pt_line != 0) {
          if (*pt_line >= '0' && *pt_line <= '9') {
            polygons->vertexes[vertex] = strtol(pt_line, &pt_line, 10);
            if (flag == SUCCESS) {
              first_vertex_polygon = polygons->vertexes[vertex];
              flag = FAIL;
            }
            else if (index_vertex < vertex_in_facet){
              polygons->vertexes[vertex + 1] = polygons->vertexes[vertex];
              index_vertex++;
              vertex++;
            }
            index_vertex++;
            vertex++;
            // problem
            while(*pt_line != ' ' && *pt_line != '\0' && *pt_line != '\n') {
              printf("pt %c\n", *pt_line);
              pt_line++;
            }
            //
          }
          pt_line++;
        }
        polygons->vertexes[vertex] = first_vertex_polygon;
        vertex++;
          // printf("indexver %d\n", index_vertex);
        index_vertex = 1;
        flag = SUCCESS;
        i++;
      }
    }
    free(line);
}

int get_vertices(FILE* fd, int count_of_vertexes, double** vertices) {
  int i = 0;
  Error_e code = SUCCESS;
  size_t length = 512;
  char* line = (char*)calloc(SIZE_BUFFER, sizeof(char));
  (*vertices) = (double*)malloc(sizeof(double) * 1);
  int size = 1;
  char* pt_line = NULL;
  int j = 0;
  int xyz = 0;
  while (i < count_of_vertexes) {
    getline(&line, &length, fd);
    pt_line = line;
    if (line[0] == 'v' && line[1] == ' ') {
      size += 3;
      (*vertices) = (double*)realloc((*vertices), size * sizeof(double));
      while (xyz != 3 && *pt_line != '\n') {
        if (*pt_line >= '0' && *pt_line <= '9') {
            (*vertices)[j] = strtod(pt_line, &pt_line);
            // matrix->matrix[row][xyz] = strtod(pt_line, &pt_line); // f 1/1/0 3/2/1 4/4/2
            xyz++;
            j++;
        }
        pt_line++;
      }
      if (xyz != 3) {
        code = FAIL;
        // printf("Error");
      }
      xyz = 0;
      i++;
    }
  }
  free(line);
  return (code);
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

void get_parse_data (data_t* parse_data, const char *pathtofile) {
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

void ft_print_vertices(double* vertices, int count_of_facets) {
  int i = 0;
  int j = 0;
  int z = 0;
  while (i < count_of_facets) {
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
/// @param count_of_facets count 
void ft_print_polygons(polygon_t polygons, int vertex_in_facet) {
  int i = 0;
  int j = 0;
  while (i < polygons.numbers_of_vertexes_in_facets) {
       if (j == vertex_in_facet) {
        printf("\n");
        j = 0;
    } 
    printf("%d ", polygons.vertexes[i]);

    j++;
    i++;
  }
}
