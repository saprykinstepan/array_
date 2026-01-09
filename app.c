#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include "arrays.h"

#define SIZE 100

int task11();
int task14(double* array, int size);
int task16();
int task19();

double calculateValue(int x);
int analyze_array();
void tabulateFunction();

int main() {
    setlocale(LC_ALL, "Russian");
    
    puts("================================================");
    puts("Лабораторные работы 11, 14, 16, 19:");
    puts("Работа с массивами и функциями");
    puts("================================================\n");
    
    int size;
    printf("Введите размер массива (до %d): ", SIZE);
    scanf("%d", &size);
    
    if (size <= 0 || size > SIZE) {
        printf("Ошибка: неверный размер массива!\n");
        return -1;
    }
    
    double* array = (double*)malloc(size * sizeof(double));
    if (array == NULL) {
        printf("Ошибка выделения памяти!\n");
        return -1;
    }
    
    // Выполнение лабораторных работ
    task11();
    task14(array, size);
    task16();
    task19();
    
    free(array);
    printf("\nВсе работы выполнены успешно!\n");
    return 0;
}

// Функция для лабораторной работы 11
int task11() {
    printf("\n────────────────────────────────\n");
    printf("Лабораторная работа 11\n");
    printf("────────────────────────────────\n");
    
    float A[10];
    float temp;
    float sum = 0;
    
    // Ввод массива
    printf("Введите 10 элементов массива:\n");
    for (int i = 0; i < 10; i++) {
        printf("a[%d] = ", i);
        scanf("%f", &temp);
        A[i] = temp;
    }
    
    // Вывод таблицы и преобразование
    printf("\n┌────────┬───────────────────┬────────────────┐\n");
    printf("│ Индекс │ Исходное значение │ Новое значение │\n");
    printf("├────────┼───────────────────┼────────────────┤\n");
    
    for (int i = 0; i < 10; i++) {
        float original = A[i];
        // Преобразование: возвести в квадрат
        A[i] = A[i] * A[i];
        sum += A[i];
        printf("│ %6d │ %17.2f │ %14.2f │\n", i, original, A[i]);
    }
    
    printf("└────────┴───────────────────┴────────────────┘\n");
    
    float average = sum / 10;
    printf("\nСреднее арифметическое квадратов: %.2f\n", average);
    
    // Вызов функции анализа массива
    analyze_array();
    
    return 0;
}

// Функция для вычисления значений (вариант из лабы 8)
double calculateValue(int x) {
    // Пример: y = sin(x) + cos(2x)
    return sin(x) + cos(2 * x);
}

// Анализ массива для лабы 11
int analyze_array() {
    double arr[50];
    double pos_sum = 0, neg_sum = 0;
    int pos_count = 0, neg_count = 0;
    
    printf("\nАнализ массива arr[50]:\n");
    printf("─────────────────────────\n");
    
    for (int i = 0; i < 50; i++) {
        arr[i] = calculateValue(i);
        
        if (arr[i] > 0) {
            pos_sum += arr[i];
            pos_count++;
        } else if (arr[i] < 0) {
            neg_sum += arr[i];
            neg_count++;
        }
    }
    
    printf("Сумма положительных: %12.4f\n", pos_sum);
    printf("Сумма отрицательных: %12.4f\n", neg_sum);
    printf("Количество положительных: %8d\n", pos_count);
    printf("Количество отрицательных: %8d\n", neg_count);
    
    if (pos_count > 0) {
        printf("Среднее положительных: %11.4f\n", pos_sum / pos_count);
    }
    
    return 0;
}

// Функция для лабораторной работы 14
int task14(double* array, int size) {
    printf("\n────────────────────────────────\n");
    printf("Лабораторная работа 14\n");
    printf("────────────────────────────────\n");
    
    // Используем функции из arrays.h
    printf("1. Заполнение массива...\n");
    double* filled_array = full_elements(array, size);
    
    printf("\n2. Вывод исходного массива:\n");
    put_elements(filled_array, size);
    
    printf("\n3. Обработка массива...\n");
    double* processed_array = calc_elements(filled_array, size);
    
    printf("\n4. Вывод обработанного массива:\n");
    put_elements(processed_array, size);
    
    printf("\n5. Вычисление суммы элементов...\n");
    double sum = sum_elements(processed_array, 0, size - 1);
    printf("   Сумма всех элементов: %.4f\n", sum);
    
    double search_value;
    printf("\n6. Поиск элемента в массиве\n");
    printf("   Введите значение для поиска: ");
    scanf("%lf", &search_value);
    
    int position = find_element(processed_array, size, search_value);
    if (position != -1) {
        printf("   Элемент найден на позиции: %d\n", position);
    } else {
        printf("   Элемент не найден\n");
    }
    
    return 0;
}

