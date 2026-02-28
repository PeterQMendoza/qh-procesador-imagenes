#pragma once

#include "i_clasificador_forma.hpp"

#include <vector>
#include <algorithm>

class ClasificadorRectangulo final : public IClasificadorForma {
    private:
        int m_minArea;

    public:
        explicit ClasificadorRectangulo(int minArea = 100);
        
        bool clasificar(
            const Componente& componente,
            ResultadoDeteccion& resultado
        ) const override;
};