#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char *unit)
{
   float bitsPerColorPixel = 24;
   float videoSizeColor = w * h * bitsPerColorPixel * durationMovie * fps;
   float videoSizeBW = w * h * durationCredits * fps;
   float totalSizeBits = videoSizeColor + videoSizeBW;
   float finalSize;

   if (strcmp(unit, "bt") == 0)
   {
      finalSize = totalSizeBits;
   }
   else if (strcmp(unit, "ko") == 0)
   {
      finalSize = totalSizeBits / 1024;
   }
   else if (strcmp(unit, "mo") == 0)
   {
      finalSize = totalSizeBits / (1024 * 1024);
   }
   else if (strcmp(unit, "go") == 0)
   {
      finalSize = totalSizeBits / (1024 * 1024 * 1024);
   }
   else
   {
      return -1.0f;
   }
   return finalSize / 8;
}