// Функция для лабораторной работы 16
int task16() {
    printf("\n────────────────────────────────\n");
    printf("Лабораторная работа 16\n");
    printf("────────────────────────────────\n");
    
    int array[20];
    srand(time(NULL));
    
    // Заполнение случайными числами
    for (int i = 0; i < 20; i++) {
        array[i] = rand() % 100;
    }
    
    printf("Сгенерированный массив (20 элементов):\n");
    for (int i = 0; i < 20; i++) {
        printf("%3d ", array[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    
    // Поиск максимального и минимального
    int max = array[0], min = array[0];
    double sum = array[0];
    
    for (int i = 1; i < 20; i++) {
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
        sum += array[i];
    }
    
    double average = sum / 20;
    
    printf("\nРезультаты анализа:\n");
    printf("Максимальный элемент: %d\n", max);
    printf("Минимальный элемент: %d\n", min);
    printf("Среднее значение: %.2f\n", average);
    
    // Подсчет элементов выше среднего
    int above_avg = 0;
    for (int i = 0; i < 20; i++) {
        if (array[i] > average) above_avg++;
    }
    printf("Элементов выше среднего: %d\n", above_avg);
    
    return 0;
}

// Функция для лабораторной работы 19
int task19() {
    printf("\n────────────────────────────────\n");
    printf("Лабораторная работа 19\n");
    printf("────────────────────────────────\n");
    
    FILE* file;
    char filename[] = "data.txt";
    int choice;
    
    printf("Работа с файлами:\n");
    printf("1. Создать и записать файл\n");
    printf("2. Чтение из файла\n");
    printf("3. Табулирование функции в файл\n");
    printf("Выберите действие: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            file = fopen(filename, "w");
            if (file) {
                fprintf(file, "Лабораторная работа 19\n");
                fprintf(file, "Тестовые данные:\n");
                for (int i = 1; i <= 10; i++) {
                    fprintf(file, "Значение %d: %.2f\n", i, i * 3.14);
                }
                fclose(file);
                printf("Файл '%s' создан успешно\n", filename);
            } else {
                printf("Ошибка создания файла\n");
            }
            break;
            
        case 2:
            file = fopen(filename, "r");
            if (file) {
                printf("Содержимое файла '%s':\n", filename);
                char line[100];
                while (fgets(line, sizeof(line), file)) {
                    printf("%s", line);
                }
                fclose(file);
            } else {
                printf("Файл не найден. Сначала создайте файл (пункт 1)\n");
            }
            break;
            
        case 3:
            tabulateFunction();
            break;
            
        default:
            printf("Неверный выбор\n");
    }
    
    return 0;
}

// Табулирование функции для лабы 19
void tabulateFunction() {
    FILE* file = fopen("function_table.txt", "w");
    if (!file) {
        printf("Ошибка создания файла\n");
        return;
    }
    
    double start, end, step;
    printf("Табулирование функции f(x) = sin(x) * cos(x)\n");
    printf("Введите начало интервала: ");
    scanf("%lf", &start);
    printf("Введите конец интервала: ");
    scanf("%lf", &end);
    printf("Введите шаг: ");
    scanf("%lf", &step);
    
    fprintf(file, "Табулирование функции f(x) = sin(x) * cos(x)\n");
    fprintf(file, "Интервал: [%.2f, %.2f], шаг: %.4f\n\n", start, end, step);
    fprintf(file, "     x          f(x)\n");
    fprintf(file, "----------------------\n");
    
    int count = 0;
    for (double x = start; x <= end; x += step) {
        double y = sin(x) * cos(x);
        fprintf(file, "%8.4f    %10.6f\n", x, y);
        count++;
    }
    
    fclose(file);
    printf("Табулирование завершено. Создано %d записей в файле 'function_table.txt'\n", count);
}
