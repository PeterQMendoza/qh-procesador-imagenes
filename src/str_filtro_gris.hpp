#include "i_operacion.hpp"

class EstrategiaFiltroGris : public IOperacion {
    public:
        void aplicar(CImg<unsigned char>& imagen) override;
};
