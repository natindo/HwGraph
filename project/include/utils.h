#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

//algorithm
void DijAlg (int infinity, int rowsAndCols, int *visitedVertexs, int *minDistance, int **matrix);

//init matrix
int initMatrix (FILE *file,int **matrix, int *rowsAndCols);
int countRowsAndCol (FILE *file);

//errors
void isHaveFreestandingVertex (int **matrix, int rowsAndCols);
void inputVertexError (int beg, int end, int rowsAndCols);
void fileOpenError (FILE *file);

#endif //PROJECT_INCLUDE_UTILS_H_
