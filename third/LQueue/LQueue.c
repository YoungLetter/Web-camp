#include <stdlib.h>
#include <stdio.h>
#include "LQueue.h"

extern int space;   //连接两个.c文件中的space,链式队列

void InitLQueue(LQueue *Q)            //链式队列类似链表
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
        printf("申请内存失败\n");
    else {
        p ->next = NULL;    //记得p是Node大小
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
        printf("队列长度为零\n");
        return FALSE;
    }
    else {
        e = (void *)malloc(Q ->front ->size);
        e = Q ->front ->data;
        printf("\t该队头元素为\n\t\t\t\t");
        LPrint(e, Q ->front ->size);
        printf("\n");
        return TRUE;
    }
}

int LengthLQueue(LQueue *Q)
{
    if (Q ->length == 0)
        printf("队列长度为零\n");
    return (int)(Q ->length);
}
Status EnLQueue(LQueue *Q, void *data)
{
    Node *new = (Node *)malloc(sizeof(Node));//新建节点
    if (new == NULL){
        return FALSE;
    }
    else {
        new ->data = (void *)malloc(space);  //直接申请一个data大小的空间;
        new ->size = space;
        //printf("\t%d\t", *(int *)data);
        new ->data = data;    //赋值
        new ->next = NULL;
        //printf("\t%p\t", new ->data);//在这里这样没有错
        if (Q ->length == 0){ //空
            Q ->front = new;
            Q ->rear = new;
           // printf("第一次传来的地址%p\n", Q ->front ->data);
            //不能连续为相同的数据类型原因是都是相同的地址……
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
        Node *temp = Q ->front;//队头数据储存
        Q ->front = temp->next;//队头为下一位选手

        if (Q ->rear == temp)    //一种特殊情况如果只有一个元素，此时尾指针头指针指向空;
            Q -> rear = Q ->front;

        Q ->length--;
        free(temp ->data);
        free(temp);
        return TRUE;
    }
}

void ClearLQueue(LQueue *Q) //关于是否为空会在Main函数判断
{
    if (Q ->length == 0);
    else {
        Q ->rear = Q ->front; //让尾回归头，回到最初初始化的样子
        Q ->length = 0;        //长度回归;

        Node *p = Q ->front ->next;//暂存第二个结构;
        Q ->front ->next = NULL;    //指向清空;
        Node *temp = NULL;
        while (p){          //当刚开始第二个结构不为空
            temp = p ->next;//暂存p下一个结构
            free(p ->data);
            free(p);//把当前p free；
            p = temp;
        }           //清除了从第二个结构不为空开始到尾部的队列


        free(Q ->front ->data);//清空第一个的值只留下两个指针
        Q ->front ->data = NULL;
        printf("\t清空成功\n");
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
void LPrint(void *q, int size)//数据类型未知
{
    if (size == 1){
        printf("char: %c", *(char *)q);                   //char
    }
    else if (size == 2 || size == 4){
        printf("int: %d", *(int *)q);                   //short， int ，long；
    }
    else if (size == 8){                //单精度在计算时自动转换成双精度就不考虑单精度了
        printf("double: %f", *(double *)q);                 //double
    }
    else {
        printf("输出出错\n");
    }
}
