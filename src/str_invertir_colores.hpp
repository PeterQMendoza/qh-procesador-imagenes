#include "i_operacion.hpp"

class EstrategiaInvertirColores : public IOperacion {
    public:
    void aplicar(CImg<unsigned char>& imagen) override;
};
