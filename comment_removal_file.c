#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void comment_removal_file(char *p)
{

FILE *fp;
char ifile[50];
int len=strlen(p);
strncpy(ifile,p,len-2);
strcat(ifile,".i");

fp=fopen(ifile,"r+");

if(fp==0)
{
printf("no file found\n");
return;
}

char c1=0,c2=0,cha;
while((cha=fgetc(fp))!=EOF)
{
 c1=c2;
 c2=cha;
   if(c1=='/' && c2=='/')
    {
     fseek(fp,-2,SEEK_CUR);
     while((cha=fgetc(fp))!='\n' && cha!=EOF){
      fseek(fp,-1,SEEK_CUR);
       fputc(' ',fp);
      }
    }
   if (c1 == '/' && c2 == '*')
     {
         fseek(fp, -2, SEEK_CUR);
         char prev = 0, curr = 0;
         while ((curr = fgetc(fp)) != EOF) {
             fseek(fp, -1, SEEK_CUR);
             fputc(' ', fp);
             if (prev == '*' && curr == '/')
                 break;
             prev = curr;
         }
     }
}
fclose(fp);

}



