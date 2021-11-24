#include "utils.h"

int main(void) {
    FILE *file = fopen("table.txt", "r");

    if (file == NULL) {
        exit(1);
    }

    int rowsAndCols = 1; // 1 тк отсутствует newline в последней строчке
    int infinity = 0; // номер, с которым будет производиться первое сравнение

    rowsAndCols = countRowsAndCol(file, rowsAndCols);

    int **matrix = (int **) malloc (rowsAndCols * sizeof(int *));

    infinity = initMatrix(file, matrix, &rowsAndCols, infinity);

    int beg, end;

    printf("Enter the starting vertex number\n");
    scanf("%d", &beg);

    if ((beg < 0) || (beg > rowsAndCols)) {
        exit (3);
    }

    printf("Enter the end vertex number\n");
    scanf("%d", &end);

    if ((end < 0) || (end > (rowsAndCols - 1))) {
        exit (4);
    }

    int *minDistance = (int*) calloc (rowsAndCols + 1, sizeof(int));
    int *visitedVertexs = (int*) calloc (rowsAndCols + 1, sizeof(int));

    for (int i = 0; i < rowsAndCols; i++) { // инициализация минимального расстояния и посещённых вершин
        minDistance[i] = infinity;
        visitedVertexs[i] = 1;
    }

    minDistance[beg] = 0;

    // Вывод кратчайших расстояний до вершин
    DijAlg (infinity, rowsAndCols, visitedVertexs, minDistance, matrix);

    printf("Кратчайшее расстояние от вершины %d до вершины %d \n", beg, end);
    printf("%d \n", minDistance[end]);

    return 0;
}
