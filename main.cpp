#include <QApplication>

#include "decodewindow.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  DecodeWindow w;
  w.show();
  return a.exec();
}
