#include "coder.h"

#include <QDebug>

#ifdef _WIN32
#define _CRT_SECURE_NO_DEPRECATE 1
#endif

#ifdef __cplusplus
extern "C" {
#include "SKP_Silk_SDK_API.h"
#include "SKP_Silk_SigProc_FIX.h"
}
#endif

#ifdef _SYSTEM_IS_BIG_ENDIAN
/* Function to convert a little endian int16 to a */
/* big endian int16 or vica verca                 */
void swap_endian(SKP_int16 vec[], SKP_int len) {
  SKP_int i;
  SKP_int16 tmp;
  SKP_uint8 *p1, *p2;

  for (i = 0; i < len; i++) {
    tmp = vec[i];
    p1 = (SKP_uint8 *)&vec[i];
    p2 = (SKP_uint8 *)&tmp;
    p1[0] = p2[1];
    p1[1] = p2[0];
  }
}
#endif

#if (defined(_WIN32) || defined(_WINCE))
#include <windows.h> /* timer */
#else                // Linux or Mac
#include <sys/time.h>
#endif

#ifdef _WIN32

unsigned long GetHighResolutionTime() /* O: time in usec*/
{
  /* Returns a time counter in microsec	*/
  /* the resolution is platform dependent */
  /* but is typically 1.62 us resolution  */
  LARGE_INTEGER lpPerformanceCount;
  LARGE_INTEGER lpFrequency;
  QueryPerformanceCounter(&lpPerformanceCount);
  QueryPerformanceFrequency(&lpFrequency);
  return (unsigned long)((1000000 * (lpPerformanceCount.QuadPart)) /
                         lpFrequency.QuadPart);
}
#else   // Linux or Mac
unsigned long GetHighResolutionTime() /* O: time in usec*/
{
  struct timeval tv;
  gettimeofday(&tv, 0);
  return ((tv.tv_sec * 1000000) + (tv.tv_usec));
}
#endif  // _WIN32

/* Seed for the random number generator, which is used for simulating packet
 * loss */
static SKP_int32 rand_seed = 1;

Coder::Coder(QString &inputPath, QString &outputPath) {
  this->inputPath = inputPath;
  this->outputPath = outputPath;
}

int Coder::encode() { return 0; }

int Coder::decode() {
  unsigned long tottime, starttime;
  double filetime;
  size_t counter;
  SKP_int32 totPackets, i, k;
  SKP_int16 ret, len, tot_len;
  SKP_int16 nBytes;
  SKP_uint8
      payload[MAX_BYTES_PER_FRAME * MAX_INPUT_FRAMES * (MAX_LBRR_DELAY + 1)];
  SKP_uint8 *payloadEnd = NULL, *payloadToDec = NULL;
  SKP_uint8 FECpayload[MAX_BYTES_PER_FRAME * MAX_INPUT_FRAMES], *payloadPtr;
  SKP_int16 nBytesFEC;
  SKP_int16 nBytesPerPacket[MAX_LBRR_DELAY + 1], totBytes;
  SKP_int16 out[((FRAME_LENGTH_MS * MAX_API_FS_KHZ) << 1) * MAX_INPUT_FRAMES],
      *outPtr;
  char speechOutFileName[150], bitInFileName[150];
  FILE *bitInFile, *speechOutFile;
  SKP_int32 packetSize_ms = 0, API_Fs_Hz = 0;
  SKP_int32 decSizeBytes;
  void *psDec;
  SKP_float loss_prob;
  SKP_int32 frames, lost, quiet;
  SKP_SILK_SDK_DecControlStruct DecControl;
  if (inputPath.isEmpty() || outputPath.isEmpty()) {
    throw -1;
  }
  /* default settings */
  quiet = 0;
  loss_prob = 0.0f;

  strcpy(bitInFileName, inputPath.toStdString().data());
  strcpy(speechOutFileName, outputPath.toStdString().data());
  qDebug() << "input: " << bitInFileName;
  qDebug() << "output: " << speechOutFileName;

  return 0;
}
