/**
 * arrays.h - Заголовочный файл для работы с массивами
 * Функции для работы с одномерными массивами double
 */

#ifndef ARRAYS_H
#define ARRAYS_H

#include <math.h>

/**
 * Функция для получения значений (вариант из работы 8)
 * @param x аргумент функции
 * @return значение функции f(x)
 */
double func(double x);

/**
 * Заполнение массива значениями функции
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на заполненный массив
 */
double* full_elements(double* ptr_array, int n);

/**
 * Печать элементов массива
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return количество выведенных элементов
 */
int put_elements(double* ptr_array, int n);

/**
 * Обработка элементов массива согласно индивидуальному варианту
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на обработанный массив
 */
double* calc_elements(double* ptr_array, int n);

/**
 * Вычисление суммы элементов массива в диапазоне [begin, end]
 * @param ptr_array указатель на массив
 * @param begin начальный индекс (включительно)
 * @param end конечный индекс (включительно)
 * @return сумма элементов
 */
double sum_elements(double* ptr_array, int begin, int end);

/**
 * Поиск элемента в массиве
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @param element искомый элемент
 * @return индекс найденного элемента или -1 если не найден
 */
int find_element(double* ptr_array, int n, double element);

/**
 * Нахождение максимального элемента до позиции K
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @param K позиция, до которой искать (включительно)
 * @return максимальное значение или -1 при ошибке
 */
double find_max_before_k(double* ptr_array, int n, int K);

/**
 * Подсчет положительных элементов в массиве
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return количество положительных элементов
 */
int count_positive_elements(double* ptr_array, int n);

/**
 * Вычисление среднего арифметического элементов массива
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return среднее значение
 */
double calculate_average(double* ptr_array, int n);

/**
 * Нахождение минимального элемента в массиве
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return минимальное значение
 */
double find_min_element(double* ptr_array, int n);

/**
 * Сортировка массива по возрастанию
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на отсортированный массив
 */
double* sort_array(double* ptr_array, int n);

/**
 * Реверс массива (переворот)
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на перевернутый массив
 */
double* reverse_array(double* ptr_array, int n);

/**
 * Копирование массива
 * @param src исходный массив
 * @param dest целевой массив
 * @param n размер массивов
 * @return указатель на скопированный массив
 */
double* copy_array(double* src, double* dest, int n);

#endif
