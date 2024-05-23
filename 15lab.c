#include <stdio.h>
#include <string.h>

struct Route {
    char end_point[50];
    int plane_number;
    char plane_type[50];
    
};

int main() {
    FILE *file;
    struct Route route;
    char search_point[50];
    int found = 0;

    file = fopen("Spravka.dat", "wb");
    if (file == NULL) {
        printf("Ошибка при создании файла.\n");
        return 1;
    }

    // Записываем данные о маршрутах в файл
    struct Route routes[] = {
        {"Moscov", 1, "firsttype"},
        {"Spb", 2, "secondtype"},
        {"Moscov", 3, "thirdtype"}
    };

    fwrite(routes, sizeof(struct Route), 3, file);
    fclose(file);

    // Открываем файл для чтения
    file = fopen("Spravka.dat", "rb");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    // Вводим пункт для поиска
    printf("Введите название пункта маршрута: ");
    scanf("%s", search_point);

    // Ищем маршруты, начинающиеся или заканчивающиеся в заданном пункте
    while (fread(&route, sizeof(struct Route), 1, file) == 1) {
        if (strcmp(route.end_point, search_point) == 0) {
            printf("Номер рейса %d: %s - %s\n", route.plane_number, route.end_point, route.plane_type);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Маршрутов с указанным пунктом не найдено.\n");
    }

    fclose(file);

    return 0;
}