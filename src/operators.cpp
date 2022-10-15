#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix &oth) {
    S21Matrix result(*this);
    result.sum_matrix(oth);
    return result;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &oth) {
    this->sum_matrix(oth);
    return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix &oth) {
    S21Matrix result(*this);
    result.sub_matrix(oth);
    return result;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &oth) {
    this->sub_matrix(oth);
    return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix &oth) {
    S21Matrix result(*this);
    result.mul_matrix(oth);
    return result;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &oth) {
    this->mul_matrix(oth);
    return *this;
}

bool S21Matrix::operator==(const S21Matrix &oth) { return this->eq_matrix(oth); }

S21Matrix &S21Matrix::operator=(const S21Matrix &oth) {
    if (this->matrix_) {
        for (int i = 0; i < this->rows_; i++) {
            delete this->matrix_[i];
        }
        delete this->matrix_;
    }
    this->copy_matrix(oth);
    return *this;
}
