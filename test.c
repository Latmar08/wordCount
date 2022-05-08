#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char ch, count = 1;
	FILE* p;  //文件指针
	errno_t err;

	//判断是否输入文件
	if (argc != 3) {
		printf("请使用格式：%s 文件名", argv[0]);
		exit(1);        //不是正常退出
	}

	//判断是否正常打开文件
	if ((err = fopen_s(&p,argv[2],"r"))) {
		printf("打开文件 %s 失败", argv[2]);
		exit(1);      //打卡文件失败，非正常退出
	}

	if (strcmp(argv[1], "-c") == 0) {
		count = 0;
		while ((ch = getc(p)) != EOF) {  //EOF表示文件结束
			count++;
		}
		printf("\n字符数为 %d 个\n", count);
	}else if (strcmp(argv[1], "-w") == 0) {
		count = 0;
		while ((ch = getc(p)) != EOF) {  //EOF表示文件结束
			if ((ch == ' ') || (ch == ',')) 
				count++;
		}
		printf("\n单词数为 %d 个\n", count+1);
	}
	
	fclose(p);
	return 0;

}
