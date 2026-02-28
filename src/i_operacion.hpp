#pragma once
#include "CImg.h"

using CImgU = cimg_library::CImg<unsigned char>;

class IOperacion {
    public:
        virtual void aplicar(CImgU& imagen) = 0;
        virtual ~IOperacion() = default;
};