#include "str_redimensiona.hpp"

EstrategiaRedimensiona::EstrategiaRedimensiona(int w, int h) : m_ancho(w), m_alto(h) {}

void EstrategiaRedimensiona::aplicar(CImg<unsigned char>& imagen) {
    imagen.resize(m_ancho, m_alto);
}