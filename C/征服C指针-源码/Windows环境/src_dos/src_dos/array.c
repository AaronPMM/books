#include <stdio.h>

int main(void)
{
    int array[5];
    int i;

    /* �z��array�ɒl��ݒ� */
    for (i = 0; i < 5; i++) {
        array[i] = i;
    }

    /* ���̓��e��\�� */
    for (i = 0; i < 5; i++) {
        printf("%d\n", array[i]);
    }

    /* array�̊e�v�f�̃A�h���X��\�� */
    for (i = 0; i < 5; i++) {
        printf("&array[%d]... %p\n", i, &array[i]);
    }

    return 0;
}
