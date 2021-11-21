#include "../include/utils.h"

int main(void) {
    int rows = 1; // newline in counting lines
    int cols = 1; // without space in end of line

    int **matrix;
    int i, j;
    int infinity = 0; // the number with which the first comparison will be made
    char c;
    FILE *file = fopen("table.txt", "r");

    while (!feof(file)) // counting lines
         if (fgetc(file) == '\n')
            rows++;

    rewind(file);

    while ((c = fgetc(file)) != '\n') // counting columns
        if (c == ' ')
            cols++;

    // printf("%d\n", rows);
    // printf("%d\n", cols);

    rewind(file);

    matrix = (int**) malloc (cols * sizeof(int)); // probably cols * rows

    for (i = 0; i <= (cols * rows); i++)
        matrix[i] = (int *)malloc(cols * (sizeof(char*)));

    for (i = 0; i < rows && !feof(file) && !ferror(file); i++) { // filling the matrix
        for (j = 0; j < cols && !feof(file) && !ferror(file); j++) {
            if (!fscanf(file, "%d", &matrix[i][j])) {
                fprintf(stderr, "Error reading file\n");
                exit(1);
            }
            infinity += matrix[i][j];
        }
    }
    
    fclose(file);

    // for (i = 0; i < rows; i++) {
    //     for (j = 0; j < cols; j++) {
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    int beg = 0, end = 0;

    printf("Enter the starting vertex number\n");
    scanf("%d", &beg);

    printf("Enter the end vertex number\n");
    scanf("%d", &end);

    int *minDistance = (int*) calloc (rows, sizeof(int));
    int *visitedVertexs = (int*) calloc (rows, sizeof(int));

    for (int i = 0; i < cols; i++) { //init
        minDistance[i] = infinity;
        visitedVertexs[i] = 1;
    }

    minDistance[beg] = 0;

     

    return 0;
    //-Werror
}
