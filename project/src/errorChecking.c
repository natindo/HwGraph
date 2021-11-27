#include "utils.h"

void fileOpenError (FILE *file) {
    if (file == NULL)
        exit (1);
}

void inputVertexError (int beg, int end, int rowsAndCols) {
    if ((beg < 0) || (beg > rowsAndCols))
        exit (2);

    if ((end < 0) || (end > (rowsAndCols - 1))) // -1 тк есть 0-я вершина
        exit (3);

    if (beg > end)
        exit (4);
}

void isHaveFreestandingVertex (int **matrix, int rowsAndCols) {
    int numberOfZeros = 0;

    for (int i = 0; i < rowsAndCols; i++) {
        for (int j = 0; j < rowsAndCols; j++) {
            if (matrix[i][j] == 0)
                numberOfZeros++;

            if (numberOfZeros == rowsAndCols)
                exit (5);
            
        }
        numberOfZeros = 0;
    }
}

int read(int rowsAndCols) {
    char c;
    char *smth = (char*) malloc (rowsAndCols * sizeof(char));
    int i = 0;

    while((c = getchar()) != EOF && c != '\n') {
        if (!isdigit(c))
            exit (7);

        smth[i] = c;
        i++;
    }
    i = atoi(smth);
    return i;
}
