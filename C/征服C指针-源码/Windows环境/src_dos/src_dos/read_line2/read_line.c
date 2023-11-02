#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "read_line.h"

#define ALLOC_SIZE      (256)

/*
 * 行を読み込むバッファ。必要に応じて拡張される。縮むことはない。
 * free_buffer()の呼び出しで解放される。
 */
static char *st_line_buffer = NULL;

/*
 * st_line_bufferの先に割り当てられている領域のサイズ。
 */
static int  st_current_buffer_size = 0;

/*
 * st_line_bufferの中で、現在文字が格納されている部分のサイズ。
 */
static int  st_current_used_size = 0;

/*
 * st_line_bufferの末尾に1文字追加する。
 * 必要とあれば、st_line_bufferの先の領域を拡張する。
 */
static ReadLineStatus
add_character(int ch)
{
    /*
     * st_current_used_sizeは必ず 1づつ増えるので、
     * いきなり抜かれていることはないはず。
     */
    assert(st_current_buffer_size >= st_current_used_size);

    /*
     * st_current_used_sizeがst_current_buffer_sizeに追い付いたら、
     * バッファを拡張する。
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
    /* バッファの末尾に1文字追加 */
    st_line_buffer[st_current_used_size] = ch;
    st_current_used_size++;

    return READ_LINE_SUCCESS;
}

/*
 * バッファを解放する。別に呼ばなくても差し支えはないけれど、
 * 「プログラム終了時には、malloc()した領域は全部free()しておきたい」
 * という人は、最後にこれを呼べば良い。
 */
void free_buffer(void)
{
    free(st_line_buffer);
    st_line_buffer = NULL;
    st_current_buffer_size = 0;
    st_current_used_size = 0;
}

/*
 * fpから1行読み込む。
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
            /* 最後の行の後に改行がなかった場合 */
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
