#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

class Matrix {
private:
    int size;
    std::vector<std::vector<int>> data;

public:
    // Constructor
    Matrix(int n = 0);
    
    // Copy constructor
    Matrix(const Matrix& other);
    
    // Assignment operator
    Matrix& operator=(const Matrix& other);
    
    // Read matrix from file
    void readFromFile(const std::string& filename, int matrixIndex);
    
    // Display matrix with proper formatting
    void display() const;
    
    // Get size
    int getSize() const;
    
    // Get element at position (row, col)
    int getElement(int row, int col) const;
    
    // Set element at position (row, col)
    void setElement(int row, int col, int value);
    
    // Operator overloading for addition
    Matrix operator+(const Matrix& other) const;
    
    // Operator overloading for multiplication
    Matrix operator*(const Matrix& other) const;
    
    // Sum of main diagonal elements
    int sumMainDiagonal() const;
    
    // Sum of secondary diagonal elements
    int sumSecondaryDiagonal() const;
    
    // Swap rows (returns new matrix, doesn't modify original)
    Matrix swapRows(int row1 = 0, int row2 = 1) const;
    
    // Swap columns (returns new matrix, doesn't modify original)
    Matrix swapColumns(int col1 = 0, int col2 = 1) const;
    
    // Update element at position (row, col) with value (returns new matrix)
    Matrix updateElement(int row = 0, int col = 0, int value = 100) const;
};

// Non-member functions that take Matrix by value (ensures original is not modified)
Matrix swapRows(Matrix m, int row1 = 0, int row2 = 1);
Matrix swapColumns(Matrix m, int col1 = 0, int col2 = 1);
Matrix updateElement(Matrix m, int row = 0, int col = 0, int value = 100);

#endif // MATRIX_H


