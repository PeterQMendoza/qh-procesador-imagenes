#include "str_opening.hpp"

#include <stdexcept>

EstrategiaOpening::EstrategiaOpening(int radio)
    : m_radio(radio)
{
    if (radio <= 0)
        throw std::invalid_argument("El radio debe ser > 0");
}

void EstrategiaOpening::aplicar(CImg<unsigned char>& imagen)
{
    if (imagen.spectrum() != 1)
        throw std::invalid_argument("Opening requiere imagen monocanal");

    // Erosión
    CImg<unsigned char> erosionada = imagen.get_erode(m_radio);

    // Dilatación
    CImg<unsigned char> abierta = erosionada.get_dilate(m_radio);

    imagen = std::move(abierta);
}