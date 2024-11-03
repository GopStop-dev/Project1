#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printWord()
{

    FILE *fp = fopen("words.txt", "r");
    char line[100];
    while (fgets(line, 100, fp) != NULL)
    {
        printf("%s", line);
    }
    fclose(fp);

    return 0;
}