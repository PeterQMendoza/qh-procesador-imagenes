#pragma once

#include "i_operacion.hpp"

#include "CImg.h"

class EstrategiaFiltroGris : public IOperacion {
    public:
        void aplicar(CImgU& imagen) override;
};
