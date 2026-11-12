#include "header.h"

typedef struct macro
{
	char name[50];
	char body[50];
	struct macro *next;
}macro;

macro *head=0;

void macro_handler(char *p)
{
	//printf("%s\n",p);
	char ifile[50];
	int len=strlen(p),tell;
	len = len-2;

	strncpy(ifile,p,len);
	ifile[len]='\0';
	strcat(ifile,".i");
//	printf("%s\n",ifile);
	FILE *fr,*fw,*ft;
	fr = fopen(ifile,"r");
	if(fr==0)
		return;

	fw = fopen("temp","w");
	char line[1100],t[1000],str[100];


	while(fgets(line,sizeof(line),fr))
	{
		if(strstr(line,"#define"))
		{
			add();
			sscanf(line+7, "    %s %s", head->name,head->name);

			/*
			   tell= ftell(fr);
			   while(fgets(fr,"%s",str)!=EOF)
			   {
			   if(strstr(str,name)==0)
			   fprintf(fw,"%s",value);
			   else
			   fprintf(fw,"%s",str);

			   }
			   fseek(fr,tel
			 */
		}
	}
/*   while(head){
    printf("#define  %s  %s\n",head->name,head->body);
    head=head->next;
   }
*/


}

//printf("%s\n",ifile);




void add(){
	macro *new;
	new=malloc(sizeof(macro));
	new->next=head;
	head=new; 
}  

