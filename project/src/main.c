#include "../include/utils.h"

int main(void) {

    // char **arr;
    // int i,j;
    // int buffer;
    // int * num;
    // int n1,str;
    // n1 = str = i = j = 0;
    
    const int rows = 2;
    const int cols = 6;
    int matrix[rows][cols];
    int i, j;
    FILE *out;
    FILE *file = fopen("table.txt", "r");
    out = fopen("out.txt", "w");
    for (i = 0; i < rows && !feof(file) && !ferror(file); i++) {
        for (j = 0; j < cols && !feof(file) && !ferror(file); j++) {
            if (!fscanf(file, "%d", &matrix[i][j])) {
                fprintf(stderr, "Error reading file\n");
                exit(1);
            }
            fprintf(out, "%d ", matrix[i][j]);
        }
        fputc('\n', out);
    }
    
    fclose(file);
    fclose(out);

    return 0;
    //-Werror
}
