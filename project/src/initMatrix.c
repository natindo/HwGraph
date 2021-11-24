#include "utils.h"

int countRowsAndCol (FILE *file, int rowsAndCols) { // подсчёт строк и столбцов
    while (!feof(file))
        if (fgetc(file) == '\n')
            rowsAndCols++;

    rewind(file);

    return rowsAndCols;
}

int initMatrix (FILE *file,int **matrix, int *rowsAndCols, int infinity) {
    for (int i = 0; i <= (*rowsAndCols * 2); i++)
        matrix[i] = (int *) malloc (*rowsAndCols * (sizeof(int)));

    for (int i = 0; i < *rowsAndCols && !feof(file); i++) { // заполнение матрицы
        for (int j = 0; j < *rowsAndCols && !feof(file); j++) {
            if (!fscanf(file, "%d", &matrix[i][j])) {
                fprintf(stderr, "Error reading file\n");
                exit(1);
            }
            infinity += matrix[i][j];
        }
    }
    
    fclose(file);
    free(file);

    return infinity;
}
