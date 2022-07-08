#ifndef CODER_H
#define CODER_H

#include <string>

/* Define codec specific settings should be moved to h file */
#define MAX_BYTES_PER_FRAME 1024
#define MAX_INPUT_FRAMES 5
#define MAX_FRAME_LENGTH 480
#define FRAME_LENGTH_MS 20
#define MAX_API_FS_KHZ 48
#define MAX_LBRR_DELAY 2

class Coder {
 public:
  Coder(std::string inputPath, std::string outputPath);
  std::string encode();
  std::string decode();

 private:
  std::string inputPath;
  std::string outputPath;
};

#endif  // CODER_H
