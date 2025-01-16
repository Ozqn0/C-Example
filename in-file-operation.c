#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    char filename[100];
    char sentence[256];
    char reversed[256];
    int fd;

    printf("Lütfen bir dosya adı girin: ");
    scanf("%s", filename);

    strcat(filename, ".txt");

    printf("Kendinizi bir cümle ile tanıtın: ");
    getchar(); 
    fgets(sentence, sizeof(sentence), stdin);

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Dosya açılamadı");
        return 1;
    }

    ssize_t bytes_written = write(fd, sentence, strlen(sentence));
    if (bytes_written == -1) {
        perror("Dosyaya yazma başarısız oldu");
        close(fd);
        return 1;
    }

    if (close(fd) == -1) {
        perror("Dosya kapama başarısız oldu");
        return 1;
    }

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Dosya açılamadı");
        return 1;
    }


    ssize_t bytes_read = read(fd, sentence, sizeof(sentence) - 1);
    if (bytes_read == -1) {
        perror("Dosyadan okuma başarısız oldu");
        close(fd);
        return 1;
    }
    sentence[bytes_read] = '\0'; 


    if (close(fd) == -1) {
        perror("Dosya kapama başarısız oldu");
        return 1;
    }


    size_t len = strlen(sentence);
    for (size_t i = 0; i < len; i++) {
        reversed[i] = sentence[len - i - 1];
    }
    reversed[len] = '\0'; 


    printf("Dosyadaki verinin tersi: %s\n", reversed);

    return 0;
}