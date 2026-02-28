#pragma once

#include "CImg.h"

#include <string>
#include <cmath>

using CImgU = cimg_library::CImg<unsigned char>;

struct Componente {
    int etiqueta;

    int xmin = INT_MAX;
    int ymin = INT_MAX;
    int xmax = 0;
    int ymax = 0;

    int area = 0;
    int perimetro = 0;

    int width() const {return xmax - xmin + 1;}
    int height() const {return ymax - ymin + 1;}
    int boxArea() const {return width() * height();}

    double fillRatio() const {
        return boxArea() > 0 ? static_cast<double>(area) / boxArea() : 0.0;
    }

    double aspectRatio() const {
        return height() > 0 ? static_cast<double>(width()) / height() : 0.0;
    }
};