#include "utils.h"

void fileOpenError (FILE *file) {
    if (file == NULL)
        exit(1);
}

void inputVertexError (int beg, int end, int rowsAndCols) {
    if ((beg < 0) || (beg > rowsAndCols))
        exit (3);
    
    if ((end < 0) || (end > (rowsAndCols - 1)))
        exit (4);

    if (beg > end)
        exit (5);
}

void isHaveFreestandingVertex (int **matrix, int rowsAndCols) {
    int numberOfZeros = 0;

    for (int i = 0; i < rowsAndCols; i++) {
        for (int j = 0; j < rowsAndCols; j++) {
            if (matrix[i][j] == 0)
                numberOfZeros++;

            if (numberOfZeros == rowsAndCols)
                exit(6);
            
        }
        numberOfZeros = 0;
    }
}
