#pragma once

#include "i_visualizador.hpp"

#include <vector>

class Visualizador final : public IVisualizador {
    public:
        void mostrar(
            const CImgU& imagen,
            const std::vector<ResultadoDeteccion>& resultados
        ) const override;
};