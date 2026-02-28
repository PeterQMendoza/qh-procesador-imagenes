#pragma once

#include "procesador.hpp"
#include "detector.hpp"
#include "i_visualizador.hpp"

#include <memory>
#include <vector>

class App {
    private:
        std::unique_ptr<Procesador> m_procesador;
        std::unique_ptr<MotorDeteccion> m_motor;
        std::unique_ptr<IVisualizador> m_visualizador;

    public:
        App();
        int ejecutar();
};