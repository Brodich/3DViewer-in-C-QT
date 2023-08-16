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


    connect(ui->translate_slider_x, SIGNAL(valueChanged(int)), ui->translate_x, SLOT(setValue(int)));
    connect(ui->translate_x, SIGNAL(valueChanged(int)), ui->translate_slider_x, SLOT(setValue(int)));

    connect(ui->translate_slider_y, SIGNAL(valueChanged(int)), ui->translate_y, SLOT(setValue(int)));
    connect(ui->translate_y, SIGNAL(valueChanged(int)), ui->translate_slider_y, SLOT(setValue(int)));

    connect(ui->translate_slider_z, SIGNAL(valueChanged(int)), ui->translate_z, SLOT(setValue(int)));
    connect(ui->translate_z, SIGNAL(valueChanged(int)), ui->translate_slider_z, SLOT(setValue(int)));


    // Rotate

    connect(ui->rotate_slider_x, SIGNAL(valueChanged(int)), ui->rotate_x, SLOT(setValue(int)));
    connect(ui->rotate_x, SIGNAL(valueChanged(int)), ui->rotate_slider_x, SLOT(setValue(int)));

    connect(ui->rotate_slider_y, SIGNAL(valueChanged(int)), ui->rotate_y, SLOT(setValue(int)));
    connect(ui->rotate_y, SIGNAL(valueChanged(int)), ui->rotate_slider_y, SLOT(setValue(int)));

    connect(ui->rotate_slider_z, SIGNAL(valueChanged(int)), ui->rotate_z, SLOT(setValue(int)));
    connect(ui->rotate_z, SIGNAL(valueChanged(int)), ui->rotate_slider_z, SLOT(setValue(int)));


    // Scale

    connect(ui->scale_slider, SIGNAL(valueChanged(int)), ui->scale, SLOT(setValue(int)));
    connect(ui->scale, SIGNAL(valueChanged(int)), ui->scale_slider, SLOT(setValue(int)));



//  printf("amount_vertices: %d\n", parse_data.amount_vertices);
//  printf("amount_polygons: %d\n", parse_data.amount_polygons);

//


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
          free(ui->modelWindow->vertices);
          free(ui->modelWindow->polygons.vertices);

          get_parse_data(&ui->modelWindow->parse_data, pathtofile);
          get_vertices(fd, ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices);
          get_polygons(fd, ui->modelWindow->parse_data.amount_polygons, &ui->modelWindow->polygons);

          fclose(fd);

          ui->modelWindow->size = get_max_vector(ui->modelWindow->vertices, ui->modelWindow->parse_data.amount_vertices) * 3.;

          ui->rotate_x->setValue(0);
          ui->rotate_y->setValue(0);
          ui->rotate_z->setValue(0);
          ui->translate_x->setValue(0);
          ui->translate_y->setValue(0);
          ui->translate_z->setValue(0);
          ui->scale->setValue(0);


  }
}


void MainWindow::on_translate_x_valueChanged(int arg1)
{
//    static int origin_x = ui->translate_x->value();
    translateX(ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices, -ui->modelWindow->xTrans);
    translateX(ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices, ui->translate_x->value());
    ui->modelWindow->xTrans = ui->translate_x->value();
}


void MainWindow::on_translate_y_valueChanged(int arg1)
{
    translateY(ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices, -ui->modelWindow->yTrans);
    translateY(ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices, ui->translate_y->value());
    ui->modelWindow->yTrans = ui->translate_y->value();
}


void MainWindow::on_translate_z_valueChanged(int arg1)
{
    translateZ(ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices, -ui->modelWindow->zTrans);
    translateZ(ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices, ui->translate_z->value());
    ui->modelWindow->zTrans = ui->translate_z->value();
}

// rotate
void MainWindow::on_rotate_x_valueChanged(int arg1)
{
    rotateX(ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices, -ui->modelWindow->xRot);
    rotateX(ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices, ui->rotate_x->value());
    ui->modelWindow->xRot = ui->rotate_x->value();
}

void MainWindow::on_rotate_y_valueChanged(int arg1)
{
    rotateY(ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices, -ui->modelWindow->yRot);
    rotateY(ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices, ui->rotate_y->value());
    ui->modelWindow->yRot = ui->rotate_y->value();
}



void MainWindow::on_rotate_z_valueChanged(int arg1)
{
    rotateZ(ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices, -ui->modelWindow->zRot);
    rotateZ(ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices, ui->rotate_z->value());
    ui->modelWindow->zRot = ui->rotate_z->value();
}


void MainWindow::on_scale_valueChanged(int arg1)
{
    divide_shape(ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices, ui->modelWindow->scale);
    scale_shape(ui->modelWindow->parse_data.amount_vertices, &ui->modelWindow->vertices, ui->scale->value());
    ui->modelWindow->scale = ui->scale->value();
}



