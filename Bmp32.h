#ifndef BMP32_H
#define BMP32_h

#include <vector>
#include <string>
#include <stdint.h>

#include "rgba.h"
#include "Headers.h"
#include "Image.h"
#include "IDrawable.h"

class Bmp32
{
private:
    Image m_image;
protected:
public:
    Bmp32(const char*);
    Bmp32(int, int, uint8_t, uint8_t, uint8_t);
    ~Bmp32();
    void Draw(IDrawable* forme, RGBA col);
    void Negative();
    Image retournerImage();
    void Save(const char * path);
};

#endif