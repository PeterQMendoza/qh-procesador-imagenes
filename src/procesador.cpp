#include "procesador.hpp"
#include "ruta.hpp"

Procesador::Procesador (const std::string& dir, const std::string& file)
{
    std::unique_ptr<Ruta> ruta = std::make_unique<Ruta>(dir,file);
    m_imagen = std::make_unique<CImg<unsigned char>>(ruta->obtenerRuta().c_str());
}

void Procesador::agregarOperacion(std::unique_ptr<IOperacion> op) {
    m_operaciones.push_back(std::move(op));
}

void Procesador::ejecutar() {
    for (auto& op: m_operaciones){
        op->aplicar(*m_imagen);
    }
}

void Procesador::mostrar() {
    m_imagen->display("Imagen procesada");
}

void Procesador::guardar(const char* ruta) {
    m_imagen->save(ruta);
}