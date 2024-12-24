#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int lower, upper, secret, guess;

    // Kullanıcıdan aralık bilgilerini alma
    printf("Tahmin oyunu için istediğiniz aralığı belirleyin.\n");
    printf("Aralığın Alt Sınırı: ");
    scanf("%d", &lower);
    printf("Aralığın Üst Sınırı: ");
    scanf("%d", &upper);

    // Rastgele sayı oluşturma
    srand(time(0));
    secret = rand() % (upper - lower + 1) + lower;

    printf("Belirlediğiniz sayı aralığında bir sayı tahmin ediniz (%d - %d): ", lower, upper);

    // Tahmin döngüsü
    do {
        scanf("%d", &guess);

        // Aralık dışı kontrolü
        if (guess < lower || guess > upper) {
            printf("Lütfen %d ile %d arasında bir sayı giriniz: ", lower, upper);
        } else if (guess > secret) {
            printf("Daha küçük bir sayı girin: ");
        } else if (guess < secret) {
            printf("Daha büyük bir sayı girin: ");
        } else {
            printf("Tebrikler Başardın! Doğru tahmin.\n");
        }
    } while (guess != secret);

    return 0;
}
