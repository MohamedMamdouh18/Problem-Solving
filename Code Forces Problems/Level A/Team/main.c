#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , sum = 0 ,sol = 0 ;
    scanf("%i" , &n);
    int probs [n * 3] ;

    for(int i = 0 ; i < n * 3 ; i ++)
    {
        scanf("%i" , &probs[i]);
    }
    for(int i = 0 ; i < n * 3 ; i ++)
    {
        if(probs[i] == 1)
        {
            sum ++ ;
        }
        if((i + 1) % 3 == 0)
        {
            if(sum >= 2)
            {
                sol ++ ;
            }
            sum = 0 ;
        }
    }
    printf("%i" , sol) ;
}



/*another smaller solution:
int main()
{
    int n ,x , y , z , sol ;
    scanf("%i" , &n);
    for(int i = 0 ; i < n ; i ++)
    {
        scanf("%i %i %i" , &x , &y , &z);
        if(x + y + z >= 2)
        {
            sol++ ;
        }
    }
    printf("%i" , sol) ;
}*/
