#include "utils.h"

void DijAlg (int infinity, int rowsAndCols, int *visitedVertexs, int *minDistance, int **matrix) {
    int minIndex = infinity;
    do {
        minIndex = infinity;
        int min = infinity;
        int temp = 0;
        for (int i = 0; i < rowsAndCols; i++) {
            if ((visitedVertexs[i] == 1) && (minDistance[i] < min)) { // если вершину ещё не обошли и вес меньше min
                min = minDistance[i];
                minIndex = i; // индекс вершины с минимальным значением
            }
        }
    // Добавляем найденный минимальный вес к текущему весу вершины
    // и сравниваем с минимальным весом вершины
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
}
