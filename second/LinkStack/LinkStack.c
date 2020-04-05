#include "LinkStack.h"
#include <stdlib.h>

Status initLStack(LinkStack *s)//初始化栈顶指针,类似二级指针？但在这里就是一级指针;
{
    s ->top = (LinkStackPtr)malloc(sizeof(StackNode));  //让指针带着结构，相当于头结点;
    if (!(s ->top)){   //创建是否成功;
        return ERROR;
    }
    s ->top ->next = NULL;
    s ->count = 0;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)  //判断栈是否为空
{
    if (s ->count == 0 || !s)
        return ERROR;
    else
        return SUCCESS;
}


Status getTopLStack(LinkStack *s,ElemType *e)      //得到栈顶元素
{
    if (s ->count == 0 || s ->top == NULL || !s)    //判断是否为空
        return ERROR;
    *e = s ->top ->next ->data;
    return SUCCESS;
}
Status clearLStack(LinkStack *s)//清空栈
{
    if (s ->top == NULL || s == NULL || !s) //本身自己不能为空, 这里元素个数可以等于零，相当于已经清空，成功情况;
        return ERROR;

    s ->count = 0;      //元素个数零
    LinkStackPtr temp = s ->top ->next;
    while (temp){
        LinkStackPtr p = temp;
        temp = temp ->next;
        free(p);
    }
    return SUCCESS;
}
Status destroyLStack(LinkStack *s)//销毁栈
{
    if (s == NULL) //要把连top指针都干掉,如果它本身为空相当于已经被成功干掉
        return ERROR;

    s ->count = 0;      //元素个数零
    LinkStackPtr temp = s ->top ->next;     //清空栈
    while (temp){
        LinkStackPtr p = temp;
        temp = temp ->next;
        free(p);
    }
    free(s ->top);
    return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length)//检测栈长度
{
    if (!s || !(s ->top))
        return ERROR;
    *length = s ->count;
    return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data)//入栈
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
Status popLStack(LinkStack *s,ElemType *data)//出栈
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
