#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>

extern int flag;    //��������.c�ļ�

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

Status CreateBiTree(BiTree *T)   //���ȳ�ʼ�����ܴ���
{
    if (!(*T)) {                //����ýڵ�Ϊ�գ��ʹ���һ�����ף������ն��ӽṹ����
        if (!InitBiTree(T))
            return ERROR;
    }
    TElemType c;
    fflush(stdin);
    c = getchar();
    fflush(stdin);
    if (c == '@'|| c == '\n') {  //����ýڵ�Ϊ�գ�Ҳû��������ʲô�����ˣ��Ϳ�ʼ����
        *T = NULL;
        free(*T);
        return ERROR;
    }
    else {
        (*T) ->data = c;
        printf("\t������%c����ڵ�����:",c);
        CreateBiTree(&(*T) ->lchild);
        printf("\t������%c���ҽڵ�����:",c);
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

Status EnLQueue(LQueue *Q, BiTree T)
{
    Node *new = (Node *)malloc(sizeof(Node));//�½��ڵ�
    if (new == NULL){
        return ERROR;
    }
    else {
        new->data = T;
        new ->next = NULL;
        if (Q ->length == 0){ //��
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
    Node *temp = Q ->front;         //��ͷ���ݴ���
    Q ->front = temp->next;         //��ͷΪ��һλѡ��

    if (Q ->rear == temp)    //һ������������ֻ��һ��Ԫ�أ���ʱβָ��ͷָ��ָ���;
        Q ->rear = Q ->front;

    BiTree head = temp->data;
    Q ->length--;
    free(temp);
    return head;
}

//����ȫ�ֱ���s,number��������ַ�������s��
char s[1000] = {'\0'};
int number = 0;

Status Create(BiTree *T)   //���ȳ�ʼ�����ܴ���
{
    if (!(*T)) {                //����ýڵ�Ϊ�գ��ʹ���һ�����ף������ն��ӽṹ����
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
    if ((c = getchar())!='\n') {    //������������б��Ԫ��˵������������
        return ERROR;
    }
    fflush(stdin);
    if (numofnum-1 == numofsign) {
        return SUCCESS;
    }
    else
        return ERROR;
}

void setzero()  //��s����
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
                    flag = 1;           //ͨ����������.c�ļ���flag���ж��Ƿ��г���Ϊ������
                }
        }
    }
}
