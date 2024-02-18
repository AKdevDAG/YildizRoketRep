#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kelime_kontrol(char *tahmin, char *cevap)
{
    int i, j;
    int uzunluk = strlen(cevap);
    int olmayan[6] = {0}; // Tüm elemanları başlangıçta 0 yap

    printf("Dogru Yerde Olan Harfler: ");
    for (i = 0; i < uzunluk; i++)
    {
        if (tahmin[i] == cevap[i])
        {
            printf("%c", tahmin[i]);
            olmayan[i] = 1; // Doğru yerdeki harfi işaretle
        }
        else
        {
            printf("_");
        }
    }

    printf("\nOlan Fakat Yeri Yanliş Olan Harfler: ");
    for (i = 0; i < uzunluk; i++)
    {
        if (!olmayan[i])
        {
            for (j = 0; j < uzunluk; j++)
            {
                if (tahmin[i] == cevap[j])
                {
                    printf("%c ", tahmin[i]);
                    break;
                }
            }
        }
    }

    printf("\n");
}

int main()
{
    char cevap[6] = "ROKET";
    char tahmin[6];
    int sayac = 0;

    while (strcmp(tahmin, cevap) != 0)
    {
        printf("5 HARFLI TAHMINIZI GIRINIZ: ");
        scanf("%s", tahmin);
        kelime_kontrol(tahmin, cevap);
        sayac ++;
    }

    printf("%d. Denemede Doğru tahmin: %s\n", sayac, cevap);

    return 0;
}