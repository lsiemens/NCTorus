/// Finite approximation to the non-commuting torus
///
/// The mathematics is covered in the link arxiv.org/pdf/hep-th/9804120
///

#ifndef NCTORUS_H
#define NCTORUS_H

#include <numbers>
#include <complex>
#include <Eigen/Dense>

namespace nctori {

constexpr double PI = std::numbers::pi_v<double>;
constexpr size_t N = 10;

inline Eigen::DiagonalMatrix<std::complex<double>, N> getV() {
    double theta = 1./static_cast<double>(N);
    Eigen::Matrix<std::complex<double>, N, 1> V;
    for (size_t i = 0; i < N; i++) {
        V(i, 0) = std::exp(std::complex(0., 2.)*PI*static_cast<double>(i)*theta);
    }
    return V.asDiagonal();
}

inline Eigen::PermutationMatrix<N> getU() {
    Eigen::PermutationMatrix<N> U;
    for (size_t i = 0; i < N; i++) {
        U.indices()[i] = (static_cast<int>(i) + 1) % N;
    }
    return U;
}

} // namespace nctori

#endif
