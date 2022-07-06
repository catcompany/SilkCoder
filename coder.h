#ifndef CODER_H
#define CODER_H

#include <QString>
#include <filesystem>

/* Define codec specific settings should be moved to h file */
#define MAX_BYTES_PER_FRAME 1024
#define MAX_INPUT_FRAMES 5
#define MAX_FRAME_LENGTH 480
#define FRAME_LENGTH_MS 20
#define MAX_API_FS_KHZ 48
#define MAX_LBRR_DELAY 2

class Coder {
 public:
  Coder(QString &inputPath, QString &outputPath);
  int encode();
  int decode();

 private:
  QString inputPath;
  QString outputPath;
};

#endif  // CODER_H
