#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , A = 0 , D = 0 ;
    char input ;
    scanf("%i" , &n) ;
    for(int i = 0 ; i < n ; i ++)
    {
        scanf(" %c" , &input) ;
        if(input == 'A')
        {
            A ++ ;
        }
        else
        {
            D ++ ;
        }
    }
    if(A > D)
    {
        printf("Anton");
    }
    else if(A < D)
    {
        printf("Danik");
    }
    else if (A == D)
    {
        printf("Friendship");
    }

}
