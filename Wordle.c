#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//kelime kontrol kısmı
void kelime_kontrol(char *tahmin, char *cevap)
{
    int i, j;
    int uzunluk = strlen(cevap);
    // Tüm elemanları başlangıçta 0 yaptık
    int olmayan[6] = {0}; 

    printf("Dogru Yerde Olan Harfler: ");
    for (i = 0; i < uzunluk; i++)
    {
        if (tahmin[i] == cevap[i])
        {
            printf("%c", tahmin[i]);
            // Doğru yerdeki harfi işaretledik
            olmayan[i] = 1; 
        }
        else
        {
            printf("_");
        }
    }
    //Cevapta ve tahminde olan ama yeri yanlış olan harfleri yazdırma
    printf("\nOlan Fakat Yeri Yanliş Olan Harfler: ");
    for (i = 0; i < uzunluk; i++)
    {
        if (olmayan[i] == 0) //dogru yerde olmayan harfler 
        {
            for (j = 0; j < uzunluk; j++)
            {
                if (tahmin[i] == cevap[j]) //dogru yerde olmasa bile bu harf başka bir yerde var mı diye baıyoruz
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

    while (strcmp(tahmin, cevap) != 0) //tahmin ve cevap = olmaya kadar devam etsin istiyoruz
    {
        printf("5 HARFLI TAHMINIZI GIRINIZ: ");
        scanf("%s", tahmin);
        kelime_kontrol(tahmin, cevap);
        sayac ++;
    }

    printf("%d. Denemede Doğru tahmin: %s\n", sayac, cevap);

    return 0;
}
