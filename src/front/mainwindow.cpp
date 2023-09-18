#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  data_t parse_data = {0};
  QSettings settings("Team21", "3DViewer1.0");
  //  char const* pathtofile =
  //      "../src/assets/square.obj";
  // char* pathtofile = "assets/test.obj";
  char const* pathtofile =
      "/Users/ngocgrag/Brodich/3DViewer-in-C-QT/src/assets/cube2.obj";

  connect(ui->translate_slider_x, SIGNAL(valueChanged(int)), ui->translate_x,
          SLOT(setValue(int)));
  connect(ui->translate_x, SIGNAL(valueChanged(int)), ui->translate_slider_x,
          SLOT(setValue(int)));

  connect(ui->translate_slider_y, SIGNAL(valueChanged(int)), ui->translate_y,
          SLOT(setValue(int)));
  connect(ui->translate_y, SIGNAL(valueChanged(int)), ui->translate_slider_y,
          SLOT(setValue(int)));

  connect(ui->translate_slider_z, SIGNAL(valueChanged(int)), ui->translate_z,
          SLOT(setValue(int)));
  connect(ui->translate_z, SIGNAL(valueChanged(int)), ui->translate_slider_z,
          SLOT(setValue(int)));

  // Rotate

  connect(ui->rotate_slider_x, SIGNAL(valueChanged(int)), ui->rotate_x,
          SLOT(setValue(int)));
  connect(ui->rotate_x, SIGNAL(valueChanged(int)), ui->rotate_slider_x,
          SLOT(setValue(int)));

  connect(ui->rotate_slider_y, SIGNAL(valueChanged(int)), ui->rotate_y,
          SLOT(setValue(int)));
  connect(ui->rotate_y, SIGNAL(valueChanged(int)), ui->rotate_slider_y,
          SLOT(setValue(int)));

  connect(ui->rotate_slider_z, SIGNAL(valueChanged(int)), ui->rotate_z,
          SLOT(setValue(int)));
  connect(ui->rotate_z, SIGNAL(valueChanged(int)), ui->rotate_slider_z,
          SLOT(setValue(int)));

  // Scale

  connect(ui->scale_slider, SIGNAL(valueChanged(int)), ui->scale,
          SLOT(setValue(int)));
  connect(ui->scale, SIGNAL(valueChanged(int)), ui->scale_slider,
          SLOT(setValue(int)));

  // line width

  connect(ui->line_width_slider, SIGNAL(valueChanged(int)), ui->line_width,
          SLOT(setValue(int)));
  connect(ui->line_width, SIGNAL(valueChanged(int)), ui->line_width_slider,
          SLOT(setValue(int)));

  // vertex size

  connect(ui->vertex_size_slider, SIGNAL(valueChanged(int)), ui->vertex_size,
          SLOT(setValue(int)));
  connect(ui->vertex_size, SIGNAL(valueChanged(int)), ui->vertex_size_slider,
          SLOT(setValue(int)));
}

MainWindow::~MainWindow() {
  save_settings();
  free(ui->modelWindow->vertices);
  free(ui->modelWindow->polygons.vertices);

  delete ui;
}

void MainWindow::save_settings() {
  ui->modelWindow->setting.setValue("translate_x", ui->translate_x->value());
  ui->modelWindow->setting.setValue("translate_y", ui->translate_y->value());
  ui->modelWindow->setting.setValue("translate_z", ui->translate_z->value());

  ui->modelWindow->setting.setValue("rotate_x", ui->rotate_x->value());
  ui->modelWindow->setting.setValue("rotate_y", ui->rotate_y->value());
  ui->modelWindow->setting.setValue("rotate_z", ui->rotate_z->value());

  ui->modelWindow->setting.setValue("scale", ui->scale->value());

  ui->modelWindow->setting.setValue("line_style",
                                    ui->line_style_solid->isChecked());
  ui->modelWindow->setting.setValue("line_width", ui->line_width->value());

  ui->modelWindow->setting.setValue("vertex_style",
                                    ui->modelWindow->vertex_style);
  ui->modelWindow->setting.setValue("vertex_size", ui->vertex_size->value());

  ui->modelWindow->setting.setValue("central_type",
                                    ui->modelWindow->central_type);

  // color
  ui->modelWindow->setting.setValue("back_red", ui->modelWindow->back_r);
  ui->modelWindow->setting.setValue("back_green", ui->modelWindow->back_g);
  ui->modelWindow->setting.setValue("back_blue", ui->modelWindow->back_b);

  ui->modelWindow->setting.setValue("line_red", ui->modelWindow->line_r);
  ui->modelWindow->setting.setValue("line_green", ui->modelWindow->line_g);
  ui->modelWindow->setting.setValue("line_blue", ui->modelWindow->line_b);

  ui->modelWindow->setting.setValue("vertex_red", ui->modelWindow->vertex_r);
  ui->modelWindow->setting.setValue("vertex_green", ui->modelWindow->vertex_g);
  ui->modelWindow->setting.setValue("vertex_blue", ui->modelWindow->vertex_b);
}

