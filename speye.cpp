#include "speye.h"

template <typename T>
IGL_INLINE void igl::speye(const int m, const int n, Eigen::SparseMatrix<T> & I)
{
  // size of diagonal
  int d = (m<n?m:n);
  I = Eigen::SparseMatrix<T>(m,n);
  I.reserve(d);
  for(int i = 0;i<d;i++)
  {
    I.insert(i,i) = 1.0;
  }
  I.finalize();
}

template <typename T>
IGL_INLINE void igl::speye(const int n, Eigen::SparseMatrix<T> & I)
{
  return igl::speye(n,n,I);
}

#ifndef IGL_HEADER_ONLY
// Explicit template specialization
#endif