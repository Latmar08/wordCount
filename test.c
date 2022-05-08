#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char ch, count = 1;
	FILE* p;  //�ļ�ָ��
	errno_t err;

	//�ж��Ƿ������ļ�
	if (argc != 3) {
		printf("��ʹ�ø�ʽ��%s �ļ���", argv[0]);
		exit(1);        //���������˳�
	}

	//�ж��Ƿ��������ļ�
	if ((err = fopen_s(&p,argv[2],"r"))) {
		printf("���ļ� %s ʧ��", argv[2]);
		exit(1);      //���ļ�ʧ�ܣ��������˳�
	}

	if (strcmp(argv[1], "-c") == 0) {
		count = 0;
		while ((ch = getc(p)) != EOF) {  //EOF��ʾ�ļ�����
			count++;
		}
		printf("\n�ַ���Ϊ %d ��\n", count);
	}else if (strcmp(argv[1], "-w") == 0) {
		count = 0;
		while ((ch = getc(p)) != EOF) {  //EOF��ʾ�ļ�����
			if ((ch == ' ') || (ch == ',')) 
				count++;
		}
		printf("\n������Ϊ %d ��\n", count+1);
	}
	printf("*******");
	fclose(p);
	return 0;

}