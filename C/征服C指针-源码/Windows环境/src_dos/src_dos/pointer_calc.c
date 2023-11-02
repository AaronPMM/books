#include <stdio.h>

int main(void)
{
    int hoge;
    int *hoge_p;

    /* hoge_p に hogeへのポインタを設定 */
    hoge_p = &hoge;
    /* hoge_p の値を表示 */
    printf("hoge_p..%p\n", hoge_p);
    /* hoge_pに 1加算 */
    hoge_p++;
    /* hoge_p の値を表示 */
    printf("hoge_p..%p\n", hoge_p);
    /* hoge_p に 3加算した値を表示 */
    printf("hoge_p..%p\n", hoge_p + 3);

    return 0;
}
