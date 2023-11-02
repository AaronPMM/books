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

    /* �֐��ւ̃|�C���^�̕\�� */
    printf("&func1..%p\n", func1);
    printf("&func2..%p\n", func2);
    
    /* �����񃊃e�����̃A�h���X�̕\�� */
    printf("string literal..%p\n", "abc");

    /* �O���[�o���ϐ��̃A�h���X�̕\�� */
    printf("&global_variable..%p\n", &global_variable);

    /* �t�@�C����static�ϐ��̃A�h���X�̕\�� */
    printf("&file_static_variable..%p\n", &file_static_variable);

    /* ���[�J���ϐ��̕\�� */
    func1();
    func2();

    /* malloc�ɂ��m�ۂ����̈�̃A�h���X */
    p = malloc(sizeof(int));
    printf("malloc address..%p\n", p);

    return 0;
}
