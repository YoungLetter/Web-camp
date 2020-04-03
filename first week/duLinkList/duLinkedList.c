#include "../head/duLinkedList.h"
#include <stdlib.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    (*L) = (DuLNode *)malloc(sizeof(DuLNode));
    if (!(*L))
        return ERROR;
    else {
        (*L) ->next = NULL;
        (*L) ->prior = NULL;
    }
    return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList q ;
    if (!L){
        while (*L){
            q = (*L)->next;
            free(*L);
            *L = q;
            if (q){     //如果这个不为空，就删除前面的节点;
                q ->prior =NULL;
            }
        }
    }

}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if (p==NULL){
        return ERROR;
    }
    if (p ->prior){         //如有p前面有人;
        p ->prior ->next = q;
        q ->prior = p->prior;
    }
    q ->next = p;
    p ->prior = q;
    return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if (p==NULL){
        return ERROR;
    }
    if (p ->next){        // 如有后面有人;
        p ->next ->prior = q;
        q ->next = p->next;
    }
    p ->next = q;
    q ->prior = p;
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if (p == NULL || p ->next == NULL || e == NULL){
        return ERROR;
    }
    DuLinkedList temp;
    temp = p ->next;    //暂存要删除节点;
    p ->next = temp ->next;
    temp ->next ->prior = p;
    *e = temp ->data;
    free(temp);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    DuLinkedList cur;
    cur = L;
    while (cur){
        (*visit)(cur ->data);//函数指针加*；
        cur = cur ->next;
    }
}
