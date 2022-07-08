#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  QString sourcePath = nullptr;
  QString dstPath = "";

 public slots:
  void on_buttonOpenFile_clicked();
  void on_buttonDecode_clicked();
};

#endif  // MAINWINDOW_H
