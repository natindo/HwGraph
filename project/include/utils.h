#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#include <stdio.h>
#include <stdlib.h>

void DijAlg (int infinity, int rowsAndCols, int *visitedVertexs, int *minDistance, int **matrix);
int initMatrix (FILE *file,int **matrix, int *rowsAndCols, int infinity);
int countRowsAndCol (FILE *file, int rowsAndCols);

#endif //PROJECT_INCLUDE_UTILS_H_
