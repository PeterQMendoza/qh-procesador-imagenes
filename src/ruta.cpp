#include "ruta.hpp"

Ruta::Ruta(const std::string& directorio, const std::string& archivo)
:m_directorio(directorio), m_archivo(archivo){

}

std::string Ruta::obtenerRuta() const {
    std::filesystem::path ruta = std::filesystem::current_path() / m_directorio / m_archivo;
    return ruta.string();
}