#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char *unit)
{
    int num_pixels = w * h;
    int bits_per_pixel = 24; 
    float total_bits = num_pixels * bits_per_pixel;

    if (strcmp(unit, "bt") == 0)
    {
        return total_bits;
    }
    else if (strcmp(unit, "ko") == 0)
    {
        return (total_bits / 8) / 1024;
    }
    else if (strcmp(unit, "mo") == 0)
    {
        return (total_bits / 8) / (1024 * 1024);
    }
    else if (strcmp(unit, "go") == 0)
    {
        return (total_bits / 8) / (1024 * 1024 * 1024);
    }
    else
    {
        // Invalid unit
        return 0;
    }
    // YOUR CODE HERE - END
    return 0;
}