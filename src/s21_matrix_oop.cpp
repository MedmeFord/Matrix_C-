#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
    this->rows_ = 3;
    this->cols_ = 3;
    this->matrix_ = new double *[rows_]();
    for (int i = 0; i < rows_; i++) {
        this->matrix_[i] = new double[cols_]();
    }
}


S21Matrix::S21Matrix(int rows_, int cols_) {
    if (rows_ >= 1 && cols_ >= 1) {
        this->rows_ = rows_;
        this->cols_ = cols_;
        this->matrix_ = new double *[rows_]();
        for (int i = 0; i < rows_; i++) {
            this->matrix_[i] = new double[cols_]();
        }

    } else {
        this->rows_ = 0;
        this->cols_ = 0;
        this->matrix_ = nullptr;
        throw std::exception();
    }
}

S21Matrix::S21Matrix(const S21Matrix &other)
        : rows_(other.rows_), cols_(other.cols_) {
    this->matrix_ = new double *[rows_]();
    for (int i = 0; i < rows_; i++) {
        this->matrix_[i] = new double[cols_]();
    }
    for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->cols_; j++) {
            this->matrix_[i][j] = other.matrix_[i][j];
        }
    }
}

S21Matrix::S21Matrix(S21Matrix &&other) {
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    this->matrix_ = other.matrix_;
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
    this->destroy_matrix();
}

void S21Matrix::sum_matrix(const S21Matrix &other) {
    if (other.matrix_ && this->rows_ >= 1 && this->cols_ >= 1) {
        if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
            for (int i = 0; i < this->rows_; i++) {
                for (int j = 0; j < this->cols_; j++) {
                    this->matrix_[i][j] =
                            this->matrix_[i][j] + other.matrix_[i][j];
                }
            }
        } else {
            throw std::exception();
        }
    } else {
        throw std::exception();
    }
}

void S21Matrix::sub_matrix(const S21Matrix &other) {
    if (other.matrix_ && this->rows_ >= 1 && this->cols_ >= 1) {
        if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
            for (int i = 0; i < this->rows_; i++) {
                for (int j = 0; j < this->cols_; j++) {
                    this->matrix_[i][j] =
                            this->matrix_[i][j] - other.matrix_[i][j];
                }
            }
        } else {
            throw std::exception();
        }
    } else {
        throw std::exception();
    }
}

void S21Matrix::mul_number(const double num) {
    if (this->rows_ >= 1 && this->cols_ >= 1) {
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->cols_; j++) {
                this->matrix_[i][j] = this->matrix_[i][j] * num;
            }
        }
    } else {
        throw std::exception();
    }
}

void S21Matrix::mul_matrix(const S21Matrix &other) {
    if (other.rows_ >= 1 && other.cols_ >= 1 && this->rows_ >= 1 &&
        this->cols_ >= 1) {
        if (this->rows_ == other.cols_ && this->cols_ == other.rows_) {
            double result[rows_][other.cols_];
            for (int i = 0; i < this->rows_; i++) {
                for (int j = 0; j < this->cols_; j++) {
                    result[i][j] = 0;
                    for (int k = 0; k < this->cols_; k++) {
                        result[i][j] +=
                                this->matrix_[i][k] * other.matrix_[k][j];
                    }
                }
            }
            for (int i = 0; i < this->rows_; i++) {
                for (int j = 0; j < this->cols_; j++) {
                    this->matrix_[i][j] = result[i][j];
                }
            }
        } else {
            throw std::exception();
        }
    } else {
        throw std::exception();
    }
}

void S21Matrix::copy_matrix(const S21Matrix &other) {
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    this->matrix_ = new double *[rows_];
    for (int i = 0; i < rows_; i++) {
        this->matrix_[i] = new double[cols_];
    }
    for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->cols_; j++) {
            this->matrix_[i][j] = other.matrix_[i][j];
        }
    }
}

S21Matrix S21Matrix::transpose() {
    S21Matrix result((S21Matrix &)*this);
    if (this->rows_ >= 1 && this->cols_ >= 1) {
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->cols_; j++) {
                this->matrix_[j][i] = result.matrix_[i][j];
            }
        }
    } else {
        throw std::exception();
    }

    return *this;
}

double S21Matrix::determinant() {
    double result = 0;
    if (this->rows_ >= 1 && this->cols_ >= 1) {
        if (this->rows_ == this->cols_) {
            if (this->rows_ == 1) {
                result = this->matrix_[0][0];
            } else if (this->rows_ == 2) {
                result = this->matrix_[0][0] * this->matrix_[1][1] -
                         this->matrix_[0][1] * this->matrix_[1][0];
            } else {
                double determinant = 0;
                for (int j = 0; j < this->cols_; j++) {
                    S21Matrix matrix_minor(rows_ - 1, cols_ - 1);
                    minor_matrix(matrix_minor, 0, j);
                    result = matrix_minor.determinant();
                    determinant +=
                            this->matrix_[0][j] * pow(-1, j) * result;
                }
                result = determinant;
            }
        } else {
            throw std::exception();
        }
    } else {
        throw std::exception();
    }

    return result;
}

void S21Matrix::minor_matrix(S21Matrix& result, int row, int column) {
    for (int i = 0, new_i = 0; i < this->rows_; i++) {
        if (i == row) continue;
        for (int j = 0, new_j = 0; j < this->cols_; j++) {
            if (j == column) continue;
            result.matrix_[new_i][new_j] = this->matrix_[i][j];
            new_j++;
        }
        new_i++;
    }
}

S21Matrix S21Matrix::calc_complements() {
    S21Matrix result(this->cols_, this->rows_);
    if (this->rows_ >= 1 && this->cols_ >= 1) {
        if (this->rows_ == this->cols_) {
            for (int i = 0; i < this->rows_; i++) {
                for (int j = 0; j < this->cols_; j++) {
                    S21Matrix m_for_determinant(this->cols_ - 1,
                                                this->rows_ - 1);
                    double determinant = 0;
                    this->minor_matrix(m_for_determinant, i, j);
                    determinant = m_for_determinant.determinant();
                    result.matrix_[i][j] = determinant * pow(-1, i + j);
                }
            }
        } else {
            throw std::exception();
        }
    } else {
        throw std::exception();
    }
    return result;
}

S21Matrix S21Matrix::inverse_matrix() {
    S21Matrix tmp(this->cols_, this->rows_);
    try {
        if (this->rows_ >= 1 && this->cols_ >= 1) {
            if (this->rows_ == this->cols_) {
                double determinant = this->determinant();
                if (fabs(determinant) <= EPS) {
                    throw std::exception();
                } else {
                    tmp = this->calc_complements();
                    tmp = tmp.transpose();
                    tmp.mul_number(1. / determinant);
                }
            } else {
                throw std::exception();
            }
        } else {
            throw std::exception();
        }
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    return tmp;
}

bool S21Matrix::eq_matrix(const S21Matrix &other) {
    bool flag = SUCCESS;
    if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->cols_; j++) {
                if (fabs(this->matrix_[i][j] - other.matrix_[i][j]) > EPS) {
                    flag = FAILURE;
                }
            }
        }
    } else {
        flag = FAILURE;
    }
    return flag;
}

int S21Matrix::operator()(int i, int j) {
    try {
        if (i >= rows_ || j >= cols_ || i < 0 || j < 0) {
            throw std::out_of_range("Incorrect input, index is out of range");
        }
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
    }
    return this->matrix_[i][j];
}
