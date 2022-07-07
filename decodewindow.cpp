#include "decodewindow.h"

#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QStringList>

#include "SKP_Silk_SDK_API.h"
#include "coder.h"
#include "lame.h"
#include "ui_decodewindow.h"

#ifdef __cplusplus

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
  qDebug() << "silk decoder version: " << SKP_Silk_SDK_get_version();
  qDebug() << "lame version: " << get_lame_version();
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

  Coder* coder = new Coder(sourcePath, dstPath);
  int result = coder->decode();
  if (result != 0) {
    qDebug() << "error when decode and code is " << result;
  } else {
    qDebug() << "decode success!";
  }
  dstPath = "";
}
