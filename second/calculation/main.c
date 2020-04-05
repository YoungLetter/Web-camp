#include <stdio.h>
#include <string.h>
#include "calculation.h"
#include <stdlib.h>

void drawmap()
{
    printf(
		"\n\t|*****     功能键(输入#结束程序，回车键上传)      *****|\t\n"
		"\t|______________________________________________________|\t\n"
		"\t|     0      |     1       |      2      |      3      |\t\n"
		"\t|____________|_____________|_____________|_____________|\t\n"
		"\t|     4      |     5       |      6      |      7      |\t\n"
		"\t|____________|_____________|_____________|_____________|\t\n"
		"\t|     8      |     9       |     ()      |      #      |\t\n"
		"\t|____________|_____________|_____________|_____________|\t\n"
		"\t|     +      |     -       |      *      |      /      |\t\n"
		"\t|____________|_____________|_____________|_____________|\t\n\n"
	);
	printf("\t请输入你想进行的操作(形式不能为中文括号,负数记得加括号，正数不能加括号，以单个负数开头该负数就不用加括号：\n");
	printf("\t(分数小数算不得，限制为100个字符以内)\n");
}
//判断字符， 数字并进行存储转换;
int main()
{
    int flag = 0;
    while (!flag){
        drawmap();
        char c[10000];
        fflush(stdin);
        printf("\t\t");
        scanf("%[^\n]", c);
        fflush(stdin);
        if (strlen(c)>101){
            printf("\t\t字符数超过100\n");
            system("pause");
        }
        else {
            if (flag == 0){
                for (int i = 0; i < strlen(c); i++){        //用来判断是否有#
                    if (c[i] == '#'){
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 0){
                Stack *numstack = (Stack *)malloc(sizeof(Stack *));
                Stack *signstack = (Stack *)malloc(sizeof(Stack *));
                init(numstack);
                init(signstack);
                if (!result(c, strlen(c), numstack, signstack)){
                    printf("\t\t输入错误\n");
                    system("pause");
                }
                else {
                    printf("\t\t%s = %d\n", c,numstack ->elem[0]);
                    system("pause");
                }
                free(numstack);
                free(signstack);
            }
        }
        printf("\n\t");
        system("cls");
    }
    drawmap();
    if (flag == 1){
        printf("\t感谢您的使用\n");
    }
    printf("\t");
    system("pause");
    return 0;
}