void MainWindow::restore_settings() {
  ui->translate_x->setValue(
      ui->modelWindow->setting.value("translate_x").toInt());
  ui->translate_y->setValue(
      ui->modelWindow->setting.value("translate_y").toInt());
  ui->translate_z->setValue(
      ui->modelWindow->setting.value("translate_z").toInt());

  ui->rotate_x->setValue(ui->modelWindow->setting.value("rotate_x").toInt());
  ui->rotate_y->setValue(ui->modelWindow->setting.value("rotate_y").toInt());
  ui->rotate_z->setValue(ui->modelWindow->setting.value("rotate_z").toInt());

  ui->scale->setValue(ui->modelWindow->setting.value("scale").toInt());

  if (ui->modelWindow->setting.value("line_style").toBool() == true) {
    ui->line_style_solid->setChecked(true);
  } else {
    ui->line_style_dashed->setChecked(true);
  }

  ui->line_width->setValue(
      ui->modelWindow->setting.value("line_width").toInt());

  int vertex_style = ui->modelWindow->setting.value("vertex_style").toInt();
  if (vertex_style == 1) {
    ui->vertex_style_none->setChecked(true);
  } else if (vertex_style == 2) {
    ui->vertex_style_circle->setChecked(true);
  } else {
    ui->vertex_style_square->setChecked(true);
  }

  ui->vertex_size->setValue(
      ui->modelWindow->setting.value("vertex_size").toInt());

  bool central_type = ui->modelWindow->setting.value("central_type").toBool();
  if (central_type == true) {
    ui->projection_type_central->setChecked(true);
  } else {
    ui->projection_type_parallel->setChecked(true);
  }

  // color
  ui->modelWindow->back_r =
      ui->modelWindow->setting.value("back_red").toFloat();
  ui->modelWindow->back_g =
      ui->modelWindow->setting.value("back_green").toFloat();
  ui->modelWindow->back_b =
      ui->modelWindow->setting.value("back_blue").toFloat();

  ui->modelWindow->line_r =
      ui->modelWindow->setting.value("line_red").toFloat();
  ui->modelWindow->line_g =
      ui->modelWindow->setting.value("line_green").toFloat();
  ui->modelWindow->line_b =
      ui->modelWindow->setting.value("line_blue").toFloat();

  ui->modelWindow->vertex_r =
      ui->modelWindow->setting.value("vertex_red").toFloat();
  ui->modelWindow->vertex_g =
      ui->modelWindow->setting.value("vertex_green").toFloat();
  ui->modelWindow->vertex_b =
      ui->modelWindow->setting.value("vertex_blue").toFloat();
}

void MainWindow::on_open_file_clicked() {
  QString filePath = QFileDialog::getOpenFileName(
      this, "Open File", QDir::homePath(), "All Files (*.*)");

  std::string stdstrPath = filePath.toStdString();
  const char* pathtofile = stdstrPath.c_str();

  //    char const* pathtofile =
  //    "/Users/ngocgrag/Brodich/3DViewer-in-C-QT/src/assets/Squirrel.obj";

  FILE* fd;
  fd = fopen(pathtofile, "r");
  if (fd != NULL) {
    free(ui->modelWindow->vertices);
    free(ui->modelWindow->polygons.vertices);

    QFileInfo fileInfo(pathtofile);
    QString extension = fileInfo.suffix();
    if (extension != "obj") {
      QMessageBox msgBox;
      msgBox.setText("This is not obj file.\n Select obj file.");
      msgBox.exec();
    } else {
      get_parse_data(&ui->modelWindow->parse_data, pathtofile);
      get_vertices(fd, ui->modelWindow->parse_data.amount_vertices,
                   &ui->modelWindow->vertices);
      get_polygons(fd, ui->modelWindow->parse_data.amount_polygons,
                   &ui->modelWindow->polygons);

      ui->label_name->setText(fileInfo.fileName());
      ui->label_vertices->setText(
          QString::number(ui->modelWindow->parse_data.amount_vertices));
      ui->label_polygons->setText(
          QString::number(ui->modelWindow->parse_data.amount_polygons));
      fclose(fd);

      ui->modelWindow->size =
          get_max_vector(ui->modelWindow->vertices,
                         ui->modelWindow->parse_data.amount_vertices) *
          3.;
      restore_settings();
    }
  }
}

void MainWindow::on_translate_x_valueChanged(int arg1) {
  translateX(ui->modelWindow->parse_data.amount_vertices,
             &ui->modelWindow->vertices, -ui->modelWindow->xTrans);
  translateX(ui->modelWindow->parse_data.amount_vertices,
             &ui->modelWindow->vertices, ui->translate_x->value());
  ui->modelWindow->xTrans = ui->translate_x->value();
}

