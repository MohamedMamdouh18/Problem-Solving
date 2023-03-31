#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int q , s= 0 , d = 0 , t = 1  , y = 0 ;
    bool turnS = true ;
    scanf("%i" , &q);
    int n = q ;
    int arr[n] ;
    for(int i = 0 ; i < q ; i ++)
    {
        scanf("%i" , &arr[i]) ;
    }
    while(t <= q)
    {
        if(arr[y] > arr[n - 1])
        {
            if(turnS)
            {
                s += arr[y];
                turnS = false ;
                y ++ ;
            }
            else
            {
                d += arr[y];
                turnS = true ;
                y ++ ;
            }
        }
        else if(arr[y] < arr[n - 1])
        {
            if(turnS)
            {
                s += arr[n - 1];
                turnS = false ;
                n -- ;
            }
            else
            {
                d += arr[n - 1];
                turnS = true ;
                n -- ;
            }
        }
        else if (y == n - 1)
        {
            if(turnS)
            {
                s += arr[n - 1];
            }
            else
            {
                d += arr[n - 1];
            }
        }
        t ++ ;
    }
    printf("%i %i" , s , d) ;
}

/* Another shorter solution
int main()
{
    int q , a , s= 0 , d = 0 , t = 1  , y = 0 ;
    bool turnS = true ;
    scanf("%i" , &q);
    int n = q ;
    int arr[n] ;
    for(int i = 0 ; i < q ; i ++)
    {
        scanf("%i" , &arr[i]) ;
    }
    while(t <= q)
    {
        if(arr[y] > arr[n - 1])
        {
            a = arr[y] ;
            y ++ ;
        }
        else if(arr[y] < arr[n - 1])
        {
            a = arr[n - 1] ;
            n -- ;
        }
        else if (y == n - 1)
        {
            a = arr[y] ;
        }
        if(turnS)
        {
            s += a ;
        }
        else
        {
            d += a ;
        }
        t ++ ;
        turnS = !turnS ;
    }
    printf("%i %i" , s , d) ;
}*/
