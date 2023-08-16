#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <locale.h>

//#define GL_SILENCE_DEPRECATION
#define DIMENTION_COUNT 3

extern "C"
{
    #include "../back/parser.h"
}


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_open_file_clicked();

    void on_translate_x_valueChanged(int arg1);

    void on_translate_y_valueChanged(int arg1);

    void on_translate_z_valueChanged(int arg1);

    void on_rotate_x_valueChanged(int arg1);
    void on_rotate_y_valueChanged(int arg1);
    void on_rotate_z_valueChanged(int arg1);

    void on_scale_valueChanged(int arg1);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
