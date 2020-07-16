#include <iostream>

using namespace std;

class Matrix {
private:
    int **matrix_;
    size_t rows_;
    size_t columns_;

    int **allocate(size_t rows, size_t columns) {
        int **p = nullptr;
        if (rows != 0 && columns != 0) {
            matrix_ = new int *[rows];
            for (size_t i = 0; i < rows; ++i) {
                matrix_[i] = new int[columns];
            }
        }
        return p;
    }

public:
    // Default Constructor
    Matrix() : Matrix(0, 0) {
    }

    // Constructor with parameters
    Matrix(size_t rows, size_t columns) : rows_{rows}, columns_{columns} {
        srand(time(NULL));
        matrix_ = new int *[rows_];

        for (int i = 0; i < rows_; i++)
            matrix_[i] = new int[columns_];

        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < columns_; j++) {
                matrix_[i][j] = rand() % 10;
            }
        }

    }

    Matrix &operator=(const Matrix &matrix) {
        rows_ = matrix.rows();
        columns_ = matrix.columns();

        matrix_ = new int *[rows()];

        for (int i = 0; i < rows(); i++)
            matrix_[i] = new int[columns()];

        for (int i = 0; i < rows(); i++) {
            for (int j = 0; j < columns(); j++) {
                matrix_[i][j] = matrix.matrix_[i][j];
            }
        }
        return *this;
    }

    // Copy constructor
    Matrix(const Matrix &matrix) {
        *this = matrix;
    }

    // Destructor
    ~Matrix() {
        if (matrix_) {
            for (int i = 0; i < this->rows(); ++i) {
                delete[] matrix_[i];
            }
        }
    }

    [[nodiscard]] size_t rows() const {
        return rows_;
    }

    [[nodiscard]] std::size_t columns() const {
        return columns_;
    }

    [[nodiscard]] int at(size_t row, size_t column) const {
        cout << matrix_[row][column] << endl;
        return matrix_[row][column];
    }

    [[maybe_unused]] void set(size_t row, size_t column, int value) {
        if (row < rows() && column < columns()) {
            matrix_[row][column] = value;
        } else {
            return;
        }
    }

    [[nodiscard]] int trace() const {
        if (is_square_matrix()) {
            int trace = 0;
            for (int i = 0; i < rows(); ++i) {
                for (int j = 0; j < columns(); ++j) {
                    if (i == j) {
                        trace += matrix_[i][j];
                    }
                }
            }
            return trace;
        } else {
            return -1;
        }
    }

    [[nodiscard]] bool is_square_matrix() const {
        return columns() == rows();
    }

    [[nodiscard]] bool are_same_dim(const Matrix &matrix) const {
        return rows() == rows() && columns() == columns();
    }

    friend ostream &operator<<(ostream &os, const Matrix &matrix);

    void operator+=(const Matrix &matrix) {
        if (are_same_dim(matrix)) {
            for (int i = 0; i < rows(); ++i) {
                for (int j = 0; j < columns(); ++j) {
                    matrix_[i][j] += matrix.matrix_[i][j];
                }
            }
        } else {
            throw "Cannot add a matrix with another dimension";
        }
    }
};

ostream &operator<<(ostream &os, const Matrix &matrix) {
    for (int i = 0; i < matrix.rows(); i++) {
        for (int j = 0; j < matrix.columns(); j++) {
            os << matrix.matrix_[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

bool same_dim(const Matrix &m1, const Matrix &m2) {
    return m1.rows() == m2.rows() && m1.columns() == m2.columns();
}

Matrix operator+(const Matrix &m1, const Matrix &m2) {
    if (same_dim(m1, m2)) {
        Matrix temp(m1);
        temp += m2;
        return temp;
    } else {
        throw "Cannot add matrices with different dimensions";
    }
}

int main() {
    Matrix m1(3, 3);
    Matrix m2(3, 3);
    cout << "m1: " << endl;
    cout << m1 << endl;
    cout << "m2: " << endl;
    cout << m2 << endl;
    Matrix m3;
    m3 = m1;
    cout << "m3 = m1" << endl;
    cout << m3 << endl;
    Matrix m4 = m3 + m2;
    cout << "m4 = m3 + m2" << endl;
    cout << m4 << endl;
    m3 += m1;
    cout << "m3 += m1" << endl;
    cout << m3 << endl;
}