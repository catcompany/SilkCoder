#ifndef MP3ENCODER_H
#define MP3ENCODER_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#include "lame.h"
}
#endif

#define QQ_sampleRate 12000

class Mp3Encoder {
 public:
  Mp3Encoder();
  ~Mp3Encoder();
  int Init(const char* pcmFilePath, const char* mp3FilePath, int sampleRate,
           int channels, int bitRate);
  void Encode();
  void Destory();

 private:
  FILE* pcmFile;
  FILE* mp3File;
  lame_t lameClient;
};

#endif  // MP3ENCODER_H
