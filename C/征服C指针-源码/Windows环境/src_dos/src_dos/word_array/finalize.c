#include <stdlib.h>
#include "word_manage_p.h"

/************************************************************
 * 単語管理部の終了処理を行なう
 ************************************************************/
void word_finalize(void)
{
    int i;

    /* 単語の分の領域を解放する */
    for (i = 0; i < num_of_word; i++) {
        free(word_array[i].name);
    }

    num_of_word = 0;
}
