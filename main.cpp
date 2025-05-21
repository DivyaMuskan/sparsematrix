#include "SparseMatrix.h"
#include <iostream>

int main() {
    SparseMatrix matrix;
    
    // Set some values
    matrix.set(0, 0, 1.0);
    matrix.set(1, 1, 2.0);
    matrix.set(2, 2, 3.0);
    
    // Print some values
    std::cout << "Value at (0,0): " << matrix.get(0, 0) << std::endl;
    std::cout << "Value at (1,1): " << matrix.get(1, 1) << std::endl;
    std::cout << "Value at (2,2): " << matrix.get(2, 2) << std::endl;
    std::cout << "Value at (1,0): " << matrix.get(1, 0) << std::endl; // Should print 0
    
    // Print number of non-zero elements
    std::cout << "Number of non-zero elements: " << matrix.nonZeroCount() << std::endl;
    
    return 0;
}