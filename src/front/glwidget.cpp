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

//    double* vert = (double*) malloc( 12 * sizeof(double));
//    vert[0] = -2.5;
//    vert[1] = -2.5;
//    vert[2] = 0;

//    vert[3] = 2.5;
//    vert[4] = -2.5;
//    vert[5] = 0;

//    vert[6] = 2.5;
//    vert[7] = 2.5;
//    vert[8] = 0;

//    vert[9] = -2.5;
//    vert[10] = 2.5;
//    vert[11] = 0;



//    int* poly = (int*)malloc(4 * sizeof(int));

//    poly[0] = 0;
//    poly[1] = 1;

//    poly[2] = 2;
//    poly[3] = 3;

////    printf("affffff\n");

//    glEnable(GL_DEPTH_TEST);
//    glEnableClientState(GL_VERTEX_ARRAY);

//    glVertexPointer(DIMENTION_COUNT, GL_DOUBLE, 0, vert);

//    glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_INT, poly);
//    glDisableClientState(GL_VERTEX_ARRAY);



    ft_print_vertices(vertices, parse_data.amount_vertices);
    ft_print_polygons(polygons);


//    glEnable(GL_DEPTH_TEST);
//    glEnableClientState(GL_VERTEX_ARRAY);

//    glVertexPointer(DIMENTION_COUNT, GL_DOUBLE, 0, vertices);

//    glDrawElements(GL_LINES, polygons.number_of_vertices - 1, GL_UNSIGNED_INT, polygons.vertices);
//    glDisableClientState(GL_VERTEX_ARRAY);

    update();

}

void glwidget::paint() {
    paintGL();

}
