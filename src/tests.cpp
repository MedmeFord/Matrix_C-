#include <gtest/gtest.h>

#include "s21_matrix_oop.h"
// using namespace std;
// #include <gtest/gtest.h>
// #include "matrix_cpp.h"

TEST(test_eq_matrix1, test1) {
S21Matrix harry(3, 3);
S21Matrix billi(3, 3);
harry.placeholder();
billi.placeholder();
if (harry == billi) {
EXPECT_EQ(1, 1);
ASSERT_TRUE(1);
}
}

TEST(test_eq_assignment, test1) {
S21Matrix harry(3, 3);
S21Matrix billi(3, 3);
harry.placeholder();
billi.placeholder();
harry = billi + harry;
if (harry == billi + billi) {
EXPECT_EQ(1, 1);
}
ASSERT_TRUE(harry == billi + billi);
// matrix2.plase
// EXPECT_EQ(matrix1.eq_matrix(matrix2), 1);
}

TEST(test_transpose, test1) {
S21Matrix sarah(3, 3);
sarah.placeholder();
sarah.printer();
sarah.transpose();
sarah.printer();
// matrix2.plase
// EXPECT_EQ(matrix1.eq_matrix(matrix2), 1);
}

TEST(test_base, test1) { S21Matrix sarah(); }

TEST(test_transportin, test1) {
S21Matrix bob();

S21Matrix sarah();
}

TEST(test_simple_tests, test1) {
S21Matrix margaret(5, 5);
margaret.placeholder();
margaret.printer();
S21Matrix bob(margaret);
bob.mul_number(5);
// margaret.printer();
S21Matrix c = margaret * bob;
bob.printer();
c.printer();
S21Matrix max((S21Matrix &&) c);
// S21Matrix jei(move(c) );
S21Matrix lui((S21Matrix &)max);
max.printer();
lui.printer();
// printf("\n%d", lui.rows_);
// printf("\n%d", lui.cols_);
if (lui.eq_matrix(max)) {
printf("1111");
} else {
printf("\n no");
}
if (lui == max) {
printf("1111");
} else {
printf("\n no");
}
c.printer();
}

TEST(test_another_simple_tests, test1) {
S21Matrix margaret(5, 5);
margaret.placeholder();
margaret.printer();
S21Matrix bob(margaret);
bob = bob + margaret + margaret;
bob.printer();
}


TEST(test_determinant, test1) {
S21Matrix sarah(3, 3);
sarah.placeholder_for_determinant();
sarah.determinant();
}

TEST(higher_test_for_determinant, test1) {
S21Matrix sarah(4, 4);
sarah.placeholder();
printf("\n%lf", sarah.determinant());
sarah.printer();
}

TEST(higher_test_for_calcomplements, test1) {
S21Matrix sarah(4, 4);
sarah.placeholder();
sarah = sarah.calc_complements();
sarah.printer();
}

TEST(high_test_for_calcomplements, test1) {
S21Matrix sarah(4, 4);
sarah.placeholder_for_inverse();
sarah.printer();
sarah = sarah.inverse_matrix();
sarah.printer();
}

TEST(test_index_operator, test1) {
S21Matrix sarah(4, 4);
sarah.placeholder_for_inverse();
printf("\n%d", sarah(3, 0));
}

TEST(test_getters, test1) {
S21Matrix sarah(4, 4);
sarah.placeholder_for_inverse();
printf("\n%d", sarah.get_rows());
printf("\n%d", sarah.get_cols());
}

TEST(test_void, test1) {
S21Matrix sarah(4, 4);
sarah.printer();
}

TEST(test_set_rows, test1) {
S21Matrix sarah(4, 4);
sarah.placeholder_for_inverse();
sarah.set_rows(8);
sarah.set_cols(2);
sarah.printer();
}

TEST(test_eq_matrix, test1) {
S21Matrix matrix1(3, 3);
S21Matrix matrix2(3, 3);
matrix2.set_num(0, 0, 1);
EXPECT_EQ(matrix1.eq_matrix(matrix2), false);
}

TEST(det, test4) {
S21Matrix matrix(2, 2);
S21Matrix matrix1(1, 1);
matrix.set_num(0, 0, 1);
matrix.set_num(0, 1, 2);
matrix.set_num(1, 0, 3);
matrix.set_num(1, 1, 4);

double a = matrix.determinant();
EXPECT_EQ(a, -2);
}

TEST(calc, test5) {
S21Matrix matrix(2, 2);
S21Matrix matrix1(2, 2);
S21Matrix matrix_res(2, 2);
matrix.set_num(0, 0, 1);
matrix.set_num(0, 1, 2);
matrix.set_num(1, 0, 3);
matrix.set_num(1, 1, 4);

matrix_res.set_num(0, 0, 4);
matrix_res.set_num(0, 1, -3);
matrix_res.set_num(1, 0, -2);
matrix_res.set_num(1, 1, 1);

matrix1 = matrix.calc_complements();
int rows = matrix.get_rows();
int cols = matrix.get_cols();
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
EXPECT_EQ(matrix1(i, j), matrix_res(i, j));
}
}
}
//
TEST(inverse, test6) {
//    std::cout << "Hello, World!" << std::endl;
S21Matrix matrix(2, 2);
S21Matrix matrix_res(2, 2);
S21Matrix matrix1(2, 2);
matrix.set_num(0, 0, 1);
matrix.set_num(0, 1, 2);
matrix.set_num(1, 0, 3);
matrix.set_num(1, 1, 4);
matrix_res.set_num(0, 0, -2);
matrix_res.set_num(0, 1, 1);
matrix_res.set_num(1, 0, 1.5);
matrix_res.set_num(1, 1, -0.5);
matrix1 = matrix.inverse_matrix();
int rows = matrix.get_rows();
int cols = matrix.get_cols();
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
EXPECT_EQ(matrix1(i, j), matrix_res(i, j));
}
}
}

TEST(get_cols, test7) {
S21Matrix matrix(2, 2);
int a = matrix.get_cols();
EXPECT_EQ(a, 2);
}
TEST(get_rows, test8) {
S21Matrix matrix(2, 2);
int a = matrix.get_rows();
EXPECT_EQ(a, 2);
}

TEST(operator, test15) {
S21Matrix matrix3(2, 2);
S21Matrix matrix_res(2, 2);
S21Matrix matrix1(2, 2);
matrix1.placeholder();
matrix1.set_num(1, 1, 4);
matrix_res.set_num(0, 0, 8);
matrix_res.set_num(0, 1, 12);
matrix_res.set_num(1, 0, 18);
matrix_res.set_num(1, 1, 26);
matrix1.printer();
matrix3 = matrix1 * matrix1;
matrix3.printer();
matrix3 = matrix1 + matrix3;
matrix3.printer();
matrix3.mul_number(1);
int rows = matrix1.get_rows();
int cols = matrix1.get_cols();
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
EXPECT_EQ(matrix3(i, j), matrix_res(i, j));
}
}
matrix3.printer();
}

TEST(test_mult_new, test8) {
S21Matrix matrix1(2, 2);
matrix1.placeholder();
matrix1.set_num(1, 1, 4);
matrix1.printer();
matrix1 = matrix1 * matrix1;
matrix1.printer();
}
TEST(test_operators_new, test8) {
S21Matrix matrix1(2, 2);
matrix1.placeholder();
matrix1.set_num(1, 1, 4);
matrix1.printer();
matrix1 *= matrix1 * matrix1;
matrix1 += matrix1 - matrix1;
matrix1 -= matrix1;
matrix1.printer();
}
TEST(test_destroy, test8) {
S21Matrix matrix1(2, 2);
}
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}