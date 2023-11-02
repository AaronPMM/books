#include <stdlib.h>
#include "word_manage_p.h"

/************************************************************
 * 単語管理部の終了処理を行なう
 ************************************************************/
void word_finalize(void)
{
    Word        *temp;

    /* 登録されている単語を全てfree()する */
    while (word_header != NULL) {
        temp = word_header;
        word_header = word_header->next;

        free(temp->name);
        free(temp);
    }
}
