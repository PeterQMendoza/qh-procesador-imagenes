#include "visualizador.hpp"

using namespace cimg_library;

void Visualizador::mostrar(
    const CImgU& imagen,
    const std::vector<ResultadoDeteccion>& resultados
) const {
    // Convierte a RGB para poder diujar en color
    CImgU salida = imagen;

    if (imagen.spectrum() == 1){
        CImgU rgb(
            salida.width(),
            salida.height(),
            1,
            3
        );

        cimg_forXY(salida, x, y){
            unsigned char v = salida(x, y);
            rgb(x, y, 0, 0) = v;
            rgb(x, y, 0, 1) = v;
            rgb(x, y, 0, 2) = v;
        }

        salida = std::move(rgb);
        
    }

    const unsigned char rojo[] = {255, 0, 0};
    const unsigned char verde[] = {0, 255, 0};
    const unsigned char azul[] = {0, 0, 255};

    for (const auto& resultado: resultados){
        const auto& componente = resultado.componente;

        const unsigned char* color = rojo;

        if (resultado.tipo == "rectangulo") color = verde;
        if (resultado.tipo == "triangulo") color = azul;

        // Dibujar bounding box
        salida.draw_rectangle(
            componente.xmin,
            componente.ymin,
            componente.xmax,
            componente.ymax,
            color,
            1.0f,
            ~0U
        );

        // Dibujar texto
        salida.draw_text(
            componente.xmin,
            componente.ymin -15,
            resultado.tipo.c_str(),
            color,
            0,
            1,
            16
        );
    }

    salida.display("Detecciones");
}