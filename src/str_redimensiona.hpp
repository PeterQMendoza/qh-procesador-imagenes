#include "i_operacion.hpp"

class EstrategiaRedimensiona : public IOperacion {
    private:
        int m_ancho, m_alto;
    public:
        EstrategiaRedimensiona(int w, int h);
        void aplicar(CImg<unsigned char>& imagen) override;
};