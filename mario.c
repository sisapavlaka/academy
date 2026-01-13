
#include <stdio.h>

int main(void)
{
    int h;

    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    for (int i = 1; i <= h; i++)
    {
        for (int empty = 0; empty < h - i; empty ++)
        {
            printf(" ");
        }
        for (int hashtag = 0; hashtag < i; hashtag ++)
        {
            printf("#");
        }
        printf("\n");
    }
}
