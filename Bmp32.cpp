#include "Bmp32.h"
#include "rgba.h"
#include "GestionFichier.h"
#include "Image.h"
#include "IDrawable.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <stdint.h>


Bmp32::Bmp32(const char* filePath)
{
    m_image = GestionFichier::chargerImage(filePath);
}

Bmp32::Bmp32(int width, int height, uint8_t r = 255, uint8_t g = 255, uint8_t b = 255)
{
    // Le d�calage en octets pour obtenir les donn�es des pixels
    // est �quivalent � la taille des 3 en-t�tes
    m_image.fileHeader.offset = sizeof(m_image.fileHeader) + sizeof(m_image.infoHeader) + sizeof(m_image.colorHeader);

    // La taille totale est calcul�e � partir de la taille des en-t�tes et additionn�e
    // � la tailles des pixels constituant l'image o� chaque pixel a 4 composantes (BGRA) de 1 octet
    m_image.fileHeader.file_size = m_image.fileHeader.offset + width * height * 4;

    m_image.infoHeader.size = sizeof(m_image.infoHeader) + sizeof(m_image.colorHeader);
    m_image.infoHeader.width = width;
    m_image.infoHeader.height = -height;
    m_image.infoHeader.size_image = width * height * 4;
    m_image.infoHeader.bit_count = 32;

    m_image.data.resize(m_image.infoHeader.size_image);
    for (int i = 0; i < m_image.data.size(); i++)
    {
        m_image.data[i] = RGBA{b, g, r, 255};
    }
}

Bmp32::~Bmp32()
{
}

void Bmp32::Draw(IDrawable* forme, RGBA col)
{
    std::vector<int> toDraw = forme->Draw(this->m_image.infoHeader.width);

    while (!toDraw.empty()){
        this->m_image.data.at(toDraw.at(toDraw.size()-1)) = col;
        toDraw.pop_back();
    }
}

void Bmp32::Negative()
{

}

Image Bmp32::retournerImage()
{
    return m_image;
}

void Bmp32::Save(const char * path)
{
    GestionFichier::Save(path, this->m_image);
}
