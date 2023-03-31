#include <stdio.h>
#include <stdlib.h>
 
#define scanfint(x)       int x ; scanf("%i",&x)
#define scanfstr(x , s)   char x[s] ; scanf("%s",&x)
#define scanfsen(x , s)   char x[s] ; gets(x)
#define scanfarr(x , s)   int x[s] ; for(int i = 0 ; i < s ; i ++ ){scanf("%i",&x[i]);}
#define printf(x)         printf("%i",x)
#define mem1(x , s)       memset(x, 0, sizeof(x[0]) *s)
#define mem2(x , s , l)   memset(x, 0, sizeof(x[0]) *s*l)
#define len(s)           strlen(s)
#define rep(i, n)        for(int i = 0; i < n; i++)
#define repf(i, a, b)    for(int i = a; i < b; i++)
 
int main()
{
    scanfint(n) ;
    int a[n] ;
    int b[n] ;
    int sum = 0 ;
    rep(i , n)
    {
        scanf("%i %i" , &a[i] , &b[i]) ;
    }
    rep(i , n)
    {
        rep(j , n)
        {
            if(i != j)
            {
                if(a[j] == b[i])
                {
                    sum ++ ;
                }
            }
        }
    }
    printf(sum) ;
 
}
