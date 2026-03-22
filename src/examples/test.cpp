#include <iostream>
#include <Eigen/Dense>

#include "tori/nctori.h"

int main() {
    auto V = nctori::getV();
    auto U = Eigen::Matrix<double, nctori::N, nctori::N>(nctori::getU());
    std::cout << "Operator V\n" << V << std::endl;
    auto UV = (U*V.toDenseMatrix());
    auto VU = (V.toDenseMatrix()*U);
    std::cout << "UV\n" << UV << std::endl;
    std::cout << "VU\n" << VU << std::endl;
    std::cout << "Comutator\n" << VU - UV << std::endl;
    double theta = 1./static_cast<double>(nctori::N);
    std::cout << "expected output\n" << (std::exp(std::complex(0., 2.)*nctori::PI*theta) - 1.)*UV << std::endl;

    return 0;
}
