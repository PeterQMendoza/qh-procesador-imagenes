#pragma once

#include "componente.hpp"

#include "CImg.h"

#include <vector>

using namespace cimg_library;

class AnalizadorComponentes {
    public:
        std::vector<Componente> extraer (const CImgU& binario);

    private:
        int calcularPerimetroPixel(
            const CImgU& img,
            int x,
            int y
        ) const;
};