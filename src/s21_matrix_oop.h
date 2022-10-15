#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <cmath>
#include <iostream>
#include <stdexcept>
// для арифметики
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2
// для сравнения
#define SUCCESS 1
#define FAILURE 0
#define EPS 1e-7

class S21Matrix {
private:
    int rows_, cols_;
    double **matrix_;

    void destroy_matrix();
    void memory_allocation();
    void copy_matrix(const S21Matrix &other);
public:
    S21Matrix();   //конструкторы
    S21Matrix(int rows_, int cols_);  // Параметризированный конструктор
    S21Matrix(const S21Matrix& other); // конструктор копирования
    S21Matrix(S21Matrix&& other); // конструктор переноса

    ~S21Matrix();   //деструктор

    bool eq_matrix(const S21Matrix& other);
    void sum_matrix(const S21Matrix& other);
    void sub_matrix(const S21Matrix& other);
    void mul_number(const double num);
    void mul_matrix(const S21Matrix& other);
    S21Matrix transpose();

    S21Matrix calc_complements();
    double determinant();
    S21Matrix inverse_matrix();
    void minor_matrix(S21Matrix& result, int row, int colum);

    int operator()(int i, int j);
    S21Matrix operator+(const S21Matrix& oth);
    S21Matrix& operator+=(const S21Matrix& oth);
    S21Matrix operator-(const S21Matrix& oth);
    S21Matrix& operator-=(const S21Matrix& oth);
    S21Matrix operator*(const S21Matrix& oth);
    S21Matrix& operator*=(const S21Matrix& oth);
    bool operator==(const S21Matrix& oth);
    S21Matrix& operator=(const S21Matrix& oth);

    void printer();
    void placeholder();
    void placeholder_for_determinant();
    void placeholder_for_inverse();

    int get_rows();
    int get_cols();
    void set_rows(int row);
    void set_cols(int col);
    void set_num(int i, int j, double num);

};

#endif //CPP1_S21_MATRIXPLUS_0_MATRIX_H
