#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	char Content[100];
	FILE* fp;
	int cn = 0, wn = 0;
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		printf("打开文件失败\n");
		exit(EXIT_FAILURE);
	}
	while (!feof(fp))
	{
		fscanf(fp, "%c", &Content[cn]);
		if (Content[cn] == ' ' || Content[cn] == ',')
			wn++;
		cn++;
	}
	fclose(fp);
	if (!strcmp(argv[1],"-c"))
		printf("字符数：%d\n", cn-1);//减去EOF所占的字符
	else if (!strcmp(argv[1], "-w"))
		printf("单词数：%d\n", wn+1);
	else
		printf("请输入-c或-w\n");
	return 0;
}

