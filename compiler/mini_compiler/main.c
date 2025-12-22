
#include"file_manger.h"


#define BUFFER_SIZE 100

char line[BUFFER_SIZE] ;


int main(void)
{

        char *x= CreateFile();
     //printf("%c %c %c" , *x,*(x+12),*(x+6));
/*
     GetLine (line,BUFFER_SIZE);
     printf("%s" , line);
     GetLine (line,BUFFER_SIZE);
     printf("%s" , line);
     GetLine (line,BUFFER_SIZE);*/
     printf("%s" , x);

     //CloseFile(x);

    return 0;
}

