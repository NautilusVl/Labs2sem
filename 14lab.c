#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[] = "output.txt";
    char line[100];
    
    // Открываем файл для записи
    file = fopen(filename, "w");
    
    // Проверяем, успешно ли открылся файл
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }
    if (file != NULL) {
        printf("Файл успешно открыт.\n");
    }

    // Вводим произвольное количество строк в файл
    char words[5][100] = {"hello", "world", "how", "are", "you"};
    for (int i = 0; i < 5; i++) {
        fprintf(file, "%sn", words[i]);
    }
    printf("Файл будет закрыт.\n");
    fclose(file);
    
    // Открываем файл для чтения и записи
    file = fopen(filename, "r+");
    
    // Проверяем, успешно ли открылся файл
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    // Чтение каждой строки файла и запись слов в обратном порядке
    while (fgets(line, sizeof(line), file)) {
        int len = strlen(line);
        for (int i = len - 1; i >= 0; i--) {
            if (line[i] == ' ' || line[i] == 'n') {
                for (int j = i + 1; j < len && line[j] != ' ' && line[j] != 'n'; j++) {
                    fprintf(file, "%c", line[j]);
                }
                fprintf(file, " ");
            }
        }
        
        // Заменяем каждую строку в файле на слова в обратном порядке
        fseek(file, -len, SEEK_CUR);
        fprintf(file, "0");
    }

    fclose(file);

    printf("Файл успешно обработан и записан.\n");
    return 0;
}
