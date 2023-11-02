#include <stdlib.h>
#include "word_manage_p.h"

/************************************************************
 * �P��Ǘ����̏I���������s�Ȃ�
 ************************************************************/
void word_finalize(void)
{
    Word        *temp;

    /* �o�^����Ă���P���S��free()���� */
    while (word_header != NULL) {
        temp = word_header;
        word_header = word_header->next;

        free(temp->name);
        free(temp);
    }
}
