#include "str_clasificador_triangulo.hpp"

#include <stdexcept>
#include <algorithm>
#include <cmath>

ClasificadorTriangulo::ClasificadorTriangulo(int minArea)
: m_minArea(minArea){
    if (minArea <= 0){
        throw std::invalid_argument("Area minima invalida");
    }
}

bool ClasificadorTriangulo::clasificar(
    const Componente& componente,
    ResultadoDeteccion& resultado
) const {
    if (componente.area < m_minArea){
        return false;
    }

    double fill = componente.fillRatio();
    if (fill > 0.25 && fill < 065){
        resultado.tipo = "triangulo";
        resultado.confianza = 1.0 - std::abs(0.5 - fill);
        resultado.componente = componente;
        return true;
    }

    return false;
}
