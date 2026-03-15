#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    // We only need to check up to the second-to-last row and column
    for (int i = 0; i < matrixSize - 1; i++) {
        for (int j = 0; j < matrixColSize[0] - 1; j++) {
            // Compare the current element with its bottom-right neighbor
            if (matrix[i][j] != matrix[i + 1][j + 1]) {
                return false; 
            }
        }
    }
    
    return true; 
}
