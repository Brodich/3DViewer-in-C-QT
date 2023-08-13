#define GL_SILENCE_DEPRECATION
#include "glwidget.h"

void glwidget::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  //    initializeOpenGLFunctions();
}

void glwidget::resizeGL(int weight, int height) {
  glViewport(0, 0, weight, height);
  paintGL();
}

void glwidget::paintGL() {

  double* vertices = (double*)malloc(12 * sizeof(double));
  vertices[0] = -0.5;
  vertices[1] = -0.5;
  vertices[2] = 0;

  vertices[3] = 0.5;
  vertices[4] = -0.5;
  vertices[5] = 0;

  vertices[6] = 0.5;
  vertices[7] = 0.5;
  vertices[8] = 0;

  vertices[9] = -0.5;
  vertices[10] = 0.5;
  vertices[11] = 0;

  int* poly = (int*)malloc(4 * sizeof(int));
  poly[0] = 0;
  poly[1] = 1;

  poly[2] = 2;
  poly[3] = 3;

  glEnable(GL_DEPTH_TEST);
  glEnableClientState(GL_VERTEX_ARRAY);

  glVertexPointer(DIMENTION_COUNT, GL_DOUBLE, 0, vertices);

  glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_INT, poly);
  glDisableClientState(GL_VERTEX_ARRAY);

  

  update();
}

void glwidget::paint() { paintGL(); }
