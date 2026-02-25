#include "i_operacion.hpp"

class EstrategiaDetectorBorde : public IOperacion {
    public:
        void aplicar(CImg<unsigned char>& imagen) override;
};