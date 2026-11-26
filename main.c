#include <stdio.h>
#include "matrixfunc.h"

#define MAX_DIM 10

void clear_input(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}

int main(void)
{
    int matrix[MAX_DIM * MAX_DIM];
    int col_sums[MAX_DIM];
    size_t rows = 0;
    size_t cols = 0;
    int is_sized = 0;
    int is_filled = 0;
    char choice;

    while (1)
    {
        printf("\na - Задать размер матрицы (строки, столбцы)\n");
        printf("b - Заполнить матрицу\n");
        printf("c - Представление матрицы (значения, адреса элементов)\n");
        printf("d - Определение минимального элемента матрицы\n");
        printf("e - Вычисление суммы элементов каждого столбца матрицы\n");
        printf("f - Вычисление суммы элементов строк в диапазоне индексов k-m\n");
        printf("g - Выход\n");
        printf("Выберите пункт: ");

        if (scanf(" %c", &choice) != 1)
        {
            printf("\nЗавершение работы (EOF).\n");
            break;
        }
        clear_input();

        if (choice == 'g')
        {
            printf("Выход из программы.\n");
            break;
        }

        switch (choice)
        {
            case 'a':
                printf("Введите количество строк и столбцов (от 1 до %d): ", MAX_DIM);
                if (scanf("%zu %zu", &rows, &cols) != 2 || rows == 0 || rows > MAX_DIM || cols == 0 || cols > MAX_DIM)
                {
                    printf("Ошибка: некорректные размеры матрицы.\n");
                    rows = 0;
                    cols = 0;
                    is_sized = 0;
                    is_filled = 0;
                }
                else
                {
                    is_sized = 1;
                    is_filled = 0;
                    printf("Размер установлен: %zu x %zu.\n", rows, cols);
                }
                clear_input();
                break;

            case 'b':
                if (!is_sized)
                {
                    printf("Сначала задайте размер матрицы (пункт a).\n");
                    break;
                }
                printf("Введите %zu элементов матрицы построчно:\n", rows * cols);
                is_filled = 1;
                for (size_t i = 0; i < rows && is_filled; i++)
                {
                    for (size_t j = 0; j < cols; j++)
                    {
                        if (scanf("%d", matrix + i * cols + j) != 1)
                        {
                            printf("Ошибка ввода элемента.\n");
                            is_filled = 0;
                            break;
                        }
                    }
                }
                clear_input();
                if (is_filled)
                {
                    printf("Матрица успешно заполнена.\n");
                }
                break;

            case 'c':
                if (!is_filled)
                {
                    printf("Сначала задайте размер (a) и заполните матрицу (b).\n");
                    break;
                }
                printf("Матрица (значение [адрес]):\n");
                for (size_t i = 0; i < rows; i++)
                {
                    for (size_t j = 0; j < cols; j++)
                    {
                        const int *elem_ptr = matrix + i * cols + j;
                        printf("%6d [%p]  ", *elem_ptr, (const void *)elem_ptr);
                    }
                    printf("\n");
                }
                break;

            case 'd':
                if (!is_filled)
                {
                    printf("Сначала задайте размер (a) и заполните матрицу (b).\n");
                    break;
                }
                printf("Минимальный элемент матрицы: %d\n", mat_min(matrix, rows, cols));
                break;

            case 'e':
                if (!is_filled)
                {
                    printf("Сначала задайте размер (a) и заполните матрицу (b).\n");
                    break;
                }
                mat_col_sums(matrix, rows, cols, col_sums);
                for (size_t j = 0; j < cols; j++)
                {
                    printf("Столбец %zu: сумма = %d\n", j, *(col_sums + j));
                }
                break;

            case 'f':
                if (!is_filled)
                {
                    printf("Сначала задайте размер (a) и заполните матрицу (b).\n");
                    break;
                }
                size_t k, m;
                int range_sum = 0;
                printf("Введите начальный и конечный индексы строк k и m (от 0 до %zu): ", rows - 1);
                if (scanf("%zu %zu", &k, &m) != 2)
                {
                    printf("Ошибка ввода индексов.\n");
                    clear_input();
                    break;
                }
                clear_input();
                if (mat_rows_range_sum(matrix, rows, cols, k, m, &range_sum) == 0)
                {
                    printf("Сумма элементов строк с %zu по %zu: %d\n", k, m, range_sum);
                }
                else
                {
                    printf("Ошибка: недопустимый диапазон индексов (должно быть 0 <= k <= m < %zu).\n", rows);
                }
                break;

            default:
                printf("Неизвестный пункт меню. Выберите букву от a до g.\n");
                break;
        }
    }

    return 0;
}