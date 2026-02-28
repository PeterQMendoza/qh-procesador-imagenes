#include "procesador.hpp"
#include "ruta.hpp"

void Procesador::cargar(const std::string& directorio, const std::string& archivo){
    Ruta ruta(directorio, archivo);
    
    auto nuevaImagen = std::make_shared<CImgU>(ruta.obtenerRuta().c_str());

    std::lock_guard<std::mutex> lock(m_mutex);
    m_imagen = std::move(nuevaImagen);
}

void Procesador::agregarOperacion(std::unique_ptr<IOperacion> operacion) {
    if (!operacion){
        throw std::invalid_argument("Operacion nula");
    }
    m_operaciones.push_back(std::move(operacion));
}

void Procesador::ejecutar() {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (!m_imagen){
        throw std::runtime_error("No hay imagen cargada");
    }

    for (auto& operacion: m_operaciones){
        operacion->aplicar(*m_imagen);
    }
}

void Procesador::guardar(const std::string& ruta) const {
    std::lock_guard<std::mutex> lock(m_mutex);

    if (!m_imagen){
        throw std::runtime_error("No hay imagen para guardar");
    }

    m_imagen->save(ruta.c_str());
}

std::shared_ptr<const CImgU> Procesador::getImagenProcesada() const {
    std::lock_guard<std::mutex> lock(m_mutex);

    if (!m_imagen){
        return nullptr;
    }

    return m_imagen;
}