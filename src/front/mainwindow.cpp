#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  data_t parse_data = {0};
//  char const* pathtofile =
//      "../src/assets/square.obj";
  // char* pathtofile = "assets/test.obj";
   char const* pathtofile =
   "/Users/ngocgrag/Brodich/3DViewer-in-C-QT/src/assets/cube.obj";

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
  ft_print_polygons(polygons);

  //    glClearColor(1.0, 1.0, 1.0, 1.0);

//      if (polygons.vertices != NULL)
//      ui->modelWindow->paint();

  //    glwidget
  //    glwidget::paintGL();

//  if (vertices) {
//    free(vertices);
//  }
//  if (polygons.vertices) {
//    free(polygons.vertices);
//  }
}

MainWindow::~MainWindow() { delete ui; }
