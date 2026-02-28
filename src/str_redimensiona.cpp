#include "str_redimensiona.hpp"
#include <stdexcept>
#include <algorithm>

EstrategiaRedimensiona::EstrategiaRedimensiona(
    int maxW,
    int maxH,
    bool padding
)
    : m_maxAncho(maxW),
      m_maxAlto(maxH),
      m_usarPadding(padding)
{
    if (maxW <= 0 || maxH <= 0)
        throw std::invalid_argument("Dimensiones inválidas");
}

void EstrategiaRedimensiona::aplicar(CImgU& imagen)
{
    const int w = imagen.width();
    const int h = imagen.height();

    const double scaleW =
        static_cast<double>(m_maxAncho) / w;

    const double scaleH =
        static_cast<double>(m_maxAlto) / h;

    const double scale = std::min(scaleW, scaleH);

    const int newW = static_cast<int>(w * scale);
    const int newH = static_cast<int>(h * scale);

    imagen.resize(newW, newH, -100, -100, 3); // interpolación lineal

    if (m_usarPadding)
    {
        CImgU canvas(
            m_maxAncho,
            m_maxAlto,
            1,
            imagen.spectrum(),
            0
        );

        const int offsetX =
            (m_maxAncho - newW) / 2;

        const int offsetY =
            (m_maxAlto - newH) / 2;

        canvas.draw_image(offsetX, offsetY, imagen);

        imagen = std::move(canvas);
    }
}