#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wordGame()
{
    char line[200];
    char englishWord[100];
    char tarjima[100];
    char userTarjima[100];

    FILE *fp = fopen("words.txt", "r");

    int count = 0;
    int count2 = 0;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "%s %s", englishWord, tarjima);

        printf("Quyidagi so'zni to'g'ri tarjimasini yozing: %s\n", englishWord);
        printf("Tarjima: ");
        fgets(userTarjima, sizeof(userTarjima), stdin);

        if (strncmp(userTarjima, tarjima, strlen(tarjima)) == 0 &&
            (userTarjima[strlen(tarjima)] == '\n' || userTarjima[strlen(tarjima)] == '\0'))
        {
            count++;
        }
        else
        {
            count2++;
        }
        if (strcmp(userTarjima, "stop\n") == 0)
        {
            printf("Siz %d ta so'z to'g'ri topdingiz va %d ta so'z noto'g'ri topdingiz.\n", count, count2);
            break;
        }
    }

    fclose(fp);
}

int main()
{
    wordGame();
    return 0;
}
