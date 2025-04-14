#include "GestionFichier.h"
#include <fstream>
#include "Headers.h"

Image GestionFichier::chargerImage(std::string filePath)
{
    Image image;

    std::ifstream fichier{ filePath, std::ios::in | std::ios::binary };
    if (fichier.is_open())
    {
        fichier.read((char*)&image.fileHeader, sizeof(image.fileHeader));
        fichier.read((char*)&image.infoHeader, sizeof(image.infoHeader));
        fichier.read((char*)&image.colorHeader, sizeof(image.colorHeader));

        image.data.resize(image.infoHeader.size_image);

        fichier.seekg(image.fileHeader.offset, fichier.beg);
        fichier.read((char*)image.data.data(), image.data.size());

        fichier.close();
    }

    return image;
}

void GestionFichier::Save(const char* filePath, Image image)
{
    std::ofstream outImage{ filePath, std::ios_base::binary };
    if (outImage)
    {
        outImage.write((char*)&image.fileHeader, sizeof(image.fileHeader));
        outImage.write((char*)&image.infoHeader, sizeof(image.infoHeader));
        outImage.write((char*)&image.colorHeader, sizeof(image.colorHeader));
        outImage.write((char*)image.data.data(), image.data.size());
    }
}
