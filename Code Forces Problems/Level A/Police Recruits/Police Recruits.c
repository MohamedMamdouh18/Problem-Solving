#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n , untreat = 0 , force = 0 , event;
    scanf("%i" , &n);
    for(int i = 0 ; i < n ; i ++)
    {
        scanf("%i" , &event);
        if(event > 0)
        {
            force += event ;
        }
        else
        {
            if(force == 0 || (force + event) < 0)
            {
                untreat += abs(force + event) ;
            }
            else
            {
                force += event ;
            }
        }
    }
    printf("%i" , untreat);
}
