#include "utils.h"

int DijAlg (int infinity, int rowsAndCols, int *visitedVertexs, int *minDistance, int **matrix) {
    int minIndex = infinity;
    do {
        minIndex = infinity;
        int min = infinity;
        int temp = 0;
        for (int i = 0; i < rowsAndCols; i++) { // Если вершину ещё не обошли и вес меньше min
            if ((visitedVertexs[i] == 1) && (minDistance[i] < min)) { // Переприсваиваем значения
                min = minDistance[i];
                minIndex = i;
            }
        }
    // Добавляем найденный минимальный вес
    // к текущему весу вершины
    // и сравниваем с текущим минимальным весом вершины
        if (minIndex != infinity) {
            for (int i = 0; i < rowsAndCols; i++) {
                if (matrix[minIndex][i] > 0) {
                    temp = min + matrix[minIndex][i];
                    if (temp < minDistance[i]) {
                        minDistance[i] = temp;
                    }
                }
            }
        visitedVertexs[minIndex] = 0;
        }
    } while (minIndex < infinity);

    return 0;
}

int main(void) {
    FILE *file = fopen("table.txt", "r");

    if (file == NULL) {
        exit(1);
    }

    int rowsAndCols = 1; // newline in counting lines

    while (!feof(file)) // counting lines and columns
         if (fgetc(file) == '\n')
            rowsAndCols++;

    rewind(file);

    int **matrix = (int**) malloc (rowsAndCols * sizeof(int *)); // probably cols * rowsAndCols

    for (int i = 0; i <= (rowsAndCols * 2); i++)
        matrix[i] = (int *)malloc(rowsAndCols * (sizeof(int)));

    int infinity = 0; // the number with which the first comparison will be made

    for (int i = 0; i < rowsAndCols && !feof(file) && !ferror(file); i++) { // filling the matrix
        for (int j = 0; j < rowsAndCols && !feof(file) && !ferror(file); j++) {
            if (!fscanf(file, "%d", &matrix[i][j])) {
                fprintf(stderr, "Error reading file\n");
                exit(1);
            }
            infinity += matrix[i][j];
        }
    }
    
    fclose(file);

    int beg, end;

    printf("Enter the starting vertex number\n");
    scanf("%d", &beg);

    if ((beg < 0) || (beg > rowsAndCols)) {
        exit (3);
    }

    printf("Enter the end vertex number\n");
    scanf("%d", &end);

    if ((end < 0)|| (end > (rowsAndCols - 1))) {
        exit (4);
    }

    int *minDistance = (int*) calloc (rowsAndCols + 1, sizeof(int));
    int *visitedVertexs = (int*) calloc (rowsAndCols + 1, sizeof(int));

    for (int i = 0; i < rowsAndCols; i++) { //init
        minDistance[i] = infinity;
        visitedVertexs[i] = 1;
    }

    minDistance[beg] = 0;

    // Вывод кратчайших расстояний до вершин

    DijAlg (infinity, rowsAndCols, visitedVertexs, minDistance, matrix);

    printf("Кратчайшее расстояние от вершины %d до вершины %d \n", beg, end);
    
    // for (int i = 0; i < rowsAndCols; i++)
    //     printf("%5d ", minDistance[i]);

    printf("%d \n", minDistance[end]);

    return 0;
    //-Werror
}
