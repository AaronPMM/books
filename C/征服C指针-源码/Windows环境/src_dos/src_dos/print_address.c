#include <stdio.h>
#include <stdlib.h>

int             global_variable;
static int      file_static_variable;

void func1(void)
{
    int func1_variable;
    static int local_static_variable;

    printf("&func1_variable..%p\n", &func1_variable);
    printf("&local_static_variable..%p\n", &local_static_variable);
}

void func2(void)
{
    int func2_variable;

    printf("&func2_variable..%p\n", &func2_variable);
}

int main(void)
{
    int *p;

    /* 関数へのポインタの表示 */
    printf("&func1..%p\n", func1);
    printf("&func2..%p\n", func2);
    
    /* 文字列リテラルのアドレスの表示 */
    printf("string literal..%p\n", "abc");

    /* グローバル変数のアドレスの表示 */
    printf("&global_variable..%p\n", &global_variable);

    /* ファイル内static変数のアドレスの表示 */
    printf("&file_static_variable..%p\n", &file_static_variable);

    /* ローカル変数の表示 */
    func1();
    func2();

    /* mallocにより確保した領域のアドレス */
    p = malloc(sizeof(int));
    printf("malloc address..%p\n", p);

    return 0;
}
