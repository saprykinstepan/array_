#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arrays.h"

/**
 * Функция f(x) для работы 8
 * Ваш вариант: y = e^(-0.1x) * sin(x)
 */
double func(double x) {
    return exp(-0.1 * x) * sin(x);
}

/**
 * Заполнение массива значениями функции
 */
double* full_elements(double* ptr_array, int n) {
    if (ptr_array == NULL || n <= 0) {
        return NULL;
    }
    
    double start = 0.0;
    double end = 10.0;
    double step = (end - start) / (n - 1);
    
    for (int i = 0; i < n; i++) {
        double x = start + i * step;
        ptr_array[i] = func(x);
    }
    
    return ptr_array;
}

/**
 * Печать элементов массива
 */
int put_elements(double* ptr_array, int n) {
    if (ptr_array == NULL || n <= 0) {
        printf("Ошибка: пустой массив\n");
        return 0;
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        printf("[%2d]: %8.4f  ", i, ptr_array[i]);
        count++;
        
        // Перенос строки каждые 5 элементов
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    
    // Если последняя строка не завершена
    if (n % 5 != 0) {
        printf("\n");
    }
    
    return count;
}

/**
 * Обработка элементов массива (возведение в квадрат)
 */
double* calc_elements(double* ptr_array, int n) {
    if (ptr_array == NULL || n <= 0) {
        return NULL;
    }
    
    for (int i = 0; i < n; i++) {
        ptr_array[i] = ptr_array[i] * ptr_array[i];
    }
    
    return ptr_array;
}

/**
 * Вычисление суммы элементов массива
 */
double sum_elements(double* ptr_array, int begin, int end) {
    if (ptr_array == NULL || begin < 0 || end < begin) {
        return 0.0;
    }
    
    double sum = 0.0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    
    return sum;
}

/**
 * Поиск элемента в массиве
 */
int find_element(double* ptr_array, int n, double element) {
    if (ptr_array == NULL || n <= 0) {
        return -1;
    }
    
    for (int i = 0; i < n; i++) {
        // Сравнение с учетом погрешности
        if (fabs(ptr_array[i] - element) < 0.0001) {
            return i;
        }
    }
    
    return -1;
}

/**
 * Нахождение максимального элемента до позиции K
 */
double find_max_before_k(double* ptr_array, int n, int K) {
    if (ptr_array == NULL || n <= 0 || K < 0 || K >= n) {
        return -1.0;
    }
    
    double max = ptr_array[0];
    for (int i = 1; i <= K; i++) {
        if (ptr_array[i] > max) {
            max = ptr_array[i];
        }
    }
    
    return max;
}

/**
 * Подсчет положительных элементов
 */
int count_positive_elements(double* ptr_array, int n) {
    if (ptr_array == NULL || n <= 0) {
        return 0;
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] > 0) {
            count++;
        }
    }
    
    return count;
}

/**
 * Вычисление среднего арифметического
 */
double calculate_average(double* ptr_array, int n) {
    if (ptr_array == NULL || n <= 0) {
        return 0.0;
    }
    
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += ptr_array[i];
    }
    
    return sum / n;
}

/**
 * Нахождение минимального элемента
 */
double find_min_element(double* ptr_array, int n) {
    if (ptr_array == NULL || n <= 0) {
        return 0.0;
    }
    
    double min = ptr_array[0];
    for (int i = 1; i < n; i++) {
        if (ptr_array[i] < min) {
            min = ptr_array[i];
        }
    }
    
    return min;
}

/**
 * Сортировка массива по возрастанию (пузырьковая сортировка)
 */
double* sort_array(double* ptr_array, int n) {
    if (ptr_array == NULL || n <= 1) {
        return ptr_array;
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ptr_array[j] > ptr_array[j + 1]) {
                double temp = ptr_array[j];
                ptr_array[j] = ptr_array[j + 1];
                ptr_array[j + 1] = temp;
            }
        }
    }
    
    return ptr_array;
}

/**
 * Реверс массива
 */
double* reverse_array(double* ptr_array, int n) {
    if (ptr_array == NULL || n <= 1) {
        return ptr_array;
    }
    
    for (int i = 0; i < n / 2; i++) {
        double temp = ptr_array[i];
        ptr_array[i] = ptr_array[n - 1 - i];
        ptr_array[n - 1 - i] = temp;
    }
    
    return ptr_array;
}

/**
 * Копирование массива
 */
double* copy_array(double* src, double* dest, int n) {
    if (src == NULL || dest == NULL || n <= 0) {
        return NULL;
    }
    
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    
    return dest;
}
