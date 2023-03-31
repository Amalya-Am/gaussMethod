#include <iostream>
typedef double* doubleArrayPtr;

class matrix
{
public:
    matrix(int r, int c);
    ~matrix();
    void triangular_form();
    void sum_of_two_row(int row1, int row2);
    void multiply_row_with_num(int row, double num);
    void divide_row_by_num(int row, double num);
    void subtract_rows(int row1, int row2);
    int get_columns_count()const;
    int get_rows_count()const;
    friend  void gauss_method_solution(matrix& l);
private:
    doubleArrayPtr* m_matrix;
    int row_;
    int col_;
};
