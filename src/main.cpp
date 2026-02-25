#include "procesador.hpp"
#include "str_filtro_gris.hpp"
#include "str_invertir_colores.hpp"
#include "str_redimensiona.hpp"
#include "str_detector_borde.hpp"


#ifdef _WIN32
    #define OS "Windows"
#elif __APPLE__
    #define OS "macOS"
#elif __linux__
    #define OS "Linux"
#else
    #define OS "Desconocido"
#endif

int main() {
    std::unique_ptr<Procesador> procesador = std::make_unique<Procesador>("img", "imagen.bmp");

    // procesador->agregarOperacion(std::make_unique<EstrategiaFiltroGris>());
    // procesador->agregarOperacion(std::make_unique<EstrategiaInvertirColores>());
    // procesador->agregarOperacion(std::make_unique<EstrategiaRedimensiona>(128,128));
    procesador->agregarOperacion(std::make_unique<EstrategiaDetectorBorde>());

    procesador->ejecutar();
    procesador->mostrar();
    procesador->guardar("img/resultado.bmp");

    return 0;
}