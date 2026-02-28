#pragma once

#include "i_clasificador_forma.hpp"
#include "i_proveedor_imagen.hpp"
#include "analizador_componentes.hpp"

#include <memory>
#include <cmath>
#include <vector>
#include <stdexcept>

class MotorDeteccion final {
    private:
        std::vector<std::unique_ptr<IClasificadorForma>> m_clasificadores;

    public:
        MotorDeteccion();

        void agregar(std::unique_ptr<IClasificadorForma> clasificador);

        std::vector<ResultadoDeteccion> ejecutar(
            const CImgU& binario
        );
};