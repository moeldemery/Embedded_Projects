

#include"file_manger.h"

static FILE *fp;

char * CreateFile (void)
{
    fp = fopen("program.c", "rb");

     if (fp == NULL)
     {
         printf("FILE NOT FOUND.");
         return 0;
     }

     fseek(fp, 0, SEEK_END);
     long fsize = ftell(fp);
     fseek(fp, 0, SEEK_SET);

     char *string = malloc(fsize + 2);
     fread(string, 1, fsize, fp);
     //printf(" %s",string);
     *(string+fsize+1)=-1;
     //printf(" %d",*(string+fsize));

     fclose(fp);

     return string;
}

void GetLine (char * Buffer,int size_)
{

    fp = fopen("program.c", "r");
    static int curser =1;
    for(int i=0;i<curser;i++)
    {
        fgets(Buffer,sizeof(Buffer)*size_,fp) ;
    }
    curser++;

    fclose(fp);

}

void CloseFile(char * FileAddress)
{
    free(FileAddress);
}
