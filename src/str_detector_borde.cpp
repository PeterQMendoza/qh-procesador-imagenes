#include "str_detector_borde.hpp"

void EstrategiaDetectorBorde::aplicar(CImgU& imagen){
    CImgU edge(imagen.width(), imagen.height(),1,1,0);
    const int kernelX[3][3]={{-1,0,1}, {-2,0,2},{-1,0,1}};
    const int kernelY[3][3]={{-1,-2,-1}, {0,0,0},{1,2,1}};
    for (int y=1; y<imagen.height()-1; y++){
        for (int x=1; x<imagen.width()-1; x++){
            int gx=0, gy=0;
            for (int i=-1; i<=1; i++){
                for (int j=-1; j<=1; j++){
                    gx += imagen(x+i, y+j)*kernelX[i+1][j+1];
                    gy += imagen(x+i, y+j)*kernelY[i+1][j+1];
                }
            }

            int g = (int)sqrt(gx*gx+gy*gy);
            edge(x,y) = (g>255)?255:g;
        }
    }
    edge.display();
}