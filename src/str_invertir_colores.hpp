#include "i_operacion.hpp"

class EstrategiaInvertirColores : public IOperacion {
    public:
    void aplicar(CImgU& imagen) override;
};
