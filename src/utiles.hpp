#pragma once
#include "CImg.h"
#include "componente.hpp"
#include <vector>
#include <cmath>

using namespace cimg_library;

inline double circularidad(double area, double perimetro){
    if(perimetro <= 0) return 0.0;
    return (4.0 * M_PI * area) / (perimetro * perimetro);
}