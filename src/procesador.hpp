#include "i_operacion.hpp"
#include "i_proveedor_imagen.hpp"
#include "CImg.h"

#include <memory>
#include <vector>
#include <string>
#include <mutex>


class Procesador final : public IProveedorImagen {
    private:
        mutable std::mutex m_mutex;
        std::shared_ptr<CImgU> m_imagen;
        std::vector<std::unique_ptr<IOperacion>> m_operaciones;
    public:
        Procesador() = default;
        ~Procesador() override = default;

        void cargar(const std::string& directorio, const std::string& archivo);

        void agregarOperacion(std::unique_ptr<IOperacion> operacion);

        void ejecutar();

        void guardar(const std::string& ruta) const;

        std::shared_ptr<const CImgU> getImagenProcesada() const override;
};