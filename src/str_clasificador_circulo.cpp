#include "str_clasificador_circulo.hpp"
#include <stdexcept>
#include <algorithm>

ClasificadorCirculo::ClasificadorCirculo(double minCircularidad, int minArea)
: m_minCircularidad(minCircularidad), m_minArea(minArea) {
    if (minCircularidad <= 0.0 || minCircularidad > 1.0){
        throw std::invalid_argument("Circularidad invalida");
    }

    if (minArea <= 0.0){
        throw std::invalid_argument("Area minima invalida");
    }
}

bool ClasificadorCirculo::clasificar(
    const Componente& componente,
    ResultadoDeteccion& resultado
) const {
    if (componente.area < m_minArea){
        return false;
    }

    // Aproximacion geometica sin mascara
    double area = componente.aspectRatio();
    double fill = componente.fillRatio();

    // Heuristica de circularidad proxy
    double circularidadProxy = 1.0 - std::abs(1.0- area);

    if (circularidadProxy >= m_minCircularidad && fill > 0.6){
        resultado.tipo = "circulo";
        resultado.confianza = circularidadProxy;
        resultado.componente = componente;
        return true;
    }

    return false;
}