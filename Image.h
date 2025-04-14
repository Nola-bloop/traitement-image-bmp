#pragma once
#include <vector>
#include "rgba.h"
#include "Headers.h"

struct Image
{
    std::vector<RGBA> data{};
    BMPFilheader fileHeader;
    BMPInfoHeader infoHeader;
    BMPColorHeader colorHeader;
};