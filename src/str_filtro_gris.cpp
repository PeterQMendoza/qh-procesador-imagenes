#include "str_filtro_gris.hpp"

using namespace cimg_library;

void EstrategiaFiltroGris::aplicar(CImgU& imagen) {
    if (imagen.spectrum() == 3){
        CImgU gris = imagen.get_RGBtoYCbCr().get_channel(0);
        imagen = gris;
    }
}