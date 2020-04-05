#include <stdlib.h>
#include "calculation.h"

Status init(Stack *s)                  //初始化栈
{
    s ->elem = (ElemType *)malloc(max_size * sizeof(ElemType));    //确定大小的数组,int可以装字符，浪费罢了;
    if (!(s ->elem))
        return ERROR;
    s ->top = -1;
    return SUCCESS;
}

Status clear(Stack *s)                            //清空栈
{
    if (!s){
        return ERROR;
    }
    s ->top = -1;
    return SUCCESS;
}

Status push(Stack *s,ElemType data)              //入栈
{
    if (!s || (s->top) >= max_size-1){
            return ERROR;
    }
    s ->top++;
    s ->elem[s ->top] = data;
    return SUCCESS;
}

Status pop(Stack *s,ElemType *data)              //出栈
{
    if (!s || (s ->top)<0)
        return ERROR;
    *data = s ->elem[s ->top];
    s ->top--;
    return SUCCESS;
}

int priority (int sign)                     //算出运算符的优先级
{
    int ret;
    switch (sign){
        case '(':
            ret = 0;
            break;              //如果遇到左括号直接入栈，但在栈中它最小；

        case '+':
        case '-':
            ret = 1;
            break;

        case '*':
        case '/':
            ret = 2;
            break;
    }
    return ret;
}

void right(Stack *numstack, Stack *signstack)//单独处理右括号，因为它要找到左括号
{
    int sign; //临时储存运算符包括括号
    sign = signstack ->elem[signstack ->top];
    while (sign != '('){
        calculate(numstack, signstack);
        pop(signstack, &sign);  //符号出栈;
    }
}
Status result(char c[], int length, Stack *numstack, Stack *signstack)                          //数字入栈没要求，符号入栈得比较还有如果为空直接驴;
{
    int i = 0;
    int j = 0;
    int foundnum, foundsign;    //found检查是否连续符号或者数字，如 -- ++这种不符合逻辑
    foundnum = foundsign = 0;
    int value = 0; //把字符类型的数字转化为int类型储存起来;
    int check = 0; //check用来检查括号的完整性;
    for (; i<length; i++){
        if (c[i] == ' ' || c[i] == '\t');
        else if (c[i] >= 48 && c[i] <= 57){
            for (j = i; j<length; j++){
                    if (c[j] < 48 || c[j] > 57){
                        break;
                    }
                    else {
                        value *= 10;
                        value += c[j] - '0';
                        i = j;
                    }
            }
            foundnum++;
            if (foundnum==2)
                return ERROR;
            foundsign = 0;
            push(numstack, value);
            value = 0;
        }
        else if ( (c[i]>=40 && c[i]<=43) || c[i] == 45 || c[i] == 47){

                if (c[i] == '(' ){    //如果是左括号   有中文括号和英文括号ASCII的不同，加减乘除一样；
                    push(signstack,c[i]);
                    check++;      //check检查括号;但是多重括号就凉了
                    foundsign = 0;  //因为是左括号,所以允许出现 "+(-"这种连续运算符的出现：
                }

                else if (c[i] == ')'){
                    if (signstack ->top == -1 || check<1){
                        return ERROR;
                    }
                    else {
                        check--;    //有可能是多重括号;
                        right(numstack, signstack);
                    }

                }
                else {
                    if (i == 0){   //开头为负数的话
                        if (c[0] == '-'){
                            push(numstack, 0);
                            push(signstack, c[0]);
                            foundsign++;
                            foundnum = 0;
                            if (foundsign==2)
                                return ERROR;
                        }
                    }
                    else if (signstack ->top == -1){    //还没有符号存入情况
                        push(signstack,c[i]);
                        foundsign++;
                        foundnum = 0;
                        if (foundsign==2)
                            return ERROR;
                    }
                    else {                              //栈里有符号存入的情况
                        if (priority(c[i]) > priority(signstack ->elem[signstack ->top])){  //新的优先级大的情况
                            if (signstack ->elem[signstack ->top] == '(' && c[i] == '-' && foundnum == 0)    //有括号后面出现负号
                                push(numstack, 0);      //变成 0-；
                            push(signstack,c[i]);
                            foundsign++;
                            foundnum = 0;
                            if (foundsign==2)
                                return ERROR;
                        }
                        else {
                            while ((priority(c[i]) <= priority(signstack ->elem[signstack ->top]))&& (signstack ->top >= 0)){   //优先级小于栈内，一直循环
                                calculate(numstack, signstack);
                                if (priority(c[i]) > priority(signstack ->elem[signstack ->top]) || (signstack ->top == -1)){
                                    push(signstack, c[i]);
                                    foundsign++;
                                    foundnum = 0;
                                    if (foundsign==2)
                                        return ERROR;
                                    break;
                                }
                            }
                        }
                    }
                }
        }
        else{
            return ERROR;
        }
    }
    if ((signstack ->top) > 2*(numstack ->top-1))       //这是我自己推的公式不知道正不正确，运算符（不包括括号）最多为2(n-1)个
        return ERROR;
    while (signstack ->top != -1){      //符号栈不为空
        if (!calculate(numstack, signstack) || numstack ->top == -1)
            return ERROR;
    }
    return SUCCESS;
}

Status calculate(Stack *numstack, Stack *signstack)
{
    int n, n1, n2;
    int sign;
    pop(numstack, &n2);
    pop(numstack, &n1);//这里出现问题;
    pop(signstack, &sign);
    switch (sign){
    case '+':
        n = n1 + n2;
        break;
    case '-':
        n = n1 - n2;
        break;
    case '/':
        if (n2==0 || n1%n2 != 0)
            return ERROR;
        n = n1 / n2;
        break;
    case '*':
        n = n1 * n2;
        break;
    }
    push(numstack, n);
    return SUCCESS;
}
