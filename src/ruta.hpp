#include <filesystem>
#include <string>

class Ruta {
    private:
        std::string m_directorio;
        std::string m_archivo;
    public:
        Ruta(const std::string& directorio, const std::string& archivo);
        std::string obtenerRuta() const;
};