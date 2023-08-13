#include "mainwindow.h"

// #include <iostream>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  QPalette palette;
  // Установка цвета фона
  QColor customColor(17, 26, 41);
  palette.setColor(QPalette::Window, customColor);
  // Применение настроек палитры
  setPalette(palette);
  setAutoFillBackground(true);

  // connect(ui->openFile, SIGNAL(clicked()), this,
  // SLOT(on_openFile_clicked()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_openFile_clicked() {
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

// void MainWindow::on_labelFileName_linkActivated(const QString& link) {
//   ui->labelFileName->setText("Название файла: " + link);
// }

void MainWindow::example() {}

void MainWindow::on_pushButton_2_clicked() {}

void MainWindow::on_pushButton_3_pressed() {}
