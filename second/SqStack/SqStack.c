#include "SqStack.h"
#include <stdlib.h>

Status initStack(SqStack *s,int sizes)                  //初始化栈
{
    s ->elem = (ElemType *)malloc(sizes * sizeof(ElemType));    //确定大小的数组;
    if (!(s ->elem))
        return ERROR;
    s ->top = -1;
    s ->size = sizes;
    return SUCCESS;
}
Status isEmptyStack(SqStack *s)                         //判断栈是否为空
{
    if (s ->top == -1){
        return ERROR;
    }
    return SUCCESS;
}
Status getTopStack(SqStack *s,ElemType *e)               //得到栈顶元素
{
    if (s ->top == -1 || s ->elem == NULL){
        return ERROR;
    }
    *e = s ->elem[s ->top];
    return SUCCESS;
}
Status clearStack(SqStack *s)                            //清空栈
{
    if (!s){
        return ERROR;
    }
    s ->top = -1;
    return SUCCESS;
}
Status destroyStack(SqStack *s)                         //销毁栈
{
    if (!s)
        return ERROR;
    s ->size = 0;
    free(s ->elem);
    s ->top = -1;
    return SUCCESS;
}
Status stackLength(SqStack *s,int *length)              //检测栈长度
{
    if (!s)
        return ERROR;
    *length = (s ->top)+1;
    return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)              //入栈
{
    if (!s || (s->top) >= s ->size-1){
            return ERROR;
    }
    s ->top++;
    s ->elem[s ->top] = data;
    return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)              //出栈
{
    if (!s || (s ->top)<0)
        return ERROR;
    *data = s ->elem[s ->top];
    s ->top--;
    return SUCCESS;
}
