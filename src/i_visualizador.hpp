#pragma once

#include "i_clasificador_forma.hpp"

#include "CImg.h"

#include <vector>

using CImgU = cimg_library::CImg<unsigned char>;

class IVisualizador {
    public:
        virtual ~IVisualizador() = default;
        virtual void mostrar(
            const CImgU& imagen,
            const std::vector<ResultadoDeteccion>& resultados
        ) const = 0;
};