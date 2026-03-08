int** transpose(int** matrix, int matrixSize, 
                int* matrixColSize, 
                int* returnSize, 
                int** returnColumnSizes) 
{
    int rows = matrixSize;
    int cols = matrixColSize[0];
    // The transpose will have size cols x rows
    *returnSize = cols;
    // Allocate returnColumnSizes
    *returnColumnSizes = (int*)malloc(cols * sizeof(int));
    for (int i = 0; i < cols; i++) {
        (*returnColumnSizes)[i] = rows;
    }
    // Allocate the resultant transposed matrix
    int** result = (int**)malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        result[i] = (int*)malloc(rows * sizeof(int));
    }
    // Fill the transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}
