#include "str_suavizado.hpp"

#include <stdexcept>

EstrategiaSuavizado::EstrategiaSuavizado(float sigma)
    : m_sigma(sigma) {}

void EstrategiaSuavizado::aplicar(CImg<unsigned char>& imagen) {
    if (imagen.is_empty())
        throw std::runtime_error("Imagen no disponible");

    // Suavizado Gaussiano in-place
    imagen.blur(m_sigma);
}