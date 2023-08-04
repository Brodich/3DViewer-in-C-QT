#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    data_t parse_data = {0};
    char const* pathtofile = "/Users/ngocgrag/Brodich/3DViewer-in-C-QT/src/assets/test.obj";

    get_parse_data(&parse_data, pathtofile);

    matrix_t matrix; // free
    polygon_t* polygons; // free
    st_create_matrix(parse_data.count_of_vertexes, 3, &matrix);
    polygons = (polygon_t*) calloc(parse_data.count_of_facets, sizeof(polygon_t));

    FILE* fd;
    fd = fopen(pathtofile, "r");
    get_matrix(fd, parse_data.count_of_vertexes, &matrix);
    get_polygon(fd, parse_data.count_of_facets, &polygons);

    printf("z %d\n", parse_data.count_of_vertexes);
    printf("z %d\n", parse_data.count_of_facets);

    ft_print_matrix(matrix);
    ft_print_polygons(polygons, parse_data.count_of_facets);

}

MainWindow::~MainWindow()
{
    delete ui;
}

