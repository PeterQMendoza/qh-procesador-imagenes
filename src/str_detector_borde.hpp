#include "i_operacion.hpp"

class EstrategiaDetectorBorde : public IOperacion {
    public:
        void aplicar(CImgU& imagen) override;
};