void MainWindow::on_translate_y_valueChanged(int arg1) {
  translateY(ui->modelWindow->parse_data.amount_vertices,
             &ui->modelWindow->vertices, -ui->modelWindow->yTrans);
  translateY(ui->modelWindow->parse_data.amount_vertices,
             &ui->modelWindow->vertices, ui->translate_y->value());
  ui->modelWindow->yTrans = ui->translate_y->value();
}

void MainWindow::on_translate_z_valueChanged(int arg1) {
  translateZ(ui->modelWindow->parse_data.amount_vertices,
             &ui->modelWindow->vertices, -ui->modelWindow->zTrans);
  translateZ(ui->modelWindow->parse_data.amount_vertices,
             &ui->modelWindow->vertices, ui->translate_z->value());
  ui->modelWindow->zTrans = ui->translate_z->value();
}

// rotate
void MainWindow::on_rotate_x_valueChanged(int arg1) {
  rotateX(ui->modelWindow->parse_data.amount_vertices,
          &ui->modelWindow->vertices, -ui->modelWindow->xRot);
  rotateX(ui->modelWindow->parse_data.amount_vertices,
          &ui->modelWindow->vertices, ui->rotate_x->value());
  ui->modelWindow->xRot = ui->rotate_x->value();
}

void MainWindow::on_rotate_y_valueChanged(int arg1) {
  rotateY(ui->modelWindow->parse_data.amount_vertices,
          &ui->modelWindow->vertices, -ui->modelWindow->yRot);
  rotateY(ui->modelWindow->parse_data.amount_vertices,
          &ui->modelWindow->vertices, ui->rotate_y->value());
  ui->modelWindow->yRot = ui->rotate_y->value();
}

void MainWindow::on_rotate_z_valueChanged(int arg1) {
  rotateZ(ui->modelWindow->parse_data.amount_vertices,
          &ui->modelWindow->vertices, -ui->modelWindow->zRot);
  rotateZ(ui->modelWindow->parse_data.amount_vertices,
          &ui->modelWindow->vertices, ui->rotate_z->value());
  ui->modelWindow->zRot = ui->rotate_z->value();
}

void MainWindow::on_scale_valueChanged(int arg1) {
  divide_shape(ui->modelWindow->parse_data.amount_vertices,
               &ui->modelWindow->vertices, ui->modelWindow->scale);
  scale_shape(ui->modelWindow->parse_data.amount_vertices,
              &ui->modelWindow->vertices, ui->scale->value());
  ui->modelWindow->scale = ui->scale->value();
}

void MainWindow::on_projection_type_central_toggled(bool checked) {
  ui->modelWindow->central_type = !ui->modelWindow->central_type;
}

void MainWindow::on_line_width_valueChanged(int arg1) {
  ui->modelWindow->line_width = ui->line_width->value();
}

void MainWindow::on_color_back_clicked() {
  QColor color = QColorDialog::getColor();
  if (color.isValid()) {
    ui->modelWindow->back_r = color.red() / 255.0f;
    ui->modelWindow->back_g = color.green() / 255.0f;
    ui->modelWindow->back_b = color.blue() / 255.0f;
  }
}

void MainWindow::on_color_line_clicked() {
  QColor color = QColorDialog::getColor();
  if (color.isValid()) {
    ui->modelWindow->line_r = color.red() / 255.0f;
    ui->modelWindow->line_g = color.green() / 255.0f;
    ui->modelWindow->line_b = color.blue() / 255.0f;
  }
}

void MainWindow::on_color_vertex_clicked() {
  QColor color = QColorDialog::getColor();
  if (color.isValid()) {
    ui->modelWindow->vertex_r = color.red() / 255.0f;
    ui->modelWindow->vertex_g = color.green() / 255.0f;
    ui->modelWindow->vertex_b = color.blue() / 255.0f;
  }
}

void MainWindow::on_line_style_solid_toggled(bool checked) {
  ui->modelWindow->solid_line = !ui->modelWindow->solid_line;
  if (ui->modelWindow->solid_line == true) {
    ui->text_line_width->setText("Line width");
  } else {
    ui->text_line_width->setText("Line density");
  }
}

void MainWindow::on_vertex_size_valueChanged(int arg1) {
  ui->modelWindow->size_vertex = ui->vertex_size->value();
}

void MainWindow::on_vertex_style_none_clicked() {
  ui->modelWindow->vertex_style = 1;
}

void MainWindow::on_vertex_style_circle_clicked() {
  ui->modelWindow->vertex_style = 2;
}

void MainWindow::on_vertex_style_square_clicked() {
  ui->modelWindow->vertex_style = 3;
  printf("fd\n");
}

void MainWindow::on_screenshot_clicked() {
  QPixmap screenshot = ui->modelWindow->grab();
  QString filePath = QFileDialog::getSaveFileName(
      nullptr, "Выберите путь сохранения", QDir::homePath(), "Все файлы (*.*)");
  if (!filePath.isEmpty()) {
    screenshot.save(filePath);
  }
}
