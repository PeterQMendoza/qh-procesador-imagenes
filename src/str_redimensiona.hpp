#pragma once

#include "i_operacion.hpp"

class EstrategiaRedimensiona : public IOperacion {
    private:
        int m_maxAncho;
        int m_maxAlto;
        bool m_usarPadding;
    public:
        EstrategiaRedimensiona(int maxW, int maxH, bool padding = false);
        void aplicar(CImgU& imagen) override;
};