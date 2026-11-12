#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"

void file_inclusion(char **p,int line,char *q)
{
int i,len,j=0,n,c=0,k;
char **h,*ch,*ch1,*ch2,*m,*s="#include",ifile[100];
len=strlen(s);

int le=strlen(q);
strncpy(ifile,q,le-2);
strcat(ifile,".i");


for(i=0;i<line;i++)
{

 if(strstr(p[i],s))
   c++;

}

h=malloc(sizeof(char *)*c);

for(i=0;i<c;i++)
h[i]=malloc(20);

j=0;
for(i=0;i<line;i++)
{   

if(strstr(p[i],s))
  { 
    ch1=strchr(p[i],'<');
    ch2=strchr(p[i],'>');
   if(ch1==0||ch2==0)
    {
    ch1=strchr(p[i],'"');
    if(ch1!=NULL)
    ch2=strchr(ch1+2,'"');
    }
  
  if(ch1 == 0 || ch2 == 0)
        continue;
  
    ch2--;

   if(ch1==0 || ch2==0)
    continue;     
   
    n=ch2-ch1;
 
     for(k=0;k<n+1;k++)
        h[j][k]=ch1[k];

      h[j][k]='\0';
    // strcpy(ch,ch1); 
 //  strcpy(h[j],ch);
   j++;    
  }  
}

//for(i=0;i<c;i++)
//printf("%s\n",h[i]);


FILE *fp,*fw;
int l;
char path[50];
fw=fopen(ifile,"w");
///looop

for(i=0;i<c;i++){

if(h[i][0]=='<')
sprintf(path,"/usr/include/%s",&h[i][1]);
else
strcpy(path,&h[i][1]);


fp = fopen(path,"r");
if(fp == NULL)
{
    printf("Header opening failed\n");
    continue;
}

while((l=fgetc(fp))!=EOF)
fputc(l,fw);

fclose(fp);
}
/////////////////////////////////////////////

  int o=1;
  char *add;
  for(i=0;i<line;i++){
  if(!(add=strstr(p[i],"int main")) && o)
  continue;
  o=0;

  fprintf(fw,"%s",p[i]);
 }

rewind(fw);
fclose(fw);
}






