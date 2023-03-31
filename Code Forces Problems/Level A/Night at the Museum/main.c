#include <stdio.h>
#include <stdlib.h>

#define scans(x , s) char x[s] ; scanf("%s",&x)
#define len(X)    strlen(X)
#define rep(I, N)  for(int I = 0; I < N; I++)
#define repf(I, A, B) for(int I = A; I < B; I++)

int min(a,b)
{
    if(a > b)
    {
        return b ;
    }
    else
    {
        return a ;
    }
}

int main()
{
    scans(x , 100) ;
    int sum = 0 , pos = 'a' , aga , with ;

    rep(i , len(x))
    {
        sum += min (abs(pos - x[i]) , 26 - abs(pos - x[i]));
        pos = x[i] ;
    }
    printf("%i" , sum) ;
}
