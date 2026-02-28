#include "i_operacion.hpp"
#include <vector>
#include <numeric>
#include <cmath>

class EstrategiaUmbral : public IOperacion {
private:
    int  m_umbral;
    bool m_automatico;

    int calcularOtsu(const CImgU& imagen) const;

public:
    explicit EstrategiaUmbral(int umbral = 128);
    static EstrategiaUmbral automatico();

    void aplicar(CImgU& imagen) override;
};