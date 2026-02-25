#include "i_operacion.hpp"
#include <memory>
#include <vector>
#include <string>

using namespace cimg_library;

class Procesador {
    private:
        std::unique_ptr<CImg<unsigned char>> m_imagen;
        std::vector<std::unique_ptr<IOperacion>> m_operaciones;
    public:
        Procesador(const std::string& dir, const std::string& file);

        void agregarOperacion(std::unique_ptr<IOperacion> op);

        void ejecutar();

        void mostrar();

        void guardar(const char* ruta);
};