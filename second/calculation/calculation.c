#include <stdlib.h>
#include "calculation.h"

Status init(Stack *s)                  //��ʼ��ջ
{
    s ->elem = (ElemType *)malloc(max_size * sizeof(ElemType));    //ȷ����С������,int����װ�ַ����˷Ѱ���;
    if (!(s ->elem))
        return ERROR;
    s ->top = -1;
    return SUCCESS;
}

Status clear(Stack *s)                            //���ջ
{
    if (!s){
        return ERROR;
    }
    s ->top = -1;
    return SUCCESS;
}

Status push(Stack *s,ElemType data)              //��ջ
{
    if (!s || (s->top) >= max_size-1){
            return ERROR;
    }
    s ->top++;
    s ->elem[s ->top] = data;
    return SUCCESS;
}

Status pop(Stack *s,ElemType *data)              //��ջ
{
    if (!s || (s ->top)<0)
        return ERROR;
    *data = s ->elem[s ->top];
    s ->top--;
    return SUCCESS;
}

int priority (int sign)                     //�������������ȼ�
{
    int ret;
    switch (sign){
        case '(':
            ret = 0;
            break;              //�������������ֱ����ջ������ջ������С��

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

void right(Stack *numstack, Stack *signstack)//�������������ţ���Ϊ��Ҫ�ҵ�������
{
    int sign; //��ʱ�����������������
    sign = signstack ->elem[signstack ->top];
    while (sign != '('){
        calculate(numstack, signstack);
        pop(signstack, &sign);  //���ų�ջ;
    }
}
Status result(char c[], int length, Stack *numstack, Stack *signstack)                          //������ջûҪ�󣬷�����ջ�ñȽϻ������Ϊ��ֱ��¿;
{
    int i = 0;
    int j = 0;
    int foundnum, foundsign;    //found����Ƿ��������Ż������֣��� -- ++���ֲ������߼�
    foundnum = foundsign = 0;
    int value = 0; //���ַ����͵�����ת��Ϊint���ʹ�������;
    int check = 0; //check����������ŵ�������;
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

                if (c[i] == '(' ){    //�����������   ���������ź�Ӣ������ASCII�Ĳ�ͬ���Ӽ��˳�һ����
                    push(signstack,c[i]);
                    check++;      //check�������;���Ƕ������ž�����
                    foundsign = 0;  //��Ϊ��������,����������� "+(-"��������������ĳ��֣�
                }

                else if (c[i] == ')'){
                    if (signstack ->top == -1 || check<1){
                        return ERROR;
                    }
                    else {
                        check--;    //�п����Ƕ�������;
                        right(numstack, signstack);
                    }

                }
                else {
                    if (i == 0){   //��ͷΪ�����Ļ�
                        if (c[0] == '-'){
                            push(numstack, 0);
                            push(signstack, c[0]);
                            foundsign++;
                            foundnum = 0;
                            if (foundsign==2)
                                return ERROR;
                        }
                    }
                    else if (signstack ->top == -1){    //��û�з��Ŵ������
                        push(signstack,c[i]);
                        foundsign++;
                        foundnum = 0;
                        if (foundsign==2)
                            return ERROR;
                    }
                    else {                              //ջ���з��Ŵ�������
                        if (priority(c[i]) > priority(signstack ->elem[signstack ->top])){  //�µ����ȼ�������
                            if (signstack ->elem[signstack ->top] == '(' && c[i] == '-' && foundnum == 0)    //�����ź�����ָ���
                                push(numstack, 0);      //��� 0-��
                            push(signstack,c[i]);
                            foundsign++;
                            foundnum = 0;
                            if (foundsign==2)
                                return ERROR;
                        }
                        else {
                            while ((priority(c[i]) <= priority(signstack ->elem[signstack ->top]))&& (signstack ->top >= 0)){   //���ȼ�С��ջ�ڣ�һֱѭ��
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
    if ((signstack ->top) > 2*(numstack ->top-1))       //�������Լ��ƵĹ�ʽ��֪��������ȷ������������������ţ����Ϊ2(n-1)��
        return ERROR;
    while (signstack ->top != -1){      //����ջ��Ϊ��
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
    pop(numstack, &n1);//�����������;
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
