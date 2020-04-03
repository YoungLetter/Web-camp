#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../head/linkedList.h"

int init();
int judgelength(LinkedList head, int length);//�жϳ���
void insert(LinkedList *head, int num);      //����
void travel(LinkedList head);                //����
void out(LinkedList *head);                  //ͷ����
void destroy (LinkedList *head);             //�ݻ�

int main (int argc, char *argv[])
{
    int len, num;
    len = num = 0;
    int a = init();

    LinkedList head;  //ͷָ��;
    head = NULL;

    while (a!=9){
        switch (a){

            case 0:             //��ʼ��
                printf("\t��������Ҫ�������ȣ�(����С��10,��һλ������Ч):\n\t\t\t\t");
                char c = getchar();
                fflush(stdin);
                if (c>'9' || c<='0')
                        printf("\t������������!\n");
                else {
                    destroy(&head);//��֮ǰ������ݻ�;
                    head = NULL;   //��head����ָ���;
                    len = c - '0'; //��¼����;
                    printf("\t�����ɹ���\n");
                }
                printf("\t");
                system("pause");
                break;

            case 1:             //��ӣ���β
                if (len == 0)
                    printf("\t��������\n");
                else if (judgelength(head, len)){
                    printf("\t��������\n");
                }
                else {
                    printf("\t��������ӵ�����:����ͷΪ����Ĭ����ȷ��\n\t\t\t\t");
                    while (scanf("%d", &num) != 1){
                        fflush(stdin);
                        printf("\t�����������������:\n\t\t\t\t");
                    }
                    insert(&head, num);
                }
                printf("\t");
                system("pause");
                break;

            case 2:             //�������
                if (len==0)
                    printf("\t��������\n");
                else if (head==NULL){
                    printf("\t������Ϊ��\n");
                }
                else {
                    travel(head);
                }
                printf("\t");
                system("pause");
                break;

            case 3:             //���ӣ�ȥͷ
                if (len==0)
                    printf("\t��������\n");
                else if (head==NULL){
                    printf("\t������Ϊ��\n");
                }
                else
                    out(&head);
                printf("\t");
                system("pause");
                break;

            case 4:             //�ж��Ƿ�Ϊ��
                if (len==0){
                    printf("\t��������\n");
                }
                else if (head==NULL){
                    printf("\t������Ϊ��\n");
                }
                else
                    printf("\t����Ϊ��\n");
                printf("\t");
                system("pause");
                break;

            case 5:             //��ת����
                if (len==0)
                    printf("\t��������\n");
                else if (judgelength(head, len)){
                    printf("\t��������\n");
                }
                if (ReverseList(&head)){
                    printf("\t��ת�ɹ�\n");
                    travel(head);
                }
                else
                    printf("\t��תʧ��\n");
                printf("\t");
                system("pause");
                break;

            case 6:             //�ж��Ƿ�����
                if (len==0)
                    printf("\t��������\n");
                else if (judgelength(head, len)){
                    printf("\t��������\n");
                }
                else if (judgelength(head, len==0)){
                    printf("\t����δ��\n");
                }
                printf("\t");
                system("pause");
                break;

            case 7:             //�ݻ�����
                if (len==0)
                    printf("\t��������\n");
                else if (head==NULL){
                    printf("\t������Ϊ��\n");
                }
                else {
                    destroy(&head);
                    len = 0;
                }
                printf("\t");
                system("pause");
                break;

            case 8:             //��������
                if (len==0)
                    printf("\t��������\n");
                else if (head==NULL){
                    printf("\t������Ϊ��\n");
                }
                else {
                        printf("\t��������Ҫ���Ҳ����ٵ����֣�(��ͷΪ����Ĭ����ȷ)\n");
                    while (scanf("%d", &num) != 1){
                        fflush(stdin);
                        printf("\t�����������������\n\t\t\t\t");
                    }
                    if (SearchList(head, num))
                        printf("�ҵ����ɹ����");
                    else
                        printf("û���ҵ�������");
                }
                printf("\t");
                system("pause");
                break;

        }
        system("cls");
        a = init();//��������
    }
    printf("\n\t�����������л����ʹ��\n");
    printf("\t");
    free(head);
	system("pause");
    return 0;
}

int init()
{
    	printf(
		"\n\t|****************       ������ز���         ****************|\t\n"
		"\t|***   ����      ����                  ����    ����       ***|\t\n"
		"\t|***   0         ��ʼ������            1       ���       ***|\t\n"
		"\t|***   2         �����������          3       ����       ***|\t\n"
		"\t|***   4         �ж϶����Ƿ�Ϊ��      5       ��ת����   ***|\t\n"
		"\t|***   6         �ж϶����Ƿ�����      7       ���ٶ���   ***|\t\n"
		"\t|***   8         �Ƿ���ĳ����������    9       �˳�����   ***|\t\n"
		"\t|____________________________________________________________|\t\n\n"
	);
	printf("\t������������еĲ������Ե�һ���ַ�Ϊ׼����");
	char c;
	fflush(stdin);
	c = getchar();
	fflush(stdin);
	while (c>'9' || c<'0')//���Ϸ�����
	{
		printf("\t������������!���������룺\n\t\t\t\t");
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
    printf("\t���� %d �Ѿ�����\n", p->data);
    free(p);
}
void insert(LinkedList *head, int num)
{
    LNode *tail = (LNode *)malloc(sizeof(LNode));//����ṹ;
    tail ->data = num;
    tail ->next = NULL;
    int sum = 0;
    LinkedList p = *head;           //����head�ĵ�ַ;
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
    printf("\t%d����ɹ�\n", tail ->data);
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
