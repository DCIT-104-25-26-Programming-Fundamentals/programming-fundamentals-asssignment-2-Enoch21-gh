// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to read a matrix
void readMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Part A: Transpose a matrix
void transposeMatrix(int matrix[10][10], int transpose[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
}

// Part B: Add two matrices
void addMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Part C: Multiply two matrices
void multiplyMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10],
                      int rows1, int cols1, int cols2)
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main()
{
    int matrix1[10][10], matrix2[10][10];
    int transpose[10][10], sum[10][10], product[10][10];

    int rows, cols;

    // ==========================
    // PART A - Transpose
    // ==========================
    cout << "========== PART A: TRANSPOSE MATRIX ==========" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matrix1, rows, cols);

    transposeMatrix(matrix1, transpose, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix1, rows, cols);

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transpose, cols, rows);

    // ==========================
    // PART B - Addition
    // ==========================
    cout << "\n========== PART B: ADD MATRICES ==========" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nEnter Matrix A" << endl;
    readMatrix(matrix1, rows, cols);

    cout << "\nEnter Matrix B" << endl;
    readMatrix(matrix2, rows, cols);

    addMatrices(matrix1, matrix2, sum, rows, cols);

    cout << "\nSum of Matrices:" << endl;
    displayMatrix(sum, rows, cols);

    // ==========================
    // PART C - Multiplication
    // ==========================
    cout << "\n========== PART C: MULTIPLY MATRICES ==========" << endl;

    int rows1, cols1, rows2, cols2;

    cout << "Enter rows for Matrix A: ";
    cin >> rows1;

    cout << "Enter columns for Matrix A: ";
    cin >> cols1;

    cout << "\nEnter Matrix A" << endl;
    readMatrix(matrix1, rows1, cols1);

    cout << "\nEnter rows for Matrix B: ";
    cin >> rows2;

    cout << "Enter columns for Matrix B: ";
    cin >> cols2;

    if (cols1 != rows2)
    {
        cout << "Error: Matrix multiplication is not possible." << endl;
        return 0;
    }

    cout << "\nEnter Matrix B" << endl;
    readMatrix(matrix2, rows2, cols2);

    multiplyMatrices(matrix1, matrix2, product, rows1, cols1, cols2);

    cout << "\nProduct Matrix:" << endl;
    displayMatrix(product, rows1, cols2);

    return 0;
}