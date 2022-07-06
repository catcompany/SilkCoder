#include "decodewindow.h"

#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QStringList>

#include "SKP_Silk_SDK_API.h"
#include "ui_decodewindow.h"

#ifdef __cplusplus

extern "C" {
#include "decoder.h"
}

#endif

DecodeWindow::DecodeWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::DecodeWindow) {
  ui->setupUi(this);
}

DecodeWindow::~DecodeWindow() { delete ui; }

void DecodeWindow::on_buttonOpenFile_clicked() {
  sourcePath = QFileDialog::getOpenFileName(this, "Choose file",
                                            QDir::homePath(), "*.slk");
  if (sourcePath.isEmpty()) {
    return;
  }
  qDebug() << sourcePath;
  ui->labelSourcePath->setText(sourcePath);
}

void DecodeWindow::on_buttonDecode_clicked() {
  qDebug() << "decoder version: " << SKP_Silk_SDK_get_version();
  if (sourcePath == nullptr || sourcePath.isEmpty()) {
    return;
  }
  QStringList dstArrays = sourcePath.split(".");
  dstArrays.pop_back();
  for (auto i : dstArrays) {
    dstPath.append(i).append(".");
  }
  dstPath.append("pcm");
  ui->labelOutputPath->setText(dstPath);
  char* param[4096];
  //  param[1] = static_cast<char*>("/home/imorning/Downloads/test.slk");
  //  param[2] = static_cast<char*>("/home/imorning/Downloads/test.pcm");
  std::string input = sourcePath.toStdString();
  input.copy(param[1], input.length());
  param[2] = dstPath.toStdString().data();
  int result = decode(3, param);
  if (result != 0) {
    qDebug() << "error when decode and code is " << result;
  }
}
