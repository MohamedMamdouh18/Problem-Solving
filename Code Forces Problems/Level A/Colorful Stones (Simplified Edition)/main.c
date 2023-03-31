#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char stones[50] ;
    gets(stones) ;
    char instr [50] ;
    gets(instr) ;
    int lenght = 1 ;
    for(int i = 0 ; i < strlen(instr) ; i ++)
    {
        if(instr[i] == stones[lenght - 1])
        {
            lenght ++ ;
        }
    }
    printf("%i" , lenght) ;

}
