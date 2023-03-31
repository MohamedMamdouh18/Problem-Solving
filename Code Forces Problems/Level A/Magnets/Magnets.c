#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , pairs = 1 ;
    scanf("%i" , &n) ;
    int arr[n];
    for (int i = 0 ; i < n ; i ++)
    {
        scanf("%i" , &arr[i]) ;
        if (i != 0)
        {
            if (arr[i] + arr[i - 1] == 11)
            {
                pairs ++ ;
            }
        }
    }
    printf("%i" , pairs) ;
}
