#define GL_SILENCE_DEPRECATION


#include "glwidget.h"

//glwidget::glwidget()
//{

//}

void glwidget::initializeGL() {
    glEnable(GL_DEPTH_TEST);
//    initializeOpenGLFunctions();

}

void glwidget::resizeGL(int weight, int height) {
    glViewport(0, 0, weight, height);
    paintGL();
}

void glwidget::paintGL() {

    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(DIMENTION_COUNT, GL_DOUBLE, 0, vertices);

    glDrawElements(GL_LINES, polygons.numbers_of_vertexes_in_facets - 1, GL_UNSIGNED_INT, polygons.vertexes);
    glDisableClientState(GL_VERTEX_ARRAY);

    update();

}
