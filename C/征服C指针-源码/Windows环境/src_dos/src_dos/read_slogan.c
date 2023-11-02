#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_slogan(FILE *fp, char **slogan)
{
    char buf[1024];
    int  i;

    for (i = 0; i < 7; i++) {
        fgets(buf, 1024, fp);

        /* ���s�������폜 */
        buf[strlen(buf)-1] = '\0';

        /* �W��ЂƂ��̗̈���m�� */
        slogan[i] = malloc(sizeof(char) * (strlen(buf) + 1));

        /* �W��̓��e���R�s�[ */
        strcpy(slogan[i], buf);
    }
}

int main(void)
{
    char *slogan[7];
    int i;

    read_slogan(stdin, slogan);

    /* �ǂݍ��񂾕W���\������ */
    for (i = 0; i < 7; i++) {
        printf("%s\n", slogan[i]);
    }

    return 0;
}
