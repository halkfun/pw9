#include "matrixfunc.h"

int mat_min(const int *matptr, size_t rows, size_t cols)
{
    int min_val = *matptr;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            int current = *(matptr + i * cols + j);
            if (current < min_val)
            {
                min_val = current;
            }
        }
    }
    return min_val;
}

void mat_col_sums(const int *matptr, size_t rows, size_t cols, int *sums)
{
    for (size_t j = 0; j < cols; j++)
    {
        int col_sum = 0;
        for (size_t i = 0; i < rows; i++)
        {
            col_sum += *(matptr + i * cols + j);
        }
        *(sums + j) = col_sum;
    }
}

int mat_rows_range_sum(const int *matptr, size_t rows, size_t cols, size_t k, size_t m, int *total)
{
    if (k > m || m >= rows)
    {
        return -1;
    }

    int sum = 0;
    for (size_t i = k; i <= m; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            sum += *(matptr + i * cols + j);
        }
    }
    *total = sum;
    return 0;
}