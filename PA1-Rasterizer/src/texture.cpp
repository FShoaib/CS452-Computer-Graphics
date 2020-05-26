#include "texture.h"
#include "CGL/color.h"
#include "drawrend.h"
#include <math.h>

namespace CGL {

Color Texture::sample(const SampleParams &sp) {
  // Part 5: this funtion chooses between nearest pixel sampling and bilinear pixel interpolation sampling 
  if (sp.psm == P_NEAREST) {
    return sample_nearest(sp.p_uv);
  }
  else {
    return sample_bilinear(sp.p_uv);
  }
}

Color Texture::sample_nearest(Vector2D uv) {
  // Part 5: Understand how this funtion has been implemented.
  // keep value of level to 0
  int level = 0;
  int w = mipmap[level].width;
  int h = mipmap[level].height;

  int X = uv.x * w;
  int Y = uv.y * h;
  if (X >= 0 && X < w && Y >= 0 && Y < h) {
    int index = 4 * (Y * w + X);

    float r = (mipmap[level].texels[index]) / 255.0f;
    float g = (mipmap[level].texels[index+1]) / 255.0f;
    float b = (mipmap[level].texels[index+2]) / 255.0f;
    return Color(r, g, b);
  }
}

Color lerp(float x, Color v0, Color v1) {

    return v0 + x * (v1 + (v0 * (-1.0)));
}

Color Texture::sample_bilinear(Vector2D uv) {
  // Part 5: Fill this in.
  // Hint: look at sample_nearest
  int level = 0;
  int w = mipmap[level].width;
  int h = mipmap[level].height;

  float x_max = ceil(uv.x * w);
  float x_min = floor(uv.x * w);

  float y_max = ceil(uv.y * h);
  float y_min = floor(uv.y * h);


  if (x_max >= 0 && x_max < w && x_min >= 0 && x_min < w && y_max >= 0 && y_max < h && y_min >= 0 && y_min < h) {
    
    int in1 = 4 * (y_max * w + x_max);
    int in2 = 4 * (y_max * w + x_min);
    int in3 = 4 * (y_min * w + x_max);
    int in4 = 4 * (y_min * w + x_min);


    float r1 = (mipmap[level].texels[in1]) / 255.0f;
    float g1 = (mipmap[level].texels[in1+1]) / 255.0f;
    float b1 = (mipmap[level].texels[in1+2]) / 255.0f;

    float r2 = (mipmap[level].texels[in2]) / 255.0f;
    float g2 = (mipmap[level].texels[in2+1]) / 255.0f;
    float b2 = (mipmap[level].texels[in2+2]) / 255.0f;

    float r3 = (mipmap[level].texels[in3]) / 255.0f;
    float g3 = (mipmap[level].texels[in3+1]) / 255.0f;
    float b3 = (mipmap[level].texels[in3+2]) / 255.0f;

    float r4 = (mipmap[level].texels[in4]) / 255.0f;
    float g4 = (mipmap[level].texels[in4+1]) / 255.0f;
    float b4 = (mipmap[level].texels[in4+2]) / 255.0f;

Color c1=Color(r1,g1,b1);
Color c2=Color(r2,g2,b2);
Color c3=Color(r3,g3,b3);
Color c4=Color(r4,g4,b4);

float xc=uv.x-floor(uv.x);
float yc=uv.y-floor(uv.y);


Color f1=c3+(xc)*(c4+(c3*(-1)));
Color f2=c1+(xc)*(c2+(c1*(-1)));

Color f=f1+(yc)*(f2+(f1*(-1)));

return f;


/*

Color u0 = lerp((uv.x - floor(uv.x)), c3, c4);
Color u1 = lerp((uv.x - floor(uv.x)), c1, c2);
      return lerp((uv.y - floor(uv.y)), u0, u1);
  */

/*
float xc=uv.x-floor(uv.x);
float yc=uv.y-floor(uv.y);

Color li_12=c1 + xc * (c2 + (c1 * (-1.0)));
Color li_34=c3 + xc * (c4 + (c3 * (-1.0)));

Color lf=li_12 + yc * (li_34 + (li_12 * (-1.0)));

return lf;
*/
/*

float rf1=(x_max-uv.x)/(x_max-x_min)*r1 + (uv.x-x_min)/(x_max-x_min)*r2;
float rf2=(x_max-uv.x)/(x_max-x_min)*r3 + (uv.x-x_min)/(x_max-x_min)*r4;

float rf=(x_max-uv.x)/(x_max-x_min)*rf1 + (uv.x-x_min)/(x_max-x_min)*rf2;


float gf1=(x_max-uv.x)/(x_max-x_min)*g1 + (uv.x-x_min)/(x_max-x_min)*g2;
float gf2=(x_max-uv.x)/(x_max-x_min)*g3 + (uv.x-x_min)/(x_max-x_min)*g4;

float gf=(x_max-uv.x)/(x_max-x_min)*gf1 + (uv.x-x_min)/(x_max-x_min)*gf2;


float bf1=(x_max-uv.x)/(x_max-x_min)*b1 + (uv.x-x_min)/(x_max-x_min)*b2;
float bf2=(x_max-uv.x)/(x_max-x_min)*b3 + (uv.x-x_min)/(x_max-x_min)*b4;

float bf=(x_max-uv.x)/(x_max-x_min)*bf1 + (uv.x-x_min)/(x_max-x_min)*bf2;


Color ler1=lerp(r1,r2,r3,r4);
Color ler2=lerp(g1,g2,g3,g4);
Color ler3=lerp(b1,b2,b3,b4);

    return Color(rf,gf,bf);
*/
  }

}



/****************************************************************************/



inline void uint8_to_float(float dst[4], unsigned char *src) {
  uint8_t *src_uint8 = (uint8_t *)src;
  dst[0] = src_uint8[0] / 255.f;
  dst[1] = src_uint8[1] / 255.f;
  dst[2] = src_uint8[2] / 255.f;
  dst[3] = src_uint8[3] / 255.f;
}

inline void float_to_uint8(unsigned char *dst, float src[4]) {
  uint8_t *dst_uint8 = (uint8_t *)dst;
  dst_uint8[0] = (uint8_t)(255.f * max(0.0f, min(1.0f, src[0])));
  dst_uint8[1] = (uint8_t)(255.f * max(0.0f, min(1.0f, src[1])));
  dst_uint8[2] = (uint8_t)(255.f * max(0.0f, min(1.0f, src[2])));
  dst_uint8[3] = (uint8_t)(255.f * max(0.0f, min(1.0f, src[3])));
}

void Texture::generate_mips(int startLevel) {

  // make sure there's a valid texture
  if (startLevel >= mipmap.size()) {
    std::cerr << "Invalid start level";
  }

  // allocate sublevels
  int baseWidth = mipmap[startLevel].width;
  int baseHeight = mipmap[startLevel].height;
  int numSubLevels = (int)(log2f((float)max(baseWidth, baseHeight)));

  numSubLevels = min(numSubLevels, kMaxMipLevels - startLevel - 1);
  mipmap.resize(startLevel + numSubLevels + 1);

  int width = baseWidth;
  int height = baseHeight;
  for (int i = 1; i <= numSubLevels; i++) {

    MipLevel &level = mipmap[startLevel + i];

    // handle odd size texture by rounding down
    width = max(1, width / 2);
    //assert (width > 0);
    height = max(1, height / 2);
    //assert (height > 0);

    level.width = width;
    level.height = height;
    level.texels = vector<unsigned char>(4 * width * height);
  }

  // create mips
  int subLevels = numSubLevels - (startLevel + 1);
  for (int mipLevel = startLevel + 1; mipLevel < startLevel + subLevels + 1;
       mipLevel++) {

    MipLevel &prevLevel = mipmap[mipLevel - 1];
    MipLevel &currLevel = mipmap[mipLevel];

    int prevLevelPitch = prevLevel.width * 4; // 32 bit RGBA
    int currLevelPitch = currLevel.width * 4; // 32 bit RGBA

    unsigned char *prevLevelMem;
    unsigned char *currLevelMem;

    currLevelMem = (unsigned char *)&currLevel.texels[0];
    prevLevelMem = (unsigned char *)&prevLevel.texels[0];

    float wDecimal, wNorm, wWeight[3];
    int wSupport;
    float hDecimal, hNorm, hWeight[3];
    int hSupport;

    float result[4];
    float input[4];

    // conditional differentiates no rounding case from round down case
    if (prevLevel.width & 1) {
      wSupport = 3;
      wDecimal = 1.0f / (float)currLevel.width;
    } else {
      wSupport = 2;
      wDecimal = 0.0f;
    }

    // conditional differentiates no rounding case from round down case
    if (prevLevel.height & 1) {
      hSupport = 3;
      hDecimal = 1.0f / (float)currLevel.height;
    } else {
      hSupport = 2;
      hDecimal = 0.0f;
    }

    wNorm = 1.0f / (2.0f + wDecimal);
    hNorm = 1.0f / (2.0f + hDecimal);

    // case 1: reduction only in horizontal size (vertical size is 1)
    if (currLevel.height == prevLevel.height) {
      //assert (currLevel.height == 1);

      for (int i = 0; i < currLevel.width; i++) {
        wWeight[0] = wNorm * (1.0f - wDecimal * i);
        wWeight[1] = wNorm * 1.0f;
        wWeight[2] = wNorm * wDecimal * (i + 1);

        result[0] = result[1] = result[2] = result[3] = 0.0f;

        for (int ii = 0; ii < wSupport; ii++) {
          uint8_to_float(input, prevLevelMem + 4 * (2 * i + ii));
          result[0] += wWeight[ii] * input[0];
          result[1] += wWeight[ii] * input[1];
          result[2] += wWeight[ii] * input[2];
          result[3] += wWeight[ii] * input[3];
        }

        // convert back to format of the texture
        float_to_uint8(currLevelMem + (4 * i), result);
      }

      // case 2: reduction only in vertical size (horizontal size is 1)
    } else if (currLevel.width == prevLevel.width) {
      //assert (currLevel.width == 1);

      for (int j = 0; j < currLevel.height; j++) {
        hWeight[0] = hNorm * (1.0f - hDecimal * j);
        hWeight[1] = hNorm;
        hWeight[2] = hNorm * hDecimal * (j + 1);

        result[0] = result[1] = result[2] = result[3] = 0.0f;
        for (int jj = 0; jj < hSupport; jj++) {
          uint8_to_float(input, prevLevelMem + prevLevelPitch * (2 * j + jj));
          result[0] += hWeight[jj] * input[0];
          result[1] += hWeight[jj] * input[1];
          result[2] += hWeight[jj] * input[2];
          result[3] += hWeight[jj] * input[3];
        }

        // convert back to format of the texture
        float_to_uint8(currLevelMem + (currLevelPitch * j), result);
      }

      // case 3: reduction in both horizontal and vertical size
    } else {

      for (int j = 0; j < currLevel.height; j++) {
        hWeight[0] = hNorm * (1.0f - hDecimal * j);
        hWeight[1] = hNorm;
        hWeight[2] = hNorm * hDecimal * (j + 1);

        for (int i = 0; i < currLevel.width; i++) {
          wWeight[0] = wNorm * (1.0f - wDecimal * i);
          wWeight[1] = wNorm * 1.0f;
          wWeight[2] = wNorm * wDecimal * (i + 1);

          result[0] = result[1] = result[2] = result[3] = 0.0f;

          // convolve source image with a trapezoidal filter.
          // in the case of no rounding this is just a box filter of width 2.
          // in the general case, the support region is 3x3.
          for (int jj = 0; jj < hSupport; jj++)
            for (int ii = 0; ii < wSupport; ii++) {
              float weight = hWeight[jj] * wWeight[ii];
              uint8_to_float(input, prevLevelMem +
                                        prevLevelPitch * (2 * j + jj) +
                                        4 * (2 * i + ii));
              result[0] += weight * input[0];
              result[1] += weight * input[1];
              result[2] += weight * input[2];
              result[3] += weight * input[3];
            }

          // convert back to format of the texture
          float_to_uint8(currLevelMem + currLevelPitch * j + 4 * i, result);
        }
      }
    }
  }
}

}
