#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addWord(char *engword, char *uzbword)
{
    FILE *fp = fopen("words.txt", "a");
    fprintf(fp, "%s %s\n", engword, uzbword);
    fclose(fp);
}

void printWord()
{
    FILE *ptr = fopen("words.txt", "r");
    char line[100];
    while (fgets(line, sizeof(line), ptr) != NULL)
    {
        printf("%s", line);
    }
    fclose(ptr);
}

void wordGame()
{
    char line[200];
    char englishWord[100];
    char tarjima[100];
    char userTarjima[100];
    int count = 0;
    int count2 = 0;

    FILE *fp = fopen("words.txt", "r");

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "%s %s", englishWord, tarjima);

        printf("Quyidagi so'zni to'g'ri tarjimasini yozing: %s\n", englishWord);
        printf("Tarjima: ");
        fgets(userTarjima, sizeof(userTarjima), stdin);

        if (strcmp(userTarjima, "stop\n") == 0)
        {
            printf("Siz %d ta so'z to'g'ri topdingiz va %d ta so'z noto'g'ri topdingiz.\n", count, count2);
            break;
        }

        if (strncmp(userTarjima, tarjima, strlen(tarjima)) == 0 &&
            (userTarjima[strlen(tarjima)] == '\n' || userTarjima[strlen(tarjima)] == '\0'))
        {
            printf("To'g'ri!\n");
            count++;
        }
        else
        {
            printf("Noto'g'ri! To'g'ri tarjima: %s\n", tarjima);
            count2++;
        }
    }

    fclose(fp);
}

int main()
{
    int opt;

    while (1)
    {
        printf("\n1. So'z qo'shish\n2. So'zlar bazasini ko'rish\n3. So'z o'yini\n4. Chiqish\n");
        printf("Qaysi bo'limga kirmoxchisiz: ");
        scanf("%d", &opt);
        getchar();

        switch (opt)
        {
        case 1:
        {
            char engword[100], uzbword[100];
            printf("Inglizcha so'z kiriting: ");
            scanf("%s", engword);
            printf("O'zbekcha so'z kiriting: ");
            scanf("%s", uzbword);
            getchar();
            addWord(engword, uzbword);
            printf("So'z qo'shildi!\n");
        }
        break;

        case 2:
            printWord();
            break;

        case 3:
            wordGame();
            break;

        case 4:
            printf("Chiqish...\n");
            exit(0);

        default:
            printf("Xato kiritdingiz!\n");
            break;
        }
    }

    return 0;
}
