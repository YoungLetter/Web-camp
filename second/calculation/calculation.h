#ifndef CALCULATION_H_INCLUDED
#define CALCULATION_H_INCLUDED
/*
符号栈，数字栈，数字符号栈，入栈出栈输出判断。到第一百个如果不是\0，就判断error,
遍历有非法符号就error,第一次遇到左括号左括号最高，进去之后就最低了
小数，分数不要，分数就是不能整除的数，在出栈计算时如果有➗，而且不能整除，就error；
如果先输入符号就error，以符号结尾也error,变成后缀表达式以后，碰到符号就取两个数字；
加减乘除符号比数字数量少一，用这个来确定是否正确输入,这也意味着负数不能计算
数字的读取当读到数字时候开始计数，当读到\n, ,符号结束读取;
用ASCII码，标识，单有数字可以，单有符号，空格不行，设置一个flag,如果有这个，flag==1;
如果两个符号连续，error；如果除号后面第一个数字是零，error
if 101不为\0，error；
ascii 0 9-10 40-43 45 47-57
sign num;
2n-1
数字之间只有空格没有符号，符号之间没有数字error，有有右括号，一定先判断有没有左括号；
*/

#define max_size 100


typedef enum Status{
    ERROR = 0,
    SUCCESS = !ERROR
}Status;

typedef int ElemType;

typedef struct Stack            //数组栈
{
	ElemType *elem;
	int top;
}Stack;

//关于栈
Status init(Stack *s);                 //初始化栈

Status pop(Stack *s,ElemType *data);             //出栈
Status push(Stack *s,ElemType data);             //入栈
Status clear(Stack *s);                            //清空栈


//关于计算
Status result(char c[], int length, Stack *numstack, Stack *signstack);//数据遍历，用strlen知道长度然后遍历入栈
Status calculate(Stack *numstack, Stack *signstack);    //计算
int priority (int sign);                     //设置运算符的优先级
void right(Stack *numstack, Stack *signstack);
#endif // CALCULATION_H_INCLUDED
