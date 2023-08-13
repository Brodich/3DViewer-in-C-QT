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
   "/Users/ngocgrag/Brodich/3DViewer-in-C-QT/src/assets/cube2.obj";



  polygon_t polygons;       // free
  double* vertices = NULL;  // free



  printf("amount_vertices: %d\n", parse_data.amount_vertices);
  printf("amount_polygons: %d\n", parse_data.amount_polygons);

//  ft_print_vertices(vertices, parse_data.amount_vertices);
//  ft_print_polygons(polygons);

  //    glClearColor(1.0, 1.0, 1.0, 1.0);


//      if ((polygons.vertices) != NULL)
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

void MainWindow::on_open_file_clicked()
{

//    QString filePath = QFileDialog::getOpenFileName(
//        this, "Open File", QDir::homePath(), "All Files (*.*)");

//    std::string stdstrPath = filePath.toStdString();
//    const char* pathtofile = stdstrPath.c_str();

    char const* pathtofile =
    "/Users/ngocgrag/Brodich/3DViewer-in-C-QT/src/assets/cube2.obj";

    FILE* fd;
    fd = fopen(pathtofile, "r");
      if (fd != NULL) {
          get_parse_data(&ui->modelWindow->parse_data, pathtofile);
          get_vertices(fd, ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices);
          get_polygons(fd, ui->modelWindow->parse_data.amount_polygons, &ui->modelWindow->polygons);
          fclose(fd);
  }
}

