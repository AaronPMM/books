#ifndef WORD_MANAGE_H_INCLUDED
#define WORD_MANAGE_H_INCLUDED
#include <stdio.h>

void word_initialize(void);
void add_word(char *word);
void dump_word(FILE *fp);
int get_word_count(char *word);
void word_finalize(void);

#endif /* WORD_MANAGE_H_INCLUDED */
