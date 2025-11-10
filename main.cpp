//=========================================================
// Name: Caleb Morse
// Course: EECS 348 – Lab 11: C++ Programming
// File: main.cpp
// Collaborators: ChatGPT and Cursor
// Description:
//     Main driver for the Matrix Operations lab.
//     Reads two N×N matrices from a file and demonstrates:
//       - Formatted display
//       - Operator overloading (+, *)
//       - Diagonal sums
//       - Row/column swaps
//       - Element updates
//=========================================================

#include "Matrix.h"
#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    
    // Read size from file first
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return 1;
    }
    
    int n;
    file >> n;
    file.close();
    
    // Create matrices
    Matrix matrix1(n);
    Matrix matrix2(n);
    
    // Read matrices from file
    matrix1.readFromFile(filename, 0);
    matrix2.readFromFile(filename, 1);
    
    // Practice 1: Display both matrices
    std::cout << "\nMatrix 1:" << std::endl;
    matrix1.display();
    
    std::cout << "\nMatrix 2:" << std::endl;
    matrix2.display();
    
    // Practice 2: Add matrices using operator overloading
    std::cout << "\nMatrix 1 + Matrix 2:" << std::endl;
    Matrix sum = matrix1 + matrix2;
    sum.display();
    
    // Practice 3: Multiply matrices using operator overloading
    std::cout << "\nMatrix 1 * Matrix 2:" << std::endl;
    Matrix product = matrix1 * matrix2;
    product.display();
    
    // Practice 4: Sum of diagonal elements
    std::cout << "\nSum of main diagonal elements of Matrix 1: " 
              << matrix1.sumMainDiagonal() << std::endl;
    std::cout << "Sum of secondary diagonal elements of Matrix 1: " 
              << matrix1.sumSecondaryDiagonal() << std::endl;
    
    // Practice 5: Swap rows (default: rows 0 and 1)
    std::cout << "\nMatrix 1 with rows 0 and 1 swapped:" << std::endl;
    Matrix swappedRows = matrix1.swapRows();
    swappedRows.display();
    
    // Also demonstrate with custom indices
    std::cout << "\nMatrix 1 with rows 1 and 2 swapped:" << std::endl;
    Matrix swappedRowsCustom = matrix1.swapRows(1, 2);
    swappedRowsCustom.display();
    
    // Practice 6: Swap columns (default: columns 0 and 1)
    std::cout << "\nMatrix 1 with columns 0 and 1 swapped:" << std::endl;
    Matrix swappedCols = matrix1.swapColumns();
    swappedCols.display();
    
    // Also demonstrate with custom indices
    std::cout << "\nMatrix 1 with columns 2 and 3 swapped:" << std::endl;
    Matrix swappedColsCustom = matrix1.swapColumns(2, 3);
    swappedColsCustom.display();
    
    // Practice 7: Update element (default: row=0, col=0, value=100)
    std::cout << "\nMatrix 1 with element at (0,0) updated to 100:" << std::endl;
    Matrix updated1 = matrix1.updateElement();
    updated1.display();
    
    // Also demonstrate with custom values
    std::cout << "\nMatrix 1 with element at (2,2) updated to 999:" << std::endl;
    Matrix updated2 = matrix1.updateElement(2, 2, 999);
    updated2.display();
    
    // Verify original matrix is not modified
    std::cout << "\nOriginal Matrix 1 (unchanged):" << std::endl;
    matrix1.display();
    
    return 0;
}

