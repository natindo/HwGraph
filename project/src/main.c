#include "utils.h"

int main(void) {
    FILE *file = fopen("table.txt", "r");

    fileOpenError (file);

    int rowsAndCols = countRowsAndCol(file);
    int **matrix = (int**) malloc (rowsAndCols * sizeof(int *));

    //инициаллизируем массив matrix
    int infinity = initMatrix(file, matrix, &rowsAndCols); // номер, с которым будет производиться первое сравнение в каждой вершине

    isHaveFreeStandingVertex (matrix, rowsAndCols);
    
    printf("Enter the start vertex number\n");
    int beg = read (rowsAndCols);

    printf("Enter the end vertex number\n");
    int end = read (rowsAndCols);

    inputVertexError (beg, end, rowsAndCols);

    int *minDistance = (int*) calloc (rowsAndCols + 1, sizeof(int));
    int *visitedVertexs = (int*) calloc (rowsAndCols + 1, sizeof(int));

    for (int i = 0; i < rowsAndCols; i++) { // инициализация минимального расстояния и посещённых вершин
        minDistance[i] = infinity;
        visitedVertexs[i] = 1;
    }

    minDistance[beg] = 0;

    DijAlg (infinity, rowsAndCols, visitedVertexs, minDistance, matrix);

    // Вывод кратчайшего расстояния до вершины
    printf("Shortest distance from vertex %d to vertex %d \n", beg, end);
    printf("%d \n", minDistance[end]);

    return 0;
}
