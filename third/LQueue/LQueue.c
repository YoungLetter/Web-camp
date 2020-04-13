#include <stdlib.h>
#include <stdio.h>
#include "LQueue.h"

extern int space;   //��������.c�ļ��е�space,��ʽ����

void InitLQueue(LQueue *Q)            //��ʽ������������
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
        printf("�����ڴ�ʧ��\n");
    else {
        p ->next = NULL;    //�ǵ�p��Node��С
        Q ->front = p;
        Q ->rear = p;
        Q ->length = 0;
    }
}

void DestoryLQueue(LQueue *Q)
{
    ClearLQueue(Q);
    free(Q ->front);
    Q ->front = NULL;
}

Status IsEmptyLQueue(const LQueue *Q)
{
    if (Q ->length == 0)
        return TRUE;
    else
        return FALSE;
}

Status GetHeadLQueue(LQueue *Q, void *e)
{
    if (Q ->length == 0){
        printf("���г���Ϊ��\n");
        return FALSE;
    }
    else {
        e = (void *)malloc(Q ->front ->size);
        e = Q ->front ->data;
        printf("\t�ö�ͷԪ��Ϊ\n\t\t\t\t");
        LPrint(e, Q ->front ->size);
        printf("\n");
        return TRUE;
    }
}

int LengthLQueue(LQueue *Q)
{
    if (Q ->length == 0)
        printf("���г���Ϊ��\n");
    return (int)(Q ->length);
}
Status EnLQueue(LQueue *Q, void *data)
{
    Node *new = (Node *)malloc(sizeof(Node));//�½��ڵ�
    if (new == NULL){
        return FALSE;
    }
    else {
        new ->data = (void *)malloc(space);  //ֱ������һ��data��С�Ŀռ�;
        new ->size = space;
        //printf("\t%d\t", *(int *)data);
        new ->data = data;    //��ֵ
        new ->next = NULL;
        //printf("\t%p\t", new ->data);//����������û�д�
        if (Q ->length == 0){ //��
            Q ->front = new;
            Q ->rear = new;
           // printf("��һ�δ����ĵ�ַ%p\n", Q ->front ->data);
            //��������Ϊ��ͬ����������ԭ���Ƕ�����ͬ�ĵ�ַ����
        }
        else {
            Q ->rear ->next = new;
            Q ->rear = new;
        }

        Q ->length++;
        return TRUE;
    }

}
Status DeLQueue(LQueue *Q)
{
    if (Q ->length == 0)
        return FALSE;
    else {
        Node *temp = Q ->front;//��ͷ���ݴ���
        Q ->front = temp->next;//��ͷΪ��һλѡ��

        if (Q ->rear == temp)    //һ������������ֻ��һ��Ԫ�أ���ʱβָ��ͷָ��ָ���;
            Q -> rear = Q ->front;

        Q ->length--;
        free(temp ->data);
        free(temp);
        return TRUE;
    }
}

void ClearLQueue(LQueue *Q) //�����Ƿ�Ϊ�ջ���Main�����ж�
{
    if (Q ->length == 0);
    else {
        Q ->rear = Q ->front; //��β�ع�ͷ���ص������ʼ��������
        Q ->length = 0;        //���Ȼع�;

        Node *p = Q ->front ->next;//�ݴ�ڶ����ṹ;
        Q ->front ->next = NULL;    //ָ�����;
        Node *temp = NULL;
        while (p){          //���տ�ʼ�ڶ����ṹ��Ϊ��
            temp = p ->next;//�ݴ�p��һ���ṹ
            free(p ->data);
            free(p);//�ѵ�ǰp free��
            p = temp;
        }           //����˴ӵڶ����ṹ��Ϊ�տ�ʼ��β���Ķ���


        free(Q ->front ->data);//��յ�һ����ֵֻ��������ָ��
        Q ->front ->data = NULL;
        printf("\t��ճɹ�\n");
    }
}

Status TraverseLQueue(const LQueue *Q)
{
    if (Q ->length == 0){
        return FALSE;
    }
    else {
        Node *temp = Q ->front;
        printf("\t");
        while (temp ->next){
            LPrint(temp ->data, temp ->size);
            printf("  -->  ");
            temp = temp ->next;
        }
        LPrint(temp ->data, temp ->size);
        printf("\n");
        return TRUE;
    }
}
void LPrint(void *q, int size)//��������δ֪
{
    if (size == 1){
        printf("char: %c", *(char *)q);                   //char
    }
    else if (size == 2 || size == 4){
        printf("int: %d", *(int *)q);                   //short�� int ��long��
    }
    else if (size == 8){                //�������ڼ���ʱ�Զ�ת����˫���ȾͲ����ǵ�������
        printf("double: %f", *(double *)q);                 //double
    }
    else {
        printf("�������\n");
    }
}
