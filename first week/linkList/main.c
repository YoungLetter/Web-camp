#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../head/linkedList.h"

int init();
int judgelength(LinkedList head, int length);//判断长度
void insert(LinkedList *head, int num);      //插入
void travel(LinkedList head);                //遍历
void out(LinkedList *head);                  //头出来
void destroy (LinkedList *head);             //摧毁

int main (int argc, char *argv[])
{
    int len, num;
    len = num = 0;
    int a = init();

    LinkedList head;  //头指针;
    head = NULL;

    while (a!=9){
        switch (a){

            case 0:             //初始化
                printf("\t请输入想要的链表长度：(长度小于10,第一位数字有效):\n\t\t\t\t");
                char c = getchar();
                fflush(stdin);
                if (c>'9' || c<='0')
                        printf("\t您的输入有误!\n");
                else {
                    destroy(&head);//把之前的链表摧毁;
                    head = NULL;   //让head重新指向空;
                    len = c - '0'; //记录长度;
                    printf("\t创建成功！\n");
                }
                printf("\t");
                system("pause");
                break;

            case 1:             //入队：插尾
                if (len == 0)
                    printf("\t链表不存在\n");
                else if (judgelength(head, len)){
                    printf("\t链表已满\n");
                }
                else {
                    printf("\t请输入入队的数字:（开头为数字默认正确）\n\t\t\t\t");
                    while (scanf("%d", &num) != 1){
                        fflush(stdin);
                        printf("\t输入错误，请重新输入:\n\t\t\t\t");
                    }
                    insert(&head, num);
                }
                printf("\t");
                system("pause");
                break;

            case 2:             //遍历输出
                if (len==0)
                    printf("\t链表不存在\n");
                else if (head==NULL){
                    printf("\t该链表为空\n");
                }
                else {
                    travel(head);
                }
                printf("\t");
                system("pause");
                break;

            case 3:             //出队：去头
                if (len==0)
                    printf("\t链表不存在\n");
                else if (head==NULL){
                    printf("\t该链表为空\n");
                }
                else
                    out(&head);
                printf("\t");
                system("pause");
                break;

            case 4:             //判断是否为空
                if (len==0){
                    printf("\t链表不存在\n");
                }
                else if (head==NULL){
                    printf("\t该链表为空\n");
                }
                else
                    printf("\t链表不为空\n");
                printf("\t");
                system("pause");
                break;

            case 5:             //反转链表
                if (len==0)
                    printf("\t链表不存在\n");
                else if (judgelength(head, len)){
                    printf("\t链表已满\n");
                }
                if (ReverseList(&head)){
                    printf("\t反转成功\n");
                    travel(head);
                }
                else
                    printf("\t反转失败\n");
                printf("\t");
                system("pause");
                break;

            case 6:             //判断是否满了
                if (len==0)
                    printf("\t链表不存在\n");
                else if (judgelength(head, len)){
                    printf("\t链表已满\n");
                }
                else if (judgelength(head, len==0)){
                    printf("\t链表未满\n");
                }
                printf("\t");
                system("pause");
                break;

            case 7:             //摧毁链表
                if (len==0)
                    printf("\t链表不存在\n");
                else if (head==NULL){
                    printf("\t该链表为空\n");
                }
                else {
                    destroy(&head);
                    len = 0;
                }
                printf("\t");
                system("pause");
                break;

            case 8:             //销毁数字
                if (len==0)
                    printf("\t链表不存在\n");
                else if (head==NULL){
                    printf("\t该链表为空\n");
                }
                else {
                        printf("\t请输入想要查找并销毁的数字：(开头为数字默认正确)\n");
                    while (scanf("%d", &num) != 1){
                        fflush(stdin);
                        printf("\t输入错误，请重新输入\n\t\t\t\t");
                    }
                    if (SearchList(head, num))
                        printf("找到并成功清除");
                    else
                        printf("没有找到该数字");
                }
                printf("\t");
                system("pause");
                break;

        }
        system("cls");
        a = init();//重新来过
    }
    printf("\n\t程序结束，感谢您的使用\n");
    printf("\t");
    free(head);
	system("pause");
    return 0;
}

int init()
{
    	printf(
		"\n\t|****************       链表相关操作         ****************|\t\n"
		"\t|***   输入      功能                  输入    功能       ***|\t\n"
		"\t|***   0         初始化队列            1       入队       ***|\t\n"
		"\t|***   2         遍历输出链表          3       出队       ***|\t\n"
		"\t|***   4         判断队列是否为空      5       反转链表   ***|\t\n"
		"\t|***   6         判断队列是否已满      7       销毁队列   ***|\t\n"
		"\t|***   8         是否有某个数并销毁    9       退出程序   ***|\t\n"
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

int judgelength(LinkedList head, int length)
{
    int num = 0;
    LinkedList p = head;
    if (head==NULL);
        else {
        while(head)
        {
            num++;
            head = head ->next;
        }
    }
    head = p;
    int ret;
    if (num < length){
        ret = 0;
    }
    else ret = 1;
    return ret;
}
void travel(LinkedList head)
{
    LinkedList p = head;
    while (head){
        printf("\t%d\t", head->data);
        head = head ->next;
    }
    head = p;
    printf("\n");
}
void out(LinkedList *head)
{
    LinkedList p = *head;
    (*head) = (*head) ->next;
    printf("\t数字 %d 已经出队\n", p->data);
    free(p);
}
void insert(LinkedList *head, int num)
{
    LNode *tail = (LNode *)malloc(sizeof(LNode));//构造结构;
    tail ->data = num;
    tail ->next = NULL;
    int sum = 0;
    LinkedList p = *head;           //保存head的地址;
    if (*head == NULL){
        *head = tail;
        p = *head;
    }
    else {
        while ((*head) ->next){
            sum++;
            *head = (*head)->next;
            if (sum == 2)
                printf("taco");
        }
        (*head) ->next = tail;
    }
    printf("\t%d插入成功\n", tail ->data);
    *head = p;
}
void destroy (LinkedList *head)
{
    LinkedList p = *head;
    while (p){
        (*head) = (*head)->next;
        free(p);
        p = *head;
    }
}
