#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addWord(char *engword, char *uzbword)
{
    FILE *fp = fopen("words.txt", "a");
    fprintf(fp, "%s %s\n", engword, uzbword);
    fclose(fp);
}

int main()
{
    while (1)
    {
        printf("Inglizcha so'z kiriting: ");
        char engword[100];
        scanf("%s", engword);

        printf("O'zbekcha so'z kiriting: ");
        char uzbword[100];
        scanf("%s", uzbword);

        addWord(engword, uzbword);
        if (strcmp(engword, "stop") == 0)
        {
            printf("So'zlar bazasiga yozildi!\n");
            break;
        }
    }

    return 0;
}
