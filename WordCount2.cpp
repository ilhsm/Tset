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
		printf("���ļ�ʧ��\n");
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
		printf("�ַ�����%d\n", cn-1);//��ȥEOF��ռ���ַ�
	else if (!strcmp(argv[1], "-w"))
		printf("��������%d\n", wn+1);
	else
		printf("������-c��-w\n");
	return 0;
}

