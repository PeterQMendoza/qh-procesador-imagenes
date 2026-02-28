#include "str_clasificador_rectangulo.hpp"

#include <stdexcept>
#include <algorithm>

ClasificadorRectangulo::ClasificadorRectangulo( int minArea)
: m_minArea(minArea){

    if (minArea <= 0){
        throw std::invalid_argument("Area minima invalida");
    }
}

bool ClasificadorRectangulo::clasificar(
    const Componente& componente,
    ResultadoDeteccion& resultado
) const {
    if (componente.area < m_minArea){
        return false;
    }

    double fill = componente.fillRatio();
    
    if (fill > 0.7){
        resultado.tipo = "rectangulo";
        resultado.confianza = fill;
        resultado.componente = componente;
        return true;
    }

    return false;
}
