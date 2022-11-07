#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max_row, max_column, max_n;
    scanf("%d", &max_row);
    scanf("%d", &max_column);
    scanf("%d", &max_n);

    char *mat = (char *)malloc(sizeof(char *) * max_row * max_column);
    for (int r = 0; r < max_row; ++r)
    {
        for (int c = 0; c < max_column; ++c)
        {
            int n = 0;

            float x = 0, y = 0, tmp;
            while ((x * x + y * y) < 4 && ++n < max_n)
            {
                tmp = x * x - y * y + ((float)c * 2 / max_column - 1.5);
                y = 2 * x * y + ((float)r * 2 / max_row - 1);
                x = tmp;
            }

            mat[r * max_column + c] = (n == max_n ? '#' : '.');
        }
    }

    for (int r = 0; r < max_row; ++r)
    {
        for (int c = 0; c < max_column; ++c)
            printf("%c", mat[r * max_column + c]);
        printf("\n");
    }
}