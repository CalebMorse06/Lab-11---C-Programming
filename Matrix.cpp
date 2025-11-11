#include "Matrix.h"
#include <sstream>
#include <algorithm>

// Constructor
Matrix::Matrix(int n) : size(n) {
    if (n > 0) {
        data.resize(n, std::vector<int>(n, 0));
    }
}

// Copy constructor
Matrix::Matrix(const Matrix& other) : size(other.size), data(other.data) {
}

// Assignment operator
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        size = other.size;
        data = other.data;
    }
    return *this;
}

// Read matrix from file
void Matrix::readFromFile(const std::string& filename, int matrixIndex) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return;
    }
    
    // Read size
    file >> size;
    
    // Resize data
    data.resize(size, std::vector<int>(size));
    
    // Skip to the appropriate matrix (0 for first, 1 for second)
    if (matrixIndex == 0) {
        // Read first matrix directly
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> data[i][j];
            }
        }
    } else {
        // Skip first matrix
        int temp;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> temp;
            }
        }
        // Read second matrix
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> data[i][j];
            }
        }
    }
    
    file.close();
}

// Display matrix with proper formatting
void Matrix::display() const {
    // Find the maximum width needed for formatting
    int maxWidth = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int numDigits = 0;
            int num = std::abs(data[i][j]);
            if (num == 0) numDigits = 1;
            else {
                while (num > 0) {
                    numDigits++;
                    num /= 10;
                }
            }
            if (data[i][j] < 0) numDigits++; // Account for negative sign
            if (numDigits > maxWidth) maxWidth = numDigits;
        }
    }
    
    // Display with proper alignment
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(maxWidth) << data[i][j];
            if (j < size - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }
}

// Get size
int Matrix::getSize() const {
    return size;
}

// Get element at position (row, col)
int Matrix::getElement(int row, int col) const {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        return data[row][col];
    }
    return 0;
}

// Set element at position (row, col)
void Matrix::setElement(int row, int col, int value) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        data[row][col] = value;
    }
}

// Operator overloading for addition
Matrix Matrix::operator+(const Matrix& other) const {
    if (size != other.size) {
        std::cerr << "Error: Matrices must have the same size for addition" << std::endl;
        return Matrix(0);
    }
    
    Matrix result(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Operator overloading for multiplication
Matrix Matrix::operator*(const Matrix& other) const {
    if (size != other.size) {
        std::cerr << "Error: Matrices must have the same size for multiplication" << std::endl;
        return Matrix(0);
    }
    
    Matrix result(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

// Sum of main diagonal elements
int Matrix::sumMainDiagonal() const {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i][i];
    }
    return sum;
}

// Sum of secondary diagonal elements
int Matrix::sumSecondaryDiagonal() const {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i][size - 1 - i];
    }
    return sum;
}

// Swap rows (returns new matrix, doesn't modify original)
Matrix Matrix::swapRows(int row1, int row2) const {
    Matrix result(*this); // Create a copy
    
    if (row1 >= 0 && row1 < size && row2 >= 0 && row2 < size) {
        std::swap(result.data[row1], result.data[row2]);
    }
    
    return result;
}

// Swap columns (returns new matrix, doesn't modify original)
Matrix Matrix::swapColumns(int col1, int col2) const {
    Matrix result(*this); // Create a copy
    
    if (col1 >= 0 && col1 < size && col2 >= 0 && col2 < size) {
        for (int i = 0; i < size; i++) {
            std::swap(result.data[i][col1], result.data[i][col2]);
        }
    }
    
    return result;
}

// Update element at position (row, col) with value (returns new matrix)
Matrix Matrix::updateElement(int row, int col, int value) const {
    Matrix result(*this); // Create a copy
    
    if (row >= 0 && row < size && col >= 0 && col < size) {
        result.data[row][col] = value;
    }
    
    return result;
}

// Non-member pass-by-value wrapper functions (meet the lab requirement of passing Matrix by value)
Matrix swapRows(Matrix m, int row1, int row2) {
    return m.swapRows(row1, row2);
}

Matrix swapColumns(Matrix m, int col1, int col2) {
    return m.swapColumns(col1, col2);
}

Matrix updateElement(Matrix m, int row, int col, int value) {
    return m.updateElement(row, col, value);
}

