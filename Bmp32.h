#ifndef BMP32_H
#define BMP32_h

#include <vector>
#include <string>
#include <stdint.h>

#include "rgba.h"
#include "Headers.h"
#include "Image.h"

class Bmp32
{
private:
    Image m_image;
protected:
public:
    Bmp32(const char*);
    Bmp32(int, int, uint8_t, uint8_t, uint8_t);
    ~Bmp32();
    void DrawRect(int, int, int, int, uint8_t r = 255, uint8_t g = 255, uint8_t b = 255, uint8_t a = 255);
    void Negative();
    Image retournerImage();
};

#endif