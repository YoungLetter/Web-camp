#include "LinkStack.h"
#include <stdlib.h>

Status initLStack(LinkStack *s)//��ʼ��ջ��ָ��,���ƶ���ָ�룿�����������һ��ָ��;
{
    s ->top = (LinkStackPtr)malloc(sizeof(StackNode));  //��ָ����Žṹ���൱��ͷ���;
    if (!(s ->top)){   //�����Ƿ�ɹ�;
        return ERROR;
    }
    s ->top ->next = NULL;
    s ->count = 0;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)  //�ж�ջ�Ƿ�Ϊ��
{
    if (s ->count == 0 || !s)
        return ERROR;
    else
        return SUCCESS;
}


Status getTopLStack(LinkStack *s,ElemType *e)      //�õ�ջ��Ԫ��
{
    if (s ->count == 0 || s ->top == NULL || !s)    //�ж��Ƿ�Ϊ��
        return ERROR;
    *e = s ->top ->next ->data;
    return SUCCESS;
}
Status clearLStack(LinkStack *s)//���ջ
{
    if (s ->top == NULL || s == NULL || !s) //�����Լ�����Ϊ��, ����Ԫ�ظ������Ե����㣬�൱���Ѿ���գ��ɹ����;
        return ERROR;

    s ->count = 0;      //Ԫ�ظ�����
    LinkStackPtr temp = s ->top ->next;
    while (temp){
        LinkStackPtr p = temp;
        temp = temp ->next;
        free(p);
    }
    return SUCCESS;
}
Status destroyLStack(LinkStack *s)//����ջ
{
    if (s == NULL) //Ҫ����topָ�붼�ɵ�,���������Ϊ���൱���Ѿ����ɹ��ɵ�
        return ERROR;

    s ->count = 0;      //Ԫ�ظ�����
    LinkStackPtr temp = s ->top ->next;     //���ջ
    while (temp){
        LinkStackPtr p = temp;
        temp = temp ->next;
        free(p);
    }
    free(s ->top);
    return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length)//���ջ����
{
    if (!s || !(s ->top))
        return ERROR;
    *length = s ->count;
    return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data)//��ջ
{
    if (!s || !(s ->top))
        return ERROR;

    StackNode *fresh = (StackNode *)malloc(sizeof(StackNode));
    fresh ->data = data;
    fresh ->next = s ->top ->next;
    s ->top ->next = fresh;
    s ->count++;
    return SUCCESS;
}
Status popLStack(LinkStack *s,ElemType *data)//��ջ
{
    if (!s || !(s ->top))
        return ERROR;

    LinkStackPtr temp = s ->top ->next;
    s -> top ->next = temp ->next;
    *data = temp ->data;
    free(temp);
    s ->count--;
    return SUCCESS;
}
