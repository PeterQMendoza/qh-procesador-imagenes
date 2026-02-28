#include "detector.hpp"

MotorDeteccion::MotorDeteccion(){
}

void MotorDeteccion::agregar(std::unique_ptr<IClasificadorForma> clasificador){
    if (!clasificador){
        throw std::invalid_argument("Clasificador nulo");
    }
    m_clasificadores.push_back(std::move(clasificador));
}

std::vector<ResultadoDeteccion> MotorDeteccion::ejecutar(
    const CImgU& binario
) {
    if (binario.spectrum() != 1){
        throw std::invalid_argument("La imagen debe ser monocanal y binaria");
    }

    std::vector<ResultadoDeteccion> resultados;

    AnalizadorComponentes analizador;
    auto componentes = analizador.extraer(binario);

    for (const auto& componente : componentes){
        if (componente.area < 150) continue;

        if (componente.perimetro == 0) continue;

        const double  circularidad = 4.0 * M_PI * static_cast<double>(componente.area) / (static_cast<double>(componente.perimetro) * static_cast<double>(componente.perimetro));

        for (const auto& clasificador : m_clasificadores){
            ResultadoDeteccion resultado;
            if (clasificador->clasificar(componente, resultado)){
                // resultado.circularidad = circularidad;
                resultados.push_back(resultado);
            }
        }
    }
    return resultados;
}