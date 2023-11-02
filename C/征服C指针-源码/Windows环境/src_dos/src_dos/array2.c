#include <stdio.h>

int main(void)
{
    int array[5];
    int *p;
    int i;

    /* 配列arrayに値を設定 */
    for (i = 0; i < 5; i++) {
        array[i] = i;
    }

    /* その内容を表示(ポインタ版) */
    for (p = &array[0]; p != &array[5]; p++) {
        printf("%d\n", *p);
    }

    return 0;
}
