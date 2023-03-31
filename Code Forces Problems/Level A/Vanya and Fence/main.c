#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , h , height , width = 0;
    scanf("%i %i" , &n , &h);
    for(int i = 0 ; i < n ; i ++)
    {
        scanf("%i" , &height) ;
        if(height <= h)
        {
            width ++ ;
        }
        else
        {
            width += 2 ;
        }
    }

    printf("%i" , width) ;
}
