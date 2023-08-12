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
  double* vert = (double*)malloc(12 * sizeof(double));
  vert[0] = -0.5;
  vert[1] = -0.5;
  vert[2] = 0;

  vert[3] = 0.5;
  vert[4] = -0.5;
  vert[5] = 0;

  vert[6] = 0.5;
  vert[7] = 0.5;
  vert[8] = 0;

  vert[9] = -0.5;
  vert[10] = 0.5;
  vert[11] = 0;

  int* poly = (int*)malloc(4 * sizeof(int));

  poly[0] = 0;
  poly[1] = 1;

  poly[2] = 2;
  poly[3] = 3;

  glEnable(GL_DEPTH_TEST);
  glEnableClientState(GL_VERTEX_ARRAY);

  glVertexPointer(DIMENTION_COUNT, GL_DOUBLE, 0, vert);

  glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_INT, poly);
  glDisableClientState(GL_VERTEX_ARRAY);

  //    glEnable(GL_DEPTH_TEST);
  //    glEnableClientState(GL_VERTEX_ARRAY);

  //    glVertexPointer(DIMENTION_COUNT, GL_DOUBLE, 0, vertices);

  //    glDrawElements(GL_LINES, polygons.numbers_of_vertexes_in_facets - 1,
  //    GL_UNSIGNED_INT, polygons.vertexes);
  //    glDisableClientState(GL_VERTEX_ARRAY);

  update();
}

void glwidget::paint() { paintGL(); }
