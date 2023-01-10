bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){

    int min = 0, max = matrixSize-2, r = 0;
    if (matrixSize > 1) {
        while (max >= min) {
            r = (min+max)/2;
            if (matrix[r][0] == target || matrix[r+1][0] == target) {
                return true;
            }
            else if (matrix[r][0] < target && matrix[r+1][0] > target) {
                break;
            }
            else if (matrix[r][0] > target) {
                max = r-1;
            }
            else {
                min = r+1;
            }
        }
    }
    if (min > max) {
        r = matrixSize-1;
    }
    
    int c = 0;
    min = 0, max = *matrixColSize-1;
    while (max >= min) {
        c = (min+max)/2;
        if (matrix[r][c] == target) {
            return true;
        }
        else if (matrix[r][c] > target) {
            max = c-1;
        }
        else {
            min = c+1;
        }
    }
    return false;
}
