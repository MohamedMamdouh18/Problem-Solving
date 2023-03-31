#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n , pair = 0 ;
    scanf("%i" , &n) ;
    char arr[n] ;
    for(int i = 0 ; i < n ; i ++)
    {
        scanf(" %c" , &arr[i]);
        if (i != 0)
        {
            if(arr[i] == arr[i - 1])
            {
                pair ++ ;
            }
        }
    }
    printf("%i" , pair) ;
}
