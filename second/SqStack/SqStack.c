#include "SqStack.h"
#include <stdlib.h>

Status initStack(SqStack *s,int sizes)                  //��ʼ��ջ
{
    s ->elem = (ElemType *)malloc(sizes * sizeof(ElemType));    //ȷ����С������;
    if (!(s ->elem))
        return ERROR;
    s ->top = -1;
    s ->size = sizes;
    return SUCCESS;
}
Status isEmptyStack(SqStack *s)                         //�ж�ջ�Ƿ�Ϊ��
{
    if (s ->top == -1){
        return ERROR;
    }
    return SUCCESS;
}
Status getTopStack(SqStack *s,ElemType *e)               //�õ�ջ��Ԫ��
{
    if (s ->top == -1 || s ->elem == NULL){
        return ERROR;
    }
    *e = s ->elem[s ->top];
    return SUCCESS;
}
Status clearStack(SqStack *s)                            //���ջ
{
    if (!s){
        return ERROR;
    }
    s ->top = -1;
    return SUCCESS;
}
Status destroyStack(SqStack *s)                         //����ջ
{
    if (!s)
        return ERROR;
    s ->size = 0;
    free(s ->elem);
    s ->top = -1;
    return SUCCESS;
}
Status stackLength(SqStack *s,int *length)              //���ջ����
{
    if (!s)
        return ERROR;
    *length = (s ->top)+1;
    return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)              //��ջ
{
    if (!s || (s->top) >= s ->size-1){
            return ERROR;
    }
    s ->top++;
    s ->elem[s ->top] = data;
    return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)              //��ջ
{
    if (!s || (s ->top)<0)
        return ERROR;
    *data = s ->elem[s ->top];
    s ->top--;
    return SUCCESS;
}
