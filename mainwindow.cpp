#include "mainwindow.h"

#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QStringList>

#include "SKP_Silk_SDK_API.h"
#include "coder.h"
#include "lame.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->statusbar->showMessage(
      QString("silk version:%1  lame version:%2")
          .arg(SKP_Silk_SDK_get_version(), get_lame_version()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_buttonOpenFile_clicked() {
#ifdef __ANDROID__

  return;
#endif

  sourcePath = QFileDialog::getOpenFileName(this, "Choose file",
                                            QDir::homePath(), "*.*");
  if (sourcePath.isEmpty()) {
    return;
  }
  ui->statusbar->showMessage(sourcePath);
  ui->labelSourcePath->setText(sourcePath);
}

void MainWindow::on_buttonDecode_clicked() {
  if (sourcePath == nullptr || sourcePath.isEmpty()) {
    return;
  }
  QStringList dstArrays = sourcePath.split(".");
  dstArrays.pop_back();
  for (auto& i : dstArrays) {
    dstPath.append(i).append(".");
  }
  dstPath.append("pcm");
  ui->labelOutputPath->setText(dstPath);

  Coder* coder = new Coder(sourcePath.toStdString(), dstPath.toStdString());
  std::string result = coder->decode();
  if (result != "0") {
    ui->statusbar->showMessage(QString("error when decode and code is %1")
                                   .arg(QString().fromStdString(result)));
  } else {
    ui->statusbar->showMessage("decode success!");
  }

  delete coder;
  dstPath = "";
}
