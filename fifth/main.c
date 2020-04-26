#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree/BinaryTree.h"

int initBT();
int flag = 0;
int main()
{
    int sign = 0;
    BiTree head;  //定义头
    int ret = initBT();
    while (ret != 8){
            switch (ret){
                case 0:                     //初始化
                    if (sign == 2)
                        printf("\t您已创建了，初始化会摧毁原来的树哦\n");
                    if (sign)               //如果不为空就先摧毁
                        DestroyBiTree(&head);
                    InitBiTree(&head);
                    printf("\t创建成功！\n");
                    printf("\t");
                    sign = 1;
                    system("pause");
                    break;
                case 1:             //前序
                    if (sign < 1){
                        printf("\t未初始化\n");
                    }
                    else if (sign < 2) {
                        printf("\t未创建\n");
                    }
                    else {
                        printf("\t先序遍历为:");
                        if (PreOrderTraverse(head, visit))
                            printf("\n");
                        else
                            printf("\t遍历失败\n");
                    }
                    printf("\t");
                    system("pause");
                    break;
                case 2:
                     if (!sign){
                        printf("\t未初始化\n");
                    }
                    else if (sign == 2) {
                        printf("\t已经创建了\n");
                    }
                    else {
                        printf("\t请按先序遍历的顺序依次输入二叉树,摁回车符结束一个数的输出,@字符相当于空结点\n\t");
                        if (CreateBiTree(&head)) {
                            printf("\t创造成功\n");
                            sign = 2;
                        }
                    }
                    printf("\t");
                    system("pause");
                    break;
                case 3:             //中序
                    if (sign < 1){
                        printf("\t未初始化\n");
                    }
                    else if (sign < 2) {
                        printf("\t未创建\n");
                    }
                    else {
                        printf("\t中序遍历为:");
                        if (InOrderTraverse(head, visit))
                            printf("\n");
                        else
                            printf("\t遍历失败\n");
                    }
                    printf("\t");
                    system("pause");
                    break;
                case 4:
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else {
                       if (DestroyBiTree(&head)) {
                            printf("\t摧毁成功\n");
                            sign = 0;
                       }
                       else
                            printf("\t摧毁失败\n");
                    }
                    printf("\t");
                    system("pause");
                    break;
                case 5:
                   if (sign < 1){
                        printf("\t未初始化\n");
                    }
                    else if (sign < 2) {
                        printf("\t未创建\n");
                    }
                    else {
                        printf("\t后序遍历为:");
                        if (PostOrderTraverse(head, visit))
                             printf("\n");
                        else
                            printf("\t遍历失败\n");
                    }
                    printf("\t");
                    system("pause");
                    break;
                case 6:
                    printf("\n\t请输入正确的前缀表达式（只允许0~9 和 +-*/）\n\t");
                    BiTree expression;
                    InitBiTree(&expression);
                    Create(&expression);
                    if (!judge())
                        printf("\t您的输入有误\n");
                    else {
                        int result = Calculate(expression);
                        if (flag == 1) {
                            printf("\t您的输入结果中出现除数为零的情况\n");
                            flag = 0;
                        }
                        else
                            printf("\t表达式的结果是%d\n", result);
                    }
                    setzero();
                    DestroyBiTree(&expression);
                    printf("\t");
                    system("pause");
                    break;
                case 7:
                    if (sign < 1){
                        printf("\t未初始化\n");
                    }
                    else if (sign < 2) {
                        printf("\t未创建\n");
                    }
                    else {
                        printf("\t层次遍历为:");
                        if (LevelOrderTraverse(head, visit))
                             printf("\n");
                        else
                            printf("\t遍历失败\n");
                    }
                    printf("\t");
                    system("pause");
                    break;
            }
            system("cls");
            ret = initBT();       //重新来过
    }
    printf("\t感谢您的使用\n\t");
    system("pause");
}

int initBT()
{
    	printf(
		"\n\t|****************     BinaryTree相关操作         ****************|\t\n"
		"\t|***   输入      功能                  输入    功能           ***|\t\n"
		"\t|***   0         初始化二叉树          1       先序遍历       ***|\t\n"
		"\t|***   2         输入字符              3       中序遍历       ***|\t\n"
		"\t|***   4         摧毁树                5       后序遍历       ***|\t\n"
		"\t|***   6         前缀计算器            7       层次遍历       ***|\t\n"
		"\t|***                     8  退 出 程 序                       ***|\t\n"
		"\t|________________________________________________________________|\t\n\n"
	);
	printf("\t请输入你想进行的操作（以第一个字符为准）：");
	char c;
	fflush(stdin);
	c = getchar();
	fflush(stdin);
	while (c>'8' || c<'0')//检测合法输入
	{
		printf("\t您的输入有误!请重新输入：\n\t\t\t\t");
		c = getchar();
		fflush(stdin);
	}
	return (c-'0');
}
