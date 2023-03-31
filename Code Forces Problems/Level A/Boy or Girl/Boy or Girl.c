#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[100] = {0};
    gets(name);
    int sum = strlen(name);
    for(int i = 0 ; i < sum ; i ++)
    {
        for(int j = i + 1 ; j < sum ; j ++)
        {
            if(name[i] == name[j])
            {
                for(int z = j ; z < sum - 1 ; z ++)
                {
                    name[z] = name[z + 1];
                }
                sum -- ;
                j -- ;
            }

        }
    }
    if(sum % 2 == 0)
    {
        printf("CHAT WITH HER!") ;
    }
    else
    {
        printf("IGNORE HIM!") ;
    }
}
