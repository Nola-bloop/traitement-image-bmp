#include "Bmp32.h"
#include "rgba.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <stdint.h>


Bmp32::Bmp32(const char* filePath)
{
    std::ifstream image{ filePath, std::ios::in | std::ios::binary };
    if (image.is_open())
    {
        image.read((char*)&m_fileHeader, sizeof(m_fileHeader));
        image.read((char*)&m_infoHeader, sizeof(m_infoHeader));
        image.read((char*)&m_colorHeader, sizeof(m_colorHeader));

        m_data.resize(m_infoHeader.size_image);

        image.seekg(m_fileHeader.offset, image.beg);
        image.read((char*)m_data.data(), m_data.size());

        image.close();
    }
}

Bmp32::Bmp32(int width, int height, uint8_t r = 255, uint8_t g = 255, uint8_t b = 255)
{
    // Le d�calage en octets pour obtenir les donn�es des pixels
    // est �quivalent � la taille des 3 en-t�tes
    m_fileHeader.offset = sizeof(m_fileHeader) + sizeof(m_infoHeader) + sizeof(m_colorHeader);

    // La taille totale est calcul�e � partir de la taille des en-t�tes et additionn�e
    // � la tailles des pixels constituant l'image o� chaque pixel a 4 composantes (BGRA) de 1 octet
    m_fileHeader.file_size = m_fileHeader.offset + width * height * 4;

    m_infoHeader.size = sizeof(m_infoHeader) + sizeof(m_colorHeader);
    m_infoHeader.width = width;
    m_infoHeader.height = -height;
    m_infoHeader.size_image = width * height * 4;
    m_infoHeader.bit_count = 32;

    m_data.resize(m_infoHeader.size_image);
    for (int i = 0; i < m_data.size(); i++)
    {
        m_data[i] = RGBA{r, g, b, 255};
    }
}

Bmp32::~Bmp32()
{
}

void Bmp32::Save(const char* filePath)
{
    std::ofstream outImage{ filePath, std::ios_base::binary };
    if (outImage)
    {
        outImage.write((char*)&m_fileHeader, sizeof(m_fileHeader));
        outImage.write((char*)&m_infoHeader, sizeof(m_infoHeader));
        outImage.write((char*)&m_colorHeader, sizeof(m_colorHeader));
        outImage.write((char*)m_data.data(), m_data.size());
    }
}

void Bmp32::DrawRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    int idx{ 0 };
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            m_data[idx] = RGBA{r, g, b, a};
        }
    }
}

void Bmp32::Negative()
{

}