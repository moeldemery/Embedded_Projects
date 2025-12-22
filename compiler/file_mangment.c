#include <stdio.h>
#include <stdlib.h>
#include <math.h>


FILE *fp;
char line[1000] ;
size_t len = 0;
ssize_t read;

int main(void)
{
    fp = fopen("test.c", "r");

     if (fp == NULL)
     {
         printf("FILE NOT FOUND.");
         return 0;
     }

     while(fgets(line,sizeof(line),fp) != NULL)
     {
          fputs("//",stdout);
          fputs(line,stdout);

     }


    fclose(fp);
    return 0;
}


