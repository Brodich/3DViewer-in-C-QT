#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QtWidgets>


#define GL_SILENCE_DEPRECATION

#include "mainwindow.h"
#include "../back/parser.h"

class glwidget : public QOpenGLWidget {
Q_OBJECT

public:
    glwidget(QWidget* parent = NULL) : QOpenGLWidget(parent) {}

    using QOpenGLWidget::QOpenGLWidget;
    void paint();

    data_t parse_data = {0};
    polygon_t polygons = {0};
    double* vertices = NULL;

    int xTrans = 0, yTrans = 0, zTrans = 0;
    int xRot = 0, yRot = 0, zRot = 0;
    int scale = 1;
    double size = 1;


protected:
    void initializeGL() override;
    void resizeGL(int weight, int height) override;
    void paintGL() override;




};

#endif // GLWIDGET_H
