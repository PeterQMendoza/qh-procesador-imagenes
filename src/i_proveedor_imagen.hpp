#pragma once

#include <memory>

#include "CImg.h"

using CImgU = cimg_library::CImg<unsigned char>;

class IProveedorImagen {
    public:
        virtual ~IProveedorImagen() = default;

        virtual std::shared_ptr<const CImgU> getImagenProcesada() const = 0;
};