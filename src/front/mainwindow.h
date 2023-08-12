#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <locale.h>

#include <QMainWindow>

#include "glwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
// сlass glwidget;
}  // namespace Ui
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void example();

 private slots:
  void openFile();
  void on_pushButton_2_clicked();
  void on_pushButton_3_pressed();

 private:
  Ui::MainWindow *ui;
  const char *path;
};
#endif  // MAINWINDOW_H
