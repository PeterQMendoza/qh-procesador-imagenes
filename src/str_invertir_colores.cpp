#include "str_invertir_colores.hpp"

void EstrategiaInvertirColores::aplicar(CImg<unsigned char>& imagen) {
    imagen.invert();
}