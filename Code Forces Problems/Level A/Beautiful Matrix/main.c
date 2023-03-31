#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int mat[5][5];
    int row , col ;
    for(int i = 0 ; i < 5 ; i ++)
    {
        for(int j = 0 ; j < 5 ; j ++)
        {
            scanf("%i" , &mat[i][j]);
            if(mat[i][j] == 1)
            {
                row = i ;
                col = j ;
            }
        }
    }
    int moves = abs(row - 2) + abs(col - 2) ;
    printf("%i" , moves) ;
}
