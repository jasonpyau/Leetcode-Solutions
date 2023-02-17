void rotate(int** matrix, int matrixSize, int* matrixColSize){
    // Transpose matrix
    for (int i = 0; i < matrixSize; i++) {
        for (int k = i; k < *matrixColSize; k++) {
            int temp = matrix[i][k];
            matrix[i][k] = matrix[k][i];
            matrix[k][i] = temp;
        }
    }

    // Reverse columns
    for (int r = 0; r < matrixSize; r++) {
        for (int c = 0; c < *matrixColSize/2; c++) {
            int temp = matrix[r][c];
            matrix[r][c] = matrix[r][*matrixColSize-1-c];
            matrix[r][*matrixColSize-1-c] = temp;
        }
    }
}
