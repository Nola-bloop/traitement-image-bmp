#pragma once

#include "Headers.h"
#include <vector>
#include "rgba.h"
#include <string>
#include "Image.h"

namespace GestionFichier
{
	Image chargerImage(std::string filePath);
	void Save(const char* filePath, Image image);
};

