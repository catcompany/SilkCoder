#ifndef DECODEWINDOW_H
#define DECODEWINDOW_H

#include <QMainWindow>

namespace Ui {
class DecodeWindow;
}

class DecodeWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit DecodeWindow(QWidget *parent = nullptr);
  ~DecodeWindow();

 private:
  Ui::DecodeWindow *ui;
  QString sourcePath = nullptr;
  QString dstPath = "";

 public slots:
  void on_buttonOpenFile_clicked();
  void on_buttonDecode_clicked();
};

#endif  // DECODEWINDOW_H
