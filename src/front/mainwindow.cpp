#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    data_t parse_data = {0};
    char const* pathtofile = "/Users/eusebiaa/Projects/3DViewer-in-C-QT/src/assets/test.obj";
    // char* pathtofile = "assets/test.obj";
    // char* pathtofile = "/home/qni/Brodichgit/3DViewer-in-C-QT/src/assets/test.obj";

    get_parse_data(&parse_data, pathtofile);

    polygon_t polygons; // free
    double* vertices = NULL; // free

    FILE* fd;
    fd = fopen(pathtofile, "r");

    get_vertices(fd, parse_data.count_of_vertexes, &vertices);
    get_polygons(fd, parse_data.count_of_facets, &polygons);

    fclose(fd);

    printf("z %d\n", parse_data.count_of_vertexes);
    printf("z %d\n", parse_data.count_of_facets);

    ft_print_vertices(vertices, parse_data.count_of_vertexes);
    ft_print_polygons(polygons, 6);



//    glClearColor(1.0, 1.0, 1.0, 1.0);

//    if (polygons.vertexes != NULL)
//    ui->modelWindow->paint();

//    glwidget
//    glwidget::paintGL();
    if (vertices)
      free(vertices);
    if (polygons.vertexes)
      free(polygons.vertexes);

}

MainWindow::~MainWindow()
{
    delete ui;
}

