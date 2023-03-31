#include <iostream>
#include "matrix.hpp"
typedef double* doubleArrayPtr;

void
gauss_method_solution(matrix& b)
{
    int end = b.get_rows_count();
    doubleArrayPtr result = new double [end];
    for (int i = end-1; i >= 0; --i) {
        double sum = 0;
        for (int j = i+1;j < end; ++j){
            sum += b.m_matrix[i][j] * result[j];
        }
        result[i] = (b.m_matrix[i][end] - sum) / b.m_matrix[i][i];
    }
    for (int i = 0; i < end; ++i) {
        std::cout << result[i] << " ";
    }
}

