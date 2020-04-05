#include <stdio.h>
#include <string.h>
#include "calculation.h"
#include <stdlib.h>

void drawmap()
{
    printf(
		"\n\t|*****     ���ܼ�(����#�������򣬻س����ϴ�)      *****|\t\n"
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
	printf("\t������������еĲ���(��ʽ����Ϊ��������,�����ǵü����ţ��������ܼ����ţ��Ե���������ͷ�ø����Ͳ��ü����ţ�\n");
	printf("\t(����С���㲻�ã�����Ϊ100���ַ�����)\n");
}
//�ж��ַ��� ���ֲ����д洢ת��;
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
            printf("\t\t�ַ�������100\n");
            system("pause");
        }
        else {
            if (flag == 0){
                for (int i = 0; i < strlen(c); i++){        //�����ж��Ƿ���#
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
                    printf("\t\t�������\n");
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
        printf("\t��л����ʹ��\n");
    }
    printf("\t");
    system("pause");
    return 0;
}
