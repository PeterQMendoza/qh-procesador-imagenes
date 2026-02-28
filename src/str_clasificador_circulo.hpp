#pragma once

#include "i_clasificador_forma.hpp"

#include <vector>

class ClasificadorCirculo final: public IClasificadorForma{
    private:
        double m_minCircularidad;
        int m_minArea;

    public:
        explicit ClasificadorCirculo(double minCirc = 0.6, int minA = 50);
        bool clasificar(
            const Componente& componente,
            ResultadoDeteccion& resultado
        ) const override;
};