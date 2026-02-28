#pragma once
#include "i_operacion.hpp"
#include "CImg.h"

using namespace cimg_library;

class EstrategiaOpening : public IOperacion {
private:
    int m_radio;

public:
    explicit EstrategiaOpening(int radio = 1);

    void aplicar(CImg<unsigned char>& imagen) override;
};