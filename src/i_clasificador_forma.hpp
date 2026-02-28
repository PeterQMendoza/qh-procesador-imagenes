#pragma once

#include "componente.hpp"

#include "CImg.h"

#include <vector>

struct ResultadoDeteccion {
    std::string tipo;

    double confianza;
    Componente componente;
};

class IClasificadorForma {
    public:
        virtual ~IClasificadorForma() = default;
        
        virtual bool clasificar(
            const Componente& componente,
            ResultadoDeteccion& resultado
        ) const = 0;
};