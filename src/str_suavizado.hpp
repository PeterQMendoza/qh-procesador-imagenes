#pragma once

#include "i_operacion.hpp"

#include "CImg.h"

using namespace cimg_library;

class EstrategiaSuavizado : public IOperacion {
private:
    float m_sigma;   // Intensidad del suavizado gaussiano

public:
    explicit EstrategiaSuavizado(float sigma = 1.5f);

    void aplicar(CImg<unsigned char>& imagen) override;
};