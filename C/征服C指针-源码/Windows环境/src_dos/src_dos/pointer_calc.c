#include <stdio.h>

int main(void)
{
    int hoge;
    int *hoge_p;

    /* hoge_p �� hoge�ւ̃|�C���^��ݒ� */
    hoge_p = &hoge;
    /* hoge_p �̒l��\�� */
    printf("hoge_p..%p\n", hoge_p);
    /* hoge_p�� 1���Z */
    hoge_p++;
    /* hoge_p �̒l��\�� */
    printf("hoge_p..%p\n", hoge_p);
    /* hoge_p �� 3���Z�����l��\�� */
    printf("hoge_p..%p\n", hoge_p + 3);

    return 0;
}
