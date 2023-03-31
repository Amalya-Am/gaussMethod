#include <iostream>
#include <unistd.h>
#include "matrix.hpp"
typedef double* doubleArrayPtr;


matrix::matrix(int r, int c) 
        :m_matrix(nullptr) 
        ,row_(r)
        ,col_(c)
{
    m_matrix = new doubleArrayPtr[row_];
    for (int i = 0; i < row_; ++i){
        m_matrix[i]=new double [col_];
    }
    for (int i = 0; i < row_; ++i) {     
        for (int j = 0; j < col_; ++j) {
            if (::isatty(STDIN_FILENO)) {
            }
            std::cin >> m_matrix[i][j];
	}
    }
}

matrix::~matrix()
{
    for (int i = 0; i < row_; ++i) {
        delete m_matrix[i];
    }
    delete m_matrix;
}
		
void
matrix::triangular_form()
{
    for (int j = 0; j < row_; ++j) {
        double temp2 = m_matrix[j][j];
        for (int i = j + 1; i < row_; ++i) {        
            double temp1 = m_matrix[i][j];
            multiply_row_with_num(i, temp2);
            multiply_row_with_num(j, temp1);
            subtract_rows(i, j);
            divide_row_by_num(j,temp1);
        }
    }
    
}

void 
matrix::sum_of_two_row(int row1, int row2)
{
    for (int j = 0; j < col_; ++j) {
        m_matrix[row1][j] = m_matrix[row1][j] + m_matrix[row2][j];
    }
}

void 
matrix::multiply_row_with_num(int row, double num)
{
    for (int j = 0; j < col_; ++j) {
        m_matrix[row][j] = m_matrix[row][j] * num;
    }
}
    
void  
matrix::divide_row_by_num(int row, double num)
{
    for (int j = 0; j < col_; ++j) {
        m_matrix[row][j] = m_matrix[row][j] / num;
    }
}

void 
matrix::subtract_rows(int row1, int row2)
{
    for (int j = 0; j < col_; ++j) {
        m_matrix[row1][j] = m_matrix[row1][j] - m_matrix[row2][j];
    }
}
    
int matrix::get_rows_count()const
{
    return row_;
}
    
int 
matrix::get_columns_count()const
{
    return col_;
}

