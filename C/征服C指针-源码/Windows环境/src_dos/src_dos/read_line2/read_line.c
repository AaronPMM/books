#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "read_line.h"

#define ALLOC_SIZE      (256)

/*
 * �s��ǂݍ��ރo�b�t�@�B�K�v�ɉ����Ċg�������B�k�ނ��Ƃ͂Ȃ��B
 * free_buffer()�̌Ăяo���ŉ�������B
 */
static char *st_line_buffer = NULL;

/*
 * st_line_buffer�̐�Ɋ��蓖�Ă��Ă���̈�̃T�C�Y�B
 */
static int  st_current_buffer_size = 0;

/*
 * st_line_buffer�̒��ŁA���ݕ������i�[����Ă��镔���̃T�C�Y�B
 */
static int  st_current_used_size = 0;

/*
 * st_line_buffer�̖�����1�����ǉ�����B
 * �K�v�Ƃ���΁Ast_line_buffer�̐�̗̈���g������B
 */
static ReadLineStatus
add_character(int ch)
{
    /*
     * st_current_used_size�͕K�� 1�Â�����̂ŁA
     * �����Ȃ蔲����Ă��邱�Ƃ͂Ȃ��͂��B
     */
    assert(st_current_buffer_size >= st_current_used_size);

    /*
     * st_current_used_size��st_current_buffer_size�ɒǂ��t������A
     * �o�b�t�@���g������B
     */
    if (st_current_buffer_size == st_current_used_size) {
        char *temp;
        temp = realloc(st_line_buffer,
                       (st_current_buffer_size + ALLOC_SIZE)
                       * sizeof(char));
        if (temp == NULL) {
            return READ_LINE_OUT_OF_MEMORY;
        }
        st_line_buffer = temp;
        st_current_buffer_size += ALLOC_SIZE;
    }
    /* �o�b�t�@�̖�����1�����ǉ� */
    st_line_buffer[st_current_used_size] = ch;
    st_current_used_size++;

    return READ_LINE_SUCCESS;
}

/*
 * �o�b�t�@���������B�ʂɌĂ΂Ȃ��Ă������x���͂Ȃ�����ǁA
 * �u�v���O�����I�����ɂ́Amalloc()�����̈�͑S��free()���Ă��������v
 * �Ƃ����l�́A�Ō�ɂ�����ĂׂΗǂ��B
 */
void free_buffer(void)
{
    free(st_line_buffer);
    st_line_buffer = NULL;
    st_current_buffer_size = 0;
    st_current_used_size = 0;
}

/*
 * fp����1�s�ǂݍ��ށB
 */
ReadLineStatus read_line(FILE *fp, char **line)
{
    int                 ch;
    ReadLineStatus      status = READ_LINE_SUCCESS;

    st_current_used_size = 0;
    while ((ch = getc(fp)) != EOF) {
        if (ch == '\n') {
            status = add_character('\0');
            if (status != READ_LINE_SUCCESS)
                goto FUNC_END;
            break;
        }
        status = add_character(ch);
        if (status != READ_LINE_SUCCESS)
            goto FUNC_END;
    }
    if (ch == EOF) {
        if (st_current_used_size > 0) {
            /* �Ō�̍s�̌�ɉ��s���Ȃ������ꍇ */
            status =add_character('\0');
            if (status != READ_LINE_SUCCESS)
                goto FUNC_END;
        } else {
            status = READ_LINE_EOF;
            goto FUNC_END;
        }
    }

    *line = malloc(sizeof(char) * st_current_used_size);
    if (line == NULL) {
        status = READ_LINE_OUT_OF_MEMORY;
        goto FUNC_END;
    }
    strcpy(*line, st_line_buffer);

  FUNC_END:
    if (status != READ_LINE_SUCCESS && status != READ_LINE_EOF) {
        free_buffer();
    }
    return status;
}

int main(void)
{
    ReadLineStatus      status;
    char                *line;

    for (;;) {
        status = read_line(stdin, &line);
        if (status == READ_LINE_EOF)
            break;
        puts(line);
    }

    return 0;
}
