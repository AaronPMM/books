#include <stdlib.h>
#include "word_manage_p.h"

/************************************************************
 * �P��Ǘ����̏I���������s�Ȃ�
 ************************************************************/
void word_finalize(void)
{
    int i;

    /* �P��̕��̗̈��������� */
    for (i = 0; i < num_of_word; i++) {
        free(word_array[i].name);
    }

    num_of_word = 0;
}
