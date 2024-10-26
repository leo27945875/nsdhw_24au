#pragma once

#include<cstddef>

class Matrix {
 private:
  size_t m_nrow, m_ncol;
  double* data;

 public:
  Matrix(size_t nrow, size_t ncol);
  Matrix(const Matrix& other);
  ~Matrix();

  size_t nrow() const;
  size_t ncol() const;
  double* getData() const;

  Matrix& operator=(const Matrix& other);

  double& operator()(size_t i, size_t j);
  const double& operator()(size_t i, size_t j) const;
  bool operator==(const Matrix &m) const;
};

Matrix multiply_naive(const Matrix& A, const Matrix& B);
Matrix multiply_tile(const Matrix& A, const Matrix& B, size_t tile_size);
Matrix multiply_mkl(const Matrix& A, const Matrix& B);