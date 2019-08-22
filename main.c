#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buf[255];
    char *txt = NULL;
    FILE *pf = NULL;
    long len = 0;
    int i;


    system("dir");

    printf("Input file name: ");
    gets(buf);

    pf = fopen(buf, "rb");
    if(pf == NULL)
    {
        printf("No file!");
        exit(0);
    }
    fseek(pf, 0, SEEK_END);
    len = ftell(pf);
    rewind(pf);

    txt = (char*)malloc(len+1);
    for(i = 0; i < len; i++)
        txt[i] = fgetc(pf);
    txt[i] = '\0';

    fclose(pf);
    pf = NULL;

    printf("%s", txt);
    free(txt);
    txt = NULL;

    return 0;
}

