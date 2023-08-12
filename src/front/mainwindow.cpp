#include "mainwindow.h"

// #include <iostream>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->buttonOpenFile, SIGNAL(clicked()), this, SLOT(push_openFile()));

}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::push_openFile() {
  // Открытие диалогового окна выбора файла
  QString filePath = QFileDialog::getOpenFileName(
      this, "Open File", QDir::homePath(), "All Files (*.*)");

  if (!filePath.isEmpty()) {
    // qDebug() << filePath;
    // Преобразование QString в std::string
    std::string stdstrPath = filePath.toStdString();
    path = stdstrPath.c_str();

    data_t parse_data = {0};
    get_parse_data(&parse_data, path);

    polygon_t polygons;       // free
    double* vertices = NULL;  // free

    FILE* fd;
    fd = fopen(path, "r");
    get_vertices(fd, parse_data.amount_vertices, &vertices);
    get_polygons(fd, parse_data.amount_polygons, &polygons);
    fclose(fd);

    printf("amount_vertices: %d\n", parse_data.amount_vertices);
    printf("amount_polygons: %d\n", parse_data.amount_polygons);

    if (vertices) {
      free(vertices);
    }
    if (polygons.vertices) {
      free(polygons.vertices);
    }
    //     std::cout << "C-style string: " << path << std::endl;
    // ui->modelWindow->qt_metacast(str);
  }
}

void MainWindow::example() { std::fprintf(stderr, "dva\n"); }

void MainWindow::on_pushButton_2_clicked() {}

void MainWindow::on_pushButton_3_pressed() {}
