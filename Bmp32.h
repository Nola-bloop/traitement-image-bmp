#ifndef BMP32_H
#define BMP32_h

#include <vector>
#include <string>

#include "Headers.h"

class Bmp32
{
private:
    std::vector<uint8_t> m_data{};
    BMPFilheader m_fileHeader;
    BMPInfoHeader m_infoHeader;
    BMPColorHeader m_colorHeader;

    int IndexFromPos(int, int);
protected:
public:
    Bmp32(const char*);
    Bmp32(int, int, uint8_t, uint8_t, uint8_t);
    ~Bmp32();
    void Save(const char*);
    void DrawRect(int, int, int, int, uint8_t r = 255, uint8_t g = 255, uint8_t b = 255, uint8_t a = 255);
    void Negative();
};

#endif