#include "utils.h"

int countRowsAndCol (FILE *file) { // подсчёт строк и столбцов
    int rowsAndCols = 1; // 1 тк отсутствует newline в последней строчке
    
    while (!feof(file))
        if (fgetc(file) == '\n')
            rowsAndCols++;

    rewind(file);

    return rowsAndCols;
}

int initMatrix (FILE *file,int **matrix, int *rowsAndCols) {
    int infinity = 0;
    
    for (int i = 0; i <= (*rowsAndCols * 2); i++)
        matrix[i] = (int *) malloc (*rowsAndCols * (sizeof(int)));

    for (int i = 0; i < *rowsAndCols && !feof(file); i++) { // заполнение матрицы 
        for (int j = 0; j < *rowsAndCols && !feof(file); j++) {
            if (!fscanf(file, "%d", &matrix[i][j])) {
                fprintf(stderr, "Error reading file\n");
                exit (6);
            }

            if (matrix[i][j] < 0) {
                printf("%d\n", matrix[i][j]);
                exit (8);
            }
            infinity += matrix[i][j]; // подсчёт суммы всех элементов массива
        }
    }

    fclose(file);

    return infinity;
}
