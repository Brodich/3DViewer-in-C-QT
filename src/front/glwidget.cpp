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
//    glViewport(0, 0, weight, height);

    int w = 100;
    int h = 100;

//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glViewport(-50, -50, w, h);
//    glOrtho(40, 50, 200, 0, -1, 1);
//    glMatrixMode(GL_MODELVIEW);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScaled(2.0, 1.5, 1.0);

//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glViewport(0, 0, (GLint)w, (GLint)h);
//    glOrtho(1, 1, 1, 1, -10, 1000);
//    glMatrixMode(GL_MODELVIEW);

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
