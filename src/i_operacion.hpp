#pragma once
#include "CImg.h"

using namespace cimg_library;

class IOperacion {
    public:
        virtual void aplicar(CImg<unsigned char>& imagen) = 0;
        virtual ~IOperacion() = default;
};