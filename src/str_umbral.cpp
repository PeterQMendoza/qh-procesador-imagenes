#include "str_umbral.hpp"
#include <stdexcept>
#include <vector>
#include <cmath>

EstrategiaUmbral::EstrategiaUmbral(int umbral)
    : m_umbral(umbral), m_automatico(false)
{
    if (umbral < 0 || umbral > 255)
        throw std::invalid_argument("Umbral fuera de rango [0,255]");
}

EstrategiaUmbral EstrategiaUmbral::automatico() {
    EstrategiaUmbral e;
    e.m_automatico = true;
    return e;
}

int EstrategiaUmbral::calcularOtsu(const CImgU& imagen) const {
    std::vector<int> hist(256, 0);

    cimg_forXY(imagen, x, y) {
        hist[imagen(x,y)]++;
    }

    const int total = imagen.width() * imagen.height();

    double suma = 0.0;
    for (int i = 0; i < 256; ++i)
        suma += i * hist[i];

    double sumaB = 0.0;
    int wB = 0;
    int wF = 0;

    double varMax = 0.0;
    int threshold = 0;

    for (int t = 0; t < 256; ++t) {
        wB += hist[t];
        if (wB == 0) continue;

        wF = total - wB;
        if (wF == 0) break;

        sumaB += t * hist[t];

        double mB = sumaB / wB;
        double mF = (suma - sumaB) / wF;

        double varBetween = (double)wB * wF * (mB - mF) * (mB - mF);

        if (varBetween > varMax) {
            varMax = varBetween;
            threshold = t;
        }
    }

    return threshold;
}

void EstrategiaUmbral::aplicar(CImgU& imagen) {
    if (imagen.spectrum() != 1)
        throw std::invalid_argument("La imagen debe ser monocanal para umbral");

    int t = m_automatico ? calcularOtsu(imagen) : m_umbral;

    cimg_forXY(imagen, x, y) {
        imagen(x,y) = (imagen(x,y) >= t) ? 255 : 0;
    }
}