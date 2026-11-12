#include "header.h"

int main(int argc,char **argv)
{

	if(argc!=2)
	{
		printf("usage: ./mypreprocessor filename\n");
		return 1;
	}

	FILE *fp;
	fp=fopen(argv[1],"r");

	if(fp==0)
	{
		printf("file not found!!\n");
		return 1;
	}
	int i,c=0,c_max=0,line=0;
	char **p,ch;
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch=='\n')
		{
			c=0;
			line++;
		}
		else
			c++;
		if(c > c_max)
			c_max=c;
	}
	rewind(fp);
	p = malloc(sizeof(char *)*line);
	for(i=0;i<line;i++)
		p[i]=malloc(sizeof(char)*(c_max+2));
	i=0;
	while(fgets(p[i],c_max+3,fp))
		i++;
	fclose(fp);
        
	file_inclusion(p,line,argv[1]);
        comment_removal_file(argv[1]);
        macro_handler(argv[1]);
//printf("%s\n",p);
        
///////////////////////////////////////
         char ifile[50];
          int len=strlen(argv[1]);
          len = len-2;
  
          strncpy(ifile,argv[1],len);
          ifile[len]='\0';
          strcat(ifile,".i");

printf("\n>>>>>>>%s file generated<<<<<<<\n\n",ifile);
       

return 0;
}



















	/*
	   FILE *fw;
	   int f=1;
	   char *add;
	   fw=fopen("inputfile.i","a");
	   for(i=0;i<line;i++){
	   if(!(add=strstr(p[i],"int main")) && f)
	   continue;
	   f=0;
	   fprintf(fw,"%s",p[i]);
	   }

	 */
	/////////////////////
//	for(i=0;i<line;i++)
//		printf("%s",p[i]);


//	return 0;
//}


