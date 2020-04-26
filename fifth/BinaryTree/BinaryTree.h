#ifndef BINARY_TREE
#define BINARY_TREE

typedef char TElemType;     // 假设二叉树结点的元素类型为字符

typedef struct  BiTNode {
    TElemType data;     // 数据域
    struct BiTNode  *lchild,*rchild;  // 左、右孩子指针
} BiTNode,*BiTree;   // 二叉链表

typedef enum Status{
	ERROR,
	SUCCESS
}Status;

/**
 *  @description : 初始化二叉树
 */

Status InitBiTree(BiTree *T);

/**
 *  @description : 销毁二叉树
 */

Status DestroyBiTree(BiTree *T);

/**
 *  @description : 按先序遍历的顺序输入形成二叉树
 */

Status CreateBiTree(BiTree *T);

/**
 *  @description : 输出data数据
 */

Status visit(TElemType e);

/**
 *  @description : 前序遍历
 */

Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));

/**
 *  @description : 中序遍历
 */

Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));

/**
 *  @description : 后序遍历
 */

Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e));

/**
 *  @description : 层序遍历
 */

Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));

/**
 *  @description : 层序遍历时所需要的队列函数操作
 */

typedef struct node
{
    BiTree data;
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    int length;
} LQueue;

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *  @description : 初始化队列
 */

void InitLQueue(LQueue *Q);

/**
 *  @name        : BiTree GetHeadLQueue(LQueue *Q)
 *   @description : 返回并销毁队头元素
 */

BiTree GetHeadLQueue(LQueue *Q);

/**
 *  @name        : Status EnLQueue(LQueue *Q, BiTree T)
 *  @description : 入队操作
 */

Status EnLQueue(LQueue *Q, BiTree T);

/**
 *  @description : 将表达式构建成二叉树
 */

Status Create(BiTree *T);

/**
 *  @description : 判断输入是否正确
 */

Status judge ();

/**
 *  @description : 将用来判断正确所用到的字符数组置零
 */

void setzero();

/**
 *  @description : 计算二叉树的值
 */

int Calculate(BiTree T);

#endif // BINART_TREE
