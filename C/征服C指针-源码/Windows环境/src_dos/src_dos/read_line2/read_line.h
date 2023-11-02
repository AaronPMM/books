#ifndef READ_LINE_H_INCLUDED
#define READ_LINE_H_INCLUDED

#include <stdio.h>

typedef enum {
    READ_LINE_SUCCESS,      /* �����1�s�ǂݍ��� */
    READ_LINE_EOF,          /* �t�@�C���̏I�[�܂œǂݍ��� */
    READ_LINE_OUT_OF_MEMORY /* ������������Ȃ��Ď��s���� */
} ReadLineStatus;

ReadLineStatus read_line(FILE *fp, char **line);
void free_buffer(void);

#endif /* READ_LINE_H_INCLUDED */
