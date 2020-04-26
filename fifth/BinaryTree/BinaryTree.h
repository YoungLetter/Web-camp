#ifndef BINARY_TREE
#define BINARY_TREE

typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�

typedef struct  BiTNode {
    TElemType data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode,*BiTree;   // ��������

typedef enum Status{
	ERROR,
	SUCCESS
}Status;

/**
 *  @description : ��ʼ��������
 */

Status InitBiTree(BiTree *T);

/**
 *  @description : ���ٶ�����
 */

Status DestroyBiTree(BiTree *T);

/**
 *  @description : �����������˳�������γɶ�����
 */

Status CreateBiTree(BiTree *T);

/**
 *  @description : ���data����
 */

Status visit(TElemType e);

/**
 *  @description : ǰ�����
 */

Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));

/**
 *  @description : �������
 */

Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));

/**
 *  @description : �������
 */

Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e));

/**
 *  @description : �������
 */

Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));

/**
 *  @description : �������ʱ����Ҫ�Ķ��к�������
 */

typedef struct node
{
    BiTree data;
    struct node *next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
    int length;
} LQueue;

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *  @description : ��ʼ������
 */

void InitLQueue(LQueue *Q);

/**
 *  @name        : BiTree GetHeadLQueue(LQueue *Q)
 *   @description : ���ز����ٶ�ͷԪ��
 */

BiTree GetHeadLQueue(LQueue *Q);

/**
 *  @name        : Status EnLQueue(LQueue *Q, BiTree T)
 *  @description : ��Ӳ���
 */

Status EnLQueue(LQueue *Q, BiTree T);

/**
 *  @description : �����ʽ�����ɶ�����
 */

Status Create(BiTree *T);

/**
 *  @description : �ж������Ƿ���ȷ
 */

Status judge ();

/**
 *  @description : �������ж���ȷ���õ����ַ���������
 */

void setzero();

/**
 *  @description : �����������ֵ
 */

int Calculate(BiTree T);

#endif // BINART_TREE
