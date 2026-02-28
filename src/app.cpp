#include "app.hpp"

#include "visualizador.hpp"

#include "str_filtro_gris.hpp"
#include "str_suavizado.hpp"
#include "str_invertir_colores.hpp"
#include "str_redimensiona.hpp"
#include "str_detector_borde.hpp"
#include "str_umbral.hpp"
#include "str_opening.hpp"

#include "str_clasificador_rectangulo.hpp"
#include "str_clasificador_circulo.hpp"
#include "str_clasificador_triangulo.hpp"

#include <iostream>

App::App(){
    m_procesador = std::make_unique<Procesador>();
    m_motor = std::make_unique<MotorDeteccion>();
    m_visualizador = std::make_unique<Visualizador>();

    // Agregar los clasificadores
    m_motor->agregar(std::make_unique<ClasificadorCirculo>());
    m_motor->agregar(std::make_unique<ClasificadorRectangulo>());
    m_motor->agregar(std::make_unique<ClasificadorTriangulo>());
}

App::ejecutar(){
    try {
        // 1. Configurar pipeline
        m_procesador->cargar("img", "imagen.bmp");
        
        // 2. Pipeline de procesamiento
        m_procesador->agregarOperacion(std::make_unique<EstrategiaFiltroGris>());
        m_procesador->agregarOperacion(std::make_unique<EstrategiaSuavizado>(2.0f));
        m_procesador->agregarOperacion(std::make_unique<EstrategiaUmbral>(EstrategiaUmbral::automatico()));
        // m_procesador->agregarOperacion(std::make_unique<EstrategiaUmbral>(128));
        m_procesador->agregarOperacion(std::make_unique<EstrategiaOpening>(2));
        // m_procesador->agregarOperacion(std::make_unique<EstrategiaRedimensiona>(1024,1024));
        // procesador->agregarOperacion(std::make_unique<EstrategiaDetectorBorde>());
        
        m_procesador->ejecutar();
        
        // 3. Obtener imagen binaria
        auto imagen = m_procesador->getImagenProcesada();
        if (!imagen){
            throw std::runtime_error("Imagen procesada no disponible");
        }
        
        // 4. Ejecutar deteccion morfologica
        auto resultados = m_motor->ejecutar(*imagen);
        
        // 6. Visualizar
        m_visualizador->mostrar(*imagen, resultados);

        // 7. Guardar salida
        m_procesador->guardar("img/resultado.bmp");

        std::cout << "Cantidad detectada: " << resultados.size() << std::endl;

        return EXIT_SUCCESS;
    }
    catch (const std::exception& e){
        std::cerr << "Error en la aplicacion: " << e.what() << std::endl;

        return EXIT_FAILURE;
    }
}