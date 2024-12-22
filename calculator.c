#include <stdio.h>

int main(){
    char op;
    double num1, num2, result;
    int n, i;
    unsigned long long factorial;

    printf("İşleminizi seçin (+, -, *, /, !): ");
    scanf(" %c", &op);

    if (op == '!') {
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
    } else {
        printf("İşlem yapılacak iki sayıyı giriniz: ");
        scanf("%lf %lf", &num1, &num2);

        switch (op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/': 
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    printf("Bölen sıfır olamaz.\n");
                    return 1;
                }
                break;
            default: 
                printf("Geçersiz işlem.\n");
                return 1;
        }

        printf("Sonuç: %.2lf\n", result);
    }

    return 0;
}
