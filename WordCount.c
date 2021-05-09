#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
	FILE *fp;
	int len;
	fp=fopen("exam.txt","r");
	if(fp==NULL)
	{
		printf("can't open the file'");
		exit(0);
	}
	fseek(fp,00,SEEK_END);
	len=ftell(fp);
	rewind(fp);
	char str[99999],c;
	fread(str,sizeof(char),len,fp);
	int i, character=0,blank=0,chars=0,rows=0,word=0;
	for(i=0;(c=str[i])!='\0';i++)
	{
		if(c==' '){
			blank++;
			word=0;
		}else{
			if(word==0){
				word=1;
				 character++;
			}
		}
		if((c=str[i])=='\n'){
			rows++;
		}
	}
	chars=len-blank-rows*2;
	rows++;
	fclose(fp);
	if(strcmp(argv[1],"-c")==0)
		printf("Number of d is %d",chars);
	else if(strcmp(argv[1],"-w")==0)
		printf("Number of words is %d",character);
		else
			printf("Parameter is wrong!"); 
}

