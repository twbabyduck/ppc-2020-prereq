#include "average.h"
#include <vector>

Result calculate(int ny, int nx, const float *data, int y0, int x0, int y1,
                 int x1) {
  // Your implementation here
  double color[3] = {0.0, 0.0, 0.0};
  int rectHeight = (y1-y0);
  int rectWidth = (x1-x0);
  int numOfPixels = (rectHeight*rectWidth);

  for (int y = y0; y < y1; ++y) {
    for (int x = x0; x < x1; ++x) {
        color[0] += data[(y * nx + x) * 3 + 0];
        color[1] += data[(y * nx + x) * 3 + 1];
        color[2] += data[(y * nx + x) * 3 + 2];
    }
  }

  float r  = color[0]/numOfPixels;
  float g  = color[1]/numOfPixels;
  float b  = color[2]/numOfPixels;

  Result result{{r, g, b}};
  return result;
}
