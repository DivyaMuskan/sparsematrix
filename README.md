# 🎯 SparseMatrix Implementation

Welcome to the SparseMatrix project! 🚀 This is a memory-efficient implementation of a sparse matrix in C++.

## ✨ Features

- 📊 Efficient storage of sparse matrices using linked lists
- 🚫 Only stores non-zero elements
- ⚡ Fast access and modification operations
- 🎯 Perfect for large matrices with few non-zero elements

## 🛠️ Usage

```cpp
#include "SparseMatrix.h"

// Create a new sparse matrix
SparseMatrix matrix;

// Set values
matrix.set(0, 0, 1.0);  // Set element at row 0, col 0
matrix.set(1, 1, 2.0);  // Set element at row 1, col 1

// Get values
double value = matrix.get(0, 0);  // Get element at row 0, col 0

// Count non-zero elements
size_t count = matrix.nonZeroCount();

# Using MSVC
cl /EHsc main.cpp

# Or using MinGW
g++ -o sparseMatrix main.cpp
