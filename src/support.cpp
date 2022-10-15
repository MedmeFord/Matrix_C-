#include "s21_matrix_oop.h"

/**
 * @brief Заполняет по возрастанию
 */
void S21Matrix::placeholder() {
    int count = 0;
    if (this->matrix_) {
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->cols_; j++) {
                this->matrix_[i][j] = ++count;
            }
        }
    }
}
void S21Matrix::placeholder_for_determinant() {
    int count = 0;
    if (this->matrix_) {
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->cols_; j++) {
                this->matrix_[i][j] = ++count;
            }
        }
    }
    if (rows_ >= 2 && cols_ >= 2) {
        this->matrix_[1][1] = 66;
        this->matrix_[2][2] = 119;
    }
}
void S21Matrix::placeholder_for_inverse() {
    int array[16] = {2, 5, 7, 1, 6, 3, 4, 1, 5, -2, -3, 1, 11, 1, 1, 1};
    if (this->matrix_) {
        for (int i = 0, count = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->cols_; j++, count++) {
                this->matrix_[i][j] = array[count];
            }
        }
    }
}

int S21Matrix::get_rows() { return this->rows_; }

int S21Matrix::get_cols() { return this->cols_; }

void S21Matrix::set_rows(int row) {
    if (row <= 0) {
        throw std::exception();
    } else {
        S21Matrix copy(*this);
        this->destroy_matrix();
        this->rows_ = row;
        this->cols_ = copy.cols_;
        this->memory_allocation();

        for (int i = 0; i < copy.rows_ && i < this->rows_; i++) {
            for (int j = 0; j < copy.cols_; j++) {
                this->matrix_[i][j] = copy.matrix_[i][j];
            }
        }
    }
}

void S21Matrix::set_cols(int col) {
    if (col <= 0) {
        throw std::exception();
    } else {
        S21Matrix copy(*this);
        this->destroy_matrix();
        this->rows_ = copy.rows_;
        this->cols_ = col;
        this->memory_allocation();

        for (int i = 0; i < copy.rows_; i++) {
            for (int j = 0; j < copy.cols_ && j < this->cols_; j++) {
                this->matrix_[i][j] = copy.matrix_[i][j];
            }
        }
    }
}

void S21Matrix::memory_allocation() {
    if (this->rows_ <= 0 || this->cols_ <= 0) {
        throw std::out_of_range("Error: out of range");
    }
    this->matrix_ = new double *[rows_]();
    for (int i = 0; i < rows_; i++) {
        this->matrix_[i] = new double[cols_]();
    }
}

void S21Matrix::destroy_matrix() {
    if (this->matrix_) {
        for (int i = 0; i < this->rows_; i++) {
            delete this->matrix_[i];
        }
        delete this->matrix_;
        this->matrix_ = 0;
    }
}


void S21Matrix::set_num(int i, int j, double num) {
    matrix_[i][j] = num;
}

void S21Matrix::printer() {
    printf("\n");
    if (this->matrix_) {
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->cols_; j++) {
                printf("%lf ", this->matrix_[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n");
}
