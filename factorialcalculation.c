#include <stdio.h>

int main() {
    int n, i;
    unsigned long long factorial;

    printf("Bir sayı giriniz: ");
    scanf("%d", &n);

    while (n < 0) {
        printf("Negatif bir sayı girdiniz, lütfen tekrar bir sayı giriniz.\n");
        printf("Bir sayı giriniz: ");
        scanf("%d", &n);
    }

    factorial = 1;
    for (i = 1; i <= n; ++i) {
        factorial *= i;
    }

    printf("%d sayısının faktöryeli: %llu\n", n, factorial);

    return 0;
}