#include <stdio.h>
#include <stdlib.h>
#include "LQueue/LQueue.h"
#include <string.h>
#include "AQueue/AQueue.h"

int space = 0;  //通过它在两个.c函数间传输输入数据类型大小
int initLQ();     //初始化图

char type = 0;
int initAQ();
int main()
{
    char choice;
    printf("请输入您的选择:(第一个数字为准)\n");
    printf("\t【1】 顺序队列   【2】 循环队列 \n");
    fflush(stdin);
    choice = getchar();
    fflush(stdin);
    while (choice < '1' || choice >'2'){
        printf("\t输入错误，请重新输入:\n\t\t\t\t");
        choice = getchar();
		fflush(stdin);
    }
    system("cls");
    if (choice == '1'){
        int sign = 0;
        LQueue head ;  //定义头
        head.length = 0;    //初始化头部
        int a = initLQ(); //获取要进行什么操作
        void *data;     //把想要输入的数据用memcpy给它再通过他传到函数
        while (a!=9){
            switch (a){

                case 0:             //初始化
                    if (sign)    //如果不为空就先摧毁
                        DestoryLQueue(&head);
                    InitLQueue(&head);
                    printf("\t创建成功！\n");
                    printf("\t");
                    sign = 1;
                    system("pause");
                    break;

                case 1:                     //入队
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else {
                        printf("\t请选择入队的数据类型：\n\t");
                        printf("\t1 char    2  int   3  double\n\t\t\t\t");
                        fflush(stdin);
                        char c = getchar();
                        fflush(stdin);
                        while (c < '1' || c > '3'){     //确定正确的输入
                            printf("\t您的输入有误!请重新输入：\n\t\t\t\t");
                            c = getchar();
                            fflush(stdin);
                        }
                        fflush(stdin);

                        printf("\t请输入数字或字符\n\t\t\t\t");
                        if (c == '1'){
                            char num;
                            while (scanf("%c", &num) != 1){
                                fflush(stdin);
                                printf("\t输入错误，请重新输入:\n\t\t\t\t");
                            }
                            data = (void *)malloc(sizeof(char));
                            memcpy(data, &num, sizeof(char));
                            space = sizeof(char);
                            if (EnLQueue(&head, data))
                                printf("\t【%c】入队成功\n", num);
                            else
                                printf("\t入队失败\n");
                            data = NULL;
                            free(data);
                        }
                        else if (c == '2'){
                            int num;//00720D38
                            while (scanf("%d", &num) != 1){
                                fflush(stdin);
                                printf("\t输入错误，请重新输入:\n\t\t\t\t");
                            }
                            data = (void *)malloc(sizeof(int));
                            memcpy(data, &num, sizeof(int));
                            space = sizeof(int);
                            //printf("地址为%p\n", data);
                            if (EnLQueue(&head, data))
                                printf("\t【%d】入队成功\n", num);
                            else
                                printf("\t入队失败\n");
                            data = NULL;
                            free(data);
                        }
                        else if (c == '3'){
                            double num;
                            while (scanf("%lf", &num) != 1){
                                fflush(stdin);
                                printf("\t输入错误，请重新输入:\n\t\t\t\t");
                            }
                            data = (void *)malloc(sizeof(double));
                            memcpy(data, &num, sizeof(double));
                            space = sizeof(double);
                            if (EnLQueue(&head, data))
                                printf("\t【%f】入队成功\n", num);
                            else
                                printf("\t入队失败\n");
                            data = NULL;
                            free(data);
                        }
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 2:             //遍历输出
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else if (IsEmptyLQueue(&head)){
                        printf("\t队列为空\n");
                    }
                    else {
                        TraverseLQueue(&head);
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 3:             //出队
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else if (IsEmptyLQueue(&head)){
                        printf("\t队列为空\n");
                    }
                    else {
                        if(DeLQueue(&head))
                            printf("\t出队完成\n");
                        else
                            printf("\t出队失败\n");
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 4:             //判断是否为空
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else {
                        if (IsEmptyLQueue(&head))
                            printf("\t队列为空\n");
                        else {
                            printf("\t队列不为空\n");
                        }
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 5:             //清空
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else if (IsEmptyLQueue(&head)){
                        printf("\t队列为空\n");
                    }
                    else {
                        ClearLQueue(&head);
                        printf("\t清空成功\n");
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 6:             //检查队头
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else if (IsEmptyLQueue(&head)){
                        printf("\t队列为空\n");
                    }
                    else {
                        void *get;
                        GetHeadLQueue(&head, get);
                        free(get);
                        get = NULL;
                    }

                    printf("\t");
                    system("pause");
                    break;

                case 7:             //摧毁
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else {
                        DestoryLQueue(&head);
                        printf("\t摧毁成功\n"); //problem
                        sign = 0;
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 8:                     //确定长度
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else if (IsEmptyLQueue(&head)){
                        printf("\t队列为空\n");
                    }
                    else {
                        printf("\t队列长度为%d\n", LengthLQueue(&head));
                    }
                    printf("\t");
                    system("pause");
                    break;

            }
            system("cls");
            a = initLQ();//重新来过
        }
    }
    else if (choice == '2'){
        int sign = 0;
        int flag = 0; //用来确定是否已经确定入队类型
        AQueue head ;  //定义头
        int a = initAQ(); //获取要进行什么操作
        void *data = NULL;     //把想要输入的数据用memcpy给它再通过他传到函数
        while (a!=9){
            switch (a){

                case 0:             //初始化
                    if (sign)    //如果不为空就先摧毁
                        DestoryAQueue(&head);
                    InitAQueue(&head);
                    printf("\t创建成功！\n");
                    printf("\t");
                    sign = 1;
                    system("pause");
                    break;

                case 1:                     //入队
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else {
                        if (!flag){
                            flag = 1;
                            printf("\t请选择数据类型：\n\t");
                            printf("\t1 char    2  int   3  double\n\t\t\t\t");
                            fflush(stdin);
                            char c = getchar();
                            fflush(stdin);
                            while (c < '1' || c > '3'){     //确定正确的输入
                                printf("\t您的输入有误!请重新输入：\n\t\t\t\t");
                                c = getchar();
                                fflush(stdin);
                            }
                            fflush(stdin);
                            if (c == '1')
                                type = sizeof(char);
                            else if (c == '2')
                                type = sizeof(int);
                            else if (c == '3')
                                type = sizeof(double);
                        }

                        printf("\t请输入数字或字符\n\t\t\t\t");
                        if (type == sizeof(char)){
                            char num;
                            while (scanf("%c", &num) != 1){
                                fflush(stdin);
                                printf("\t输入错误，请重新输入:\n\t\t\t\t");
                            }
                            data = (void *)malloc(sizeof(char));
                            memcpy(data, &num, sizeof(char));
                            if (EnAQueue(&head, data))
                                printf("\t【%c】入队成功\n", num);
                            else
                                printf("\t入队失败\n");
                            data = NULL;
                            free(data);
                        }
                        else if (type== sizeof(int)){
                            int num;
                            while (scanf("%d", &num) != 1){
                                fflush(stdin);
                                printf("\t输入错误，请重新输入:\n\t\t\t\t");
                            }
                            data = (void *)malloc(sizeof(int));
                            memcpy(data, &num, sizeof(int));
                            if (EnAQueue(&head, data))
                                printf("\t【%d】入队成功\n", num);
                            else
                                printf("\t入队失败\n");
                            data = NULL;
                            free(data);
                        }
                        else if (type == sizeof(double)){
                            double num;
                            while (scanf("%lf", &num) != 1){
                                fflush(stdin);
                                printf("\t输入错误，请重新输入:\n\t\t\t\t");
                            }
                            data = (void *)malloc(sizeof(double));
                            memcpy(data, &num, sizeof(double));
                            if (EnAQueue(&head, data))
                                printf("\t【%f】入队成功\n", num);
                            else
                                printf("\t入队失败\n");
                            data = NULL;
                            free(data);
                        }
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 2:             //遍历输出
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else if (IsEmptyAQueue(&head)){
                        printf("\t队列为空\n");
                    }
                    else {
                        TraverseAQueue(&head, data);
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 3:             //出队
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else if (IsEmptyAQueue(&head)){
                        printf("\t队列为空\n");
                    }
                    else {
                        if(DeAQueue(&head))
                            printf("\t出队完成\n");
                        else
                            printf("\t出队失败\n");
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 4:             //判断是否为空
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else {
                        if (IsEmptyAQueue(&head))
                            printf("\t队列为空\n");
                        else {
                            if (IsFullAQueue(&head))
                                printf("\t队列为满\n");
                            else {
                                printf("\t队列不为空\n");
                            }
                        }
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 5:             //清空
                   if (!sign){
                        printf("\t未初始化\n");
                    }
                    else if (IsEmptyAQueue(&head)){
                        printf("\t队列为空\n");
                    }
                    else {
                        ClearAQueue(&head);
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 6:             //检查队头
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else if (IsEmptyAQueue(&head)){
                        printf("\t队列为空\n");
                    }
                    else {
                        void *get = NULL;
                        GetHeadAQueue(&head, get);
                        free(get);
                        get = NULL;
                    }

                    printf("\t");
                    system("pause");
                    break;

                case 7:             //摧毁
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else {
                        DestoryAQueue(&head);
                        printf("\t摧毁成功\n"); //problem
                        sign = 0;
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 8:                     //确定长度
                    if (!sign){
                        printf("\t未初始化\n");
                    }
                    else if (IsEmptyAQueue(&head)){
                        printf("\t队列为空\n");
                    }
                    else {
                        printf("\t队列长度为%d\n", LengthAQueue(&head));
                    }
                    printf("\t");
                    system("pause");
                    break;

            }
            system("cls");
            a = initAQ();//重新来过
        }
    }
    printf("\n\t程序结束，感谢您的使用\n");
    printf("\t");
   // free(head);
	system("pause");
    return 0;
}


int initLQ()
{
    	printf(
		"\n\t|****************     LQueue相关操作         ****************|\t\n"
		"\t|***   输入      功能                  输入    功能       ***|\t\n"
		"\t|***   0         初始化队列            1       入队       ***|\t\n"
		"\t|***   2         遍历输出              3       出队       ***|\t\n"
		"\t|***   4         判断队列是否为空      5       清空       ***|\t\n"
		"\t|***   6         检查队头元素          7       销毁       ***|\t\n"
		"\t|***   8         确定队列长度          9       退出程序   ***|\t\n"
		"\t|____________________________________________________________|\t\n\n"
	);
	printf("\t请输入你想进行的操作（以第一个字符为准）：");
	char c;
	fflush(stdin);
	c = getchar();
	fflush(stdin);
	while (c>'9' || c<'0')//检测合法输入
	{
		printf("\t您的输入有误!请重新输入：\n\t\t\t\t");
		c = getchar();
		fflush(stdin);
	}
	return (c-'0');
}

int initAQ()
{
    	printf(
		"\n\t|****************     AQueue相关操作         ****************|\t\n"
		"\t|***   输入      功能                  输入    功能       ***|\t\n"
		"\t|***   0         初始化队列            1       入队       ***|\t\n"
		"\t|***   2         遍历输出              3       出队       ***|\t\n"
		"\t|***   4         判断队列是否满或空    5       清空       ***|\t\n"
		"\t|***   6         检查队头元素          7       销毁       ***|\t\n"
		"\t|***   8         确定队列长度          9       退出程序   ***|\t\n"
		"\t|____________________________________________________________|\t\n\n"
	);
	printf("\t请输入你想进行的操作（以第一个字符为准）：");
	char c;
	fflush(stdin);
	c = getchar();
	fflush(stdin);
	while (c>'9' || c<'0')//检测合法输入
	{
		printf("\t您的输入有误!请重新输入：\n\t\t\t\t");
		c = getchar();
		fflush(stdin);
	}
	return (c-'0');
}
