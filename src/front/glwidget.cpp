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
//    ft_print_vertices(vertices, parse_data.amount_vertices);
//    ft_print_polygons(polygons);


    glEnable(GL_DEPTH_TEST);
    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(DIMENTION_COUNT, GL_DOUBLE, 0, vertices);

    glDrawElements(GL_LINES, polygons.number_of_vertices, GL_UNSIGNED_INT, polygons.vertices);
    glDisableClientState(GL_VERTEX_ARRAY);

    update();

}

void glwidget::paint() {
    paintGL();

}
