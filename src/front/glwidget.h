#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QtWidgets>

#define DIMENTION_COUNT 3

extern "C" {
#include "../back/parser.h"
}

class glwidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  glwidget(QWidget* parent = NULL) : QOpenGLWidget(parent) {}

  using QOpenGLWidget::QOpenGLWidget;
  void paint();

  data_t parse_data = {0};
  polygon_t polygons = {0};
  double* vertices = NULL;

 protected:
  void initializeGL() override;
  void resizeGL(int weight, int height) override;
  void paintGL() override;
};

#endif  // GLWIDGET_H
