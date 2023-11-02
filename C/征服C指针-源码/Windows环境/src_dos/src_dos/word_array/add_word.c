#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word_manage_p.h"

/*
 * index������̗v�f(index���܂�)���ЂƂÂ���ɃV�t�g������B
 */
static void shift_array(int index)
{
    int src;    /* �R�s�[���̃C���f�b�N�X */

    for (src = num_of_word - 1; src >= index; src--) {
        word_array[src+1] = word_array[src];
    }
    num_of_word++;
}

/*
 * ������𕡐�����B
 * �����Ă��̏����n�ɂ�strdup()�Ƃ����֐������邪�A
 * strdup()��ANSI�K�i�ɂ͂Ȃ��̂ŁA�ꉞ���삵�Ă����B
 */
static char *my_strdup(char *src)
{
    char        *dest;

    dest = malloc(sizeof(char) * (strlen(src) + 1));
    strcpy(dest, src);

    return dest;
}

/************************************************************
 * �P���ǉ�����
 ************************************************************/
void add_word(char *word)
{
    int i;
    int result;

    for (i = 0; i < num_of_word; i++) {
        result = strcmp(word_array[i].name, word);
        if (result >= 0)
            break;
    }
    if (num_of_word != 0 && result == 0) {
        /* ����̒P�ꂪ���t������ */
        word_array[i].count++;
    } else {
        shift_array(i);
        word_array[i].name = my_strdup(word);
        word_array[i].count = 1;
    }
}
