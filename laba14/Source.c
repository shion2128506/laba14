#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 100

void task1();
void task2();
void task3();
void task4();

int main()
{
    setlocale(LC_ALL, "RUS");
    task1();
    task2();
    task3();
    task4();
}

double* full_elements(double* ptr_array, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("array[%d] = ", i);
        scanf("%lf", &ptr_array[i]);
    }
    return ptr_array;
}

int put_elements(double* ptr_array, int n)
{
    int i;
    printf("Массив: ");
    for (i = 0; i < n; i++)
        printf("%.2f ", ptr_array[i]);
    printf("\n");
    return n;
}

double* calc_elements(double* ptr_array, int n)
{
    int i;
    for (i = 0; i < n; i++)
        ptr_array[i] *= 2.0;
    return ptr_array;
}

double sum_elements(double* ptr_array, int begin, int end)
{
    double sum = 0.0;
    int i;
    for (i = begin; i <= end; i++)
        sum += ptr_array[i];
    return sum;
}

int find_element(double* ptr_array, int n, double element)
{
    int i;
    for (i = 0; i < n; i++)
        if (ptr_array[i] == element)
            return i;
    return -1;
}

double max_before_k(double* ptr_array, int n, int K)
{
    double max;
    int i;

    if (n <= 0) return 0;
    if (K >= n) K = n - 1;
    if (K < 0)  K = 0;

    max = ptr_array[0];
    for (i = 1; i <= K; i++)
        if (ptr_array[i] > max)
            max = ptr_array[i];
    return max;
}

double max_before_k_full(double* ptr_array, int n, int K)
{
    return max_before_k(ptr_array, n, K);
}

void task1()
{
    static double array[N];
    int size;

    printf("Введите размер массива > ");
    scanf("%d", &size);
    if (size < 1 || size > N) { printf("Некорректный размер!\n"); return; }

    full_elements(array, size);
    printf("\nИсходный массив:\n");
    put_elements(array, size);

    calc_elements(array, size);
    printf("\nПосле обработки:\n");
    put_elements(array, size);
}

void task2()
{
    static double array[N];
    int size, begin, end, idx;
    double a, s;

    printf("Введите размер массива > ");
    scanf("%d", &size);
    if (size < 1 || size > N) { printf("Некорректный размер!\n"); return; }

    full_elements(array, size);
    put_elements(array, size);

    printf("Введите begin и end (индексы) > ");
    scanf("%d %d", &begin, &end);
    if (begin < 0) begin = 0;
    if (end >= size) end = size - 1;
    if (begin > end) { int t = begin; begin = end; end = t; }

    s = sum_elements(array, begin, end);
    printf("Сумма элементов с %d по %d = %.2f\n", begin, end, s);

    printf("Введите искомый элемент a > ");
    scanf("%lf", &a);
    idx = find_element(array, size, a);
    if (idx == -1)
        printf("Элемент %.2f не найден\n", a);
    else
        printf("Элемент %.2f найден по индексу %d\n", a, idx);
}

void task3()
{
    static double array[N];
    int size, K;
    double maxv;

    printf("Введите размер массива > ");
    scanf("%d", &size);
    if (size < 1 || size > N) { printf("Некорректный размер!\n"); return; }

    full_elements(array, size);
    put_elements(array, size);

    printf("Введите позицию K > ");
    scanf("%d", &K);

    maxv = max_before_k(array, size, K);
    printf("Максимум до позиции %d включительно = %.2f\n", K, maxv);
}

void task4()
{
    static double array[N];
    int size, K;
    double maxv;

    printf("Введите размер массива > ");
    scanf("%d", &size);
    if (size < 1 || size > N) { printf("Некорректный размер!\n"); return; }

    full_elements(array, size);
    put_elements(array, size);

    printf("Введите позицию K > ");
    scanf("%d", &K);

    maxv = max_before_k_full(array, size, K);
    printf("Максимум среди элементов до позиции %d включительно = %.2f\n", K, maxv);
}
