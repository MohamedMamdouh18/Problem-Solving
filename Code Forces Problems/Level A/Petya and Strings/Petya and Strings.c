#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[100] = {0} ;
    char str2[100] = {0} ;
    gets(str1);
    gets(str2);
    int sum1 = 0 ;int sum2 = 0 ;
    for(int i = 0 ; i < strlen(str1) ; i ++)
    {
        str1[i] = toupper(str1[i]);
        str2[i] = toupper(str2[i]);
    }
    for(int i = 0 ; i < strlen(str1) ; i ++)
    {
        if((int)str1[i] > (int)str2[i])
        {
            printf("1");
            return 0 ;
        }
        if((int)str1[i] < (int)str2[i])
        {
            printf("-1");
            return 0 ;
        }
    }
    printf("0") ;

}
