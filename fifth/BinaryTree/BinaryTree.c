#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>

extern int flag;    //连接两个.c文件

Status InitBiTree(BiTree *T)
{
    *T = (BiTree)malloc(sizeof(BiTNode));
    if (!(*T))
        return ERROR;
    else {
        (*T) ->lchild = (*T) ->rchild = NULL;
        (*T) ->data = '\n';
        return SUCCESS;
    }
}

Status DestroyBiTree(BiTree *T)
{
    if (!T)
        return ERROR;
    else {
        if ((*T) ->lchild != NULL)
            DestroyBiTree(&((*T) ->lchild));
        if ((*T) ->rchild != NULL)
            DestroyBiTree(&((*T) ->rchild));
        *T = NULL;
        free(*T);
    }
    return SUCCESS;
}

Status CreateBiTree(BiTree *T)   //得先初始化才能创建
{
    if (!(*T)) {                //如果该节点为空，就创建一个父亲，两个空儿子结构给它
        if (!InitBiTree(T))
            return ERROR;
    }
    TElemType c;
    fflush(stdin);
    c = getchar();
    fflush(stdin);
    if (c == '@'|| c == '\n') {  //如果该节点为空，也没有它儿子什么事情了，就开始回溯
        *T = NULL;
        free(*T);
        return ERROR;
    }
    else {
        (*T) ->data = c;
        printf("\t请输入%c的左节点数据:",c);
        CreateBiTree(&(*T) ->lchild);
        printf("\t请输入%c的右节点数据:",c);
        CreateBiTree(&(*T) ->rchild);
    }
    return SUCCESS;
}

Status visit(TElemType e)
{
    if (e == '\n');
    else
        printf("  %c  ", e);
    return SUCCESS;
}
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if(T) {
        visit(T ->data);
		PreOrderTraverse(T->lchild, visit);
		PreOrderTraverse(T->rchild, visit);
		return SUCCESS;
	}
	return ERROR;
}

Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if (T) {
		InOrderTraverse(T->lchild, visit);
		visit(T ->data);
		InOrderTraverse(T->rchild, visit);
		return SUCCESS;
	}
	return ERROR;
}

Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if (T) {
        PostOrderTraverse(T ->lchild, visit);
        PostOrderTraverse(T ->rchild, visit);
        visit(T ->data);
        return SUCCESS;
    }
    return ERROR;
}

Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    LQueue *Q = (LQueue *)malloc(sizeof(LQueue));
    InitLQueue(Q);
	EnLQueue(Q, T);
	while (Q ->front != NULL){
        BiTree temp = GetHeadLQueue(Q);
		visit(temp ->data);
		if(temp ->lchild){
			EnLQueue(Q, temp ->lchild);
		}
		if(temp ->rchild){
			EnLQueue(Q, temp ->rchild);
		}
	}
	return SUCCESS;
}

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

Status EnLQueue(LQueue *Q, BiTree T)
{
    Node *new = (Node *)malloc(sizeof(Node));//新建节点
    if (new == NULL){
        return ERROR;
    }
    else {
        new->data = T;
        new ->next = NULL;
        if (Q ->length == 0){ //空
            Q ->front = new;
            Q ->rear = new;
        }
        else {
            Q ->rear ->next = new;
            Q ->rear = new;
        }
        Q ->length++;
        return SUCCESS;
    }

}
BiTree GetHeadLQueue(LQueue *Q)
{
    Node *temp = Q ->front;         //队头数据储存
    Q ->front = temp->next;         //队头为下一位选手

    if (Q ->rear == temp)    //一种特殊情况如果只有一个元素，此时尾指针头指针指向空;
        Q ->rear = Q ->front;

    BiTree head = temp->data;
    Q ->length--;
    free(temp);
    return head;
}

//利用全局变量s,number将输入的字符储存在s中
char s[1000] = {'\0'};
int number = 0;

Status Create(BiTree *T)   //得先初始化才能创建
{
    if (!(*T)) {                //如果该节点为空，就创建一个父亲，两个空儿子结构给它
        if (!InitBiTree(T))
            return ERROR;
    }
    TElemType c;
    c = getchar();
    s[number++] = c;
    if (c>= '0' && c<='9') {
        (*T) ->data = c;
    }
    else {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            (*T) ->data = c;
            Create(&((*T) ->lchild));
            Create(&((*T) ->rchild));
        }
        else
            return ERROR;
    }
    return SUCCESS;
}
Status judge ()
{
    if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/');
    else
        return ERROR;

    char c = 0;
    int numofnum, numofsign;
    numofnum = numofsign = 0;
    for (int i=0; s[i]!='\0'; i++){
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            numofsign++;
        }
        else if (s[i]>='0'&&s[i]<='9') {
            numofnum++;
        }
        else
            return ERROR;
    }
    if ((c = getchar())!='\n') {    //如果缓冲区还有别的元素说明输入有问题
        return ERROR;
    }
    fflush(stdin);
    if (numofnum-1 == numofsign) {
        return SUCCESS;
    }
    else
        return ERROR;
}

void setzero()  //将s置零
{
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = '\0';
    }
    number = 0;
}

int Calculate(BiTree T)
{
    TElemType c = T ->data;
    if (c>='0' && c<='9') {
        return ((int)(c-'0'));
    }
    else {
        int left = Calculate(T ->lchild);
        int right = Calculate(T ->rchild);
        if (c == '+') {
            return (left+right);
        }
        else if (c == '-') {
            return (left-right);
        }
        else if (c == '*') {
            return (left*right);
        }
        else if (c == '/') {
                if (right != 0)
                    return (left/right);
                else {
                    flag = 1;           //通过连接两个.c文件的flag来判断是否有除数为零的情况
                }
        }
    }
}
