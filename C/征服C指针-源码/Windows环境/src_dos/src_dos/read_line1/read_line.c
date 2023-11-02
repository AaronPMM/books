#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

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
static void
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
        st_line_buffer = realloc(st_line_buffer,
                                 (st_current_buffer_size + ALLOC_SIZE)
                                 * sizeof(char));
        st_current_buffer_size += ALLOC_SIZE;
    }
    /* �o�b�t�@�̖�����1�����ǉ� */
    st_line_buffer[st_current_used_size] = ch;
    st_current_used_size++;
}

/*
 * fp����1�s�ǂݍ��ށB�t�@�C���̖����ɗ�����ANULL��Ԃ��B
 */
char *read_line(FILE *fp)
{
    int         ch;
    char        *ret;

    st_current_used_size = 0;
    while ((ch = getc(fp)) != EOF) {
        if (ch == '\n') {
            add_character('\0');
            break;
        }
        add_character(ch);
    }
    if (ch == EOF) {
        if (st_current_used_size > 0) {
            /* �Ō�̍s�̌�ɉ��s���Ȃ������ꍇ */
            add_character('\0');
        } else {
            return NULL;
        }
    }

    ret = malloc(sizeof(char) * st_current_used_size);
    strcpy(ret, st_line_buffer);

    return ret;
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
