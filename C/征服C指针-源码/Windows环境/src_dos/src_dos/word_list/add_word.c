#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word_manage_p.h"

/*
 * •¶Žš—ñ‚ð•¡»‚·‚éB
 * ‚½‚¢‚Ä‚¢‚Ìˆ—Œn‚É‚Ístrdup()‚Æ‚¢‚¤ŠÖ”‚ª‚ ‚é‚ªA
 * strdup()‚ÍANSI‹KŠi‚É‚Í‚È‚¢‚Ì‚ÅAˆê‰žŽ©ì‚µ‚Ä‚¨‚­B
 */
static char *my_strdup(char *src)
{
    char        *dest;

    dest = malloc(sizeof(char) * (strlen(src) + 1));
    strcpy(dest, src);

    return dest;
}

/*
 * V‚µ‚¢Word\‘¢‘Ì‚ð¶¬‚·‚é
 */
static Word *create_word(char *name)
{
    Word        *new_word;

    new_word = malloc(sizeof(Word));

    new_word->name = my_strdup(name);
    new_word->count = 1;
    new_word->next = NULL;

    return new_word;
}

/************************************************************
 * ’PŒê‚ð’Ç‰Á‚·‚é
 ************************************************************/
void add_word(char *word)
{
    Word        *pos;
    Word        *prev;  /* pos‚ÌŒã‚ð‚Ð‚Æ‚Â’x‚ê‚Ä•t‚¢‚Ä‚¢‚­ƒ|ƒCƒ“ƒ^ */
    Word        *new_word;
    int         result;

    prev = NULL;
    for (pos = word_header; pos != NULL; pos = pos->next) {
        result = strcmp(pos->name, word);
        if (result >= 0)
            break;

        prev = pos;
    }
    if (word_header != NULL && result == 0) {
        /* “¯ˆê‚Ì’PŒê‚ªŒ©•t‚©‚Á‚½ */
        pos->count++;
    } else {
        new_word =  create_word(word);
        if (prev == NULL) {
            /* –`“ª‚É‘}“ü */
            new_word->next = word_header;
            word_header = new_word;
        } else {
            new_word->next = pos;
            prev->next = new_word;
        }
    }
}
