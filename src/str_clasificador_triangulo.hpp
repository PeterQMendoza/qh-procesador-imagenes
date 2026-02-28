#pragma once

#include "i_clasificador_forma.hpp"

#include <vector>

class ClasificadorTriangulo final: public IClasificadorForma {
    private:
        int m_minArea;

    public:
        explicit ClasificadorTriangulo(int minArea = 50);

        bool clasificar(
            const Componente& componente,
            ResultadoDeteccion& resultado
        ) const override;
};