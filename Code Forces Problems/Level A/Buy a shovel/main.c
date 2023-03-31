#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k , r ;
    scanf("%i %i" , &k , &r) ;

    int least ;
    for(int i = 1 ; i < 100 ; i ++)
    {
        if((k * i) % 10 == 0)
        {
            least = i ;
            break ;
        }
        if((k * i - r) % 10 == 0)
        {
            least = i ;
            break ;
        }
    }
    printf("%i" , least) ;
}
