#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char        buf[256];
    int         size;
    int         *variable_array;
    int         i;

    printf("Input array size>");
    fgets(buf, 256, stdin);
    sscanf(buf, "%d", &size);

    variable_array = malloc(sizeof(int) * size);
    if (variable_array == NULL) {
        fprintf(stderr, "out of memory.\n");
        exit(1);
    }
    for (i = 0; i < size; i++) {
        variable_array[i] = i;
    }
    for (i = 0; i < size; i++) {
        printf("variable_array[%d]..%d\n", i, variable_array[i]);
    }

    return 0;
}
