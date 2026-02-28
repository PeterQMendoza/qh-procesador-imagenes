#include "analizador_componentes.hpp"

#include <stdexcept>

std::vector<Componente> AnalizadorComponentes::extraer (const CImgU& binario){
    if (binario.spectrum() != 1){
        throw std::invalid_argument("Imagen debe ser monocanal binaria");
    }

    CImg<int> etiquetas = binario.get_label();
    const int nEtiquetas = etiquetas.max();

    std::vector<Componente> componentes(nEtiquetas +1);

    // Inicializacion
    for (int i=1; i <= nEtiquetas; ++i){
        componentes[i].etiqueta = i;
        componentes[i].area = 0;
    }

    // Paso unico
    cimg_forXY(etiquetas, x, y){
        int L = etiquetas(x, y);
        if (L == 0) continue;

        auto& com = componentes[L];
        
        com.area++;

        com.xmin = std::min(com.xmin, x);
        com.ymin = std::min(com.ymin, y);
        com.xmax = std::max(com.xmax, x);
        com.ymax = std::max(com.ymax, y);

        com.perimetro += calcularPerimetroPixel(binario, x, y);

    }

    // Eliminar indice 0
    componentes.erase(componentes.begin());

    return componentes;
}

int AnalizadorComponentes::calcularPerimetroPixel(
    const CImgU& img,
    int x,
    int y
) const {
    int p = 0;

    const int w = img.width();
    const int h = img.height();

    if (x == 0 || img(x-1,y) == 0) p++;
    if (x == w-1 || img(x+1,y) == 0) p++;
    if (y == 0 || img(x,y-1) == 0) p++;
    if (y == h-1 || img(x,y+1) == 0) p++;

    return p;
}