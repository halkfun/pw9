#include <stddef.h>

int mat_min(const int *matptr, size_t rows, size_t cols);
void mat_col_sums(const int *matptr, size_t rows, size_t cols, int *sums);
int mat_rows_range_sum(const int *matptr, size_t rows, size_t cols, size_t k, size_t m, int *total);