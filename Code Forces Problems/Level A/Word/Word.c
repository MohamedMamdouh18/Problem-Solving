#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char str[100]  ;
    int lower = 0 , upper = 0 ;
    scanf("%s" , &str) ;
    for(int i = 0 ; str[i] != '\0' ; i ++)
    {
        if(isupper(str[i]))
        {
            upper ++ ;
        }
        else
        {
            lower ++ ;
        }
    }
    for(int i = 0 ; i < strlen(str) ; i ++)
    {
        if(lower >= upper )
        {
            str[i] = tolower(str[i]) ;
        }
        else
        {
            str[i] = toupper(str[i]) ;
        }
    }
    printf("%s" , str);
}
