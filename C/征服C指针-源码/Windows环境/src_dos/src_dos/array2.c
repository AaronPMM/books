#include <stdio.h>

int main(void)
{
    int array[5];
    int *p;
    int i;

    /* �z��array�ɒl��ݒ� */
    for (i = 0; i < 5; i++) {
        array[i] = i;
    }

    /* ���̓��e��\��(�|�C���^��) */
    for (p = &array[0]; p != &array[5]; p++) {
        printf("%d\n", *p);
    }

    return 0;
}
