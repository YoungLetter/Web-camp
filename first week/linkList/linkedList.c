#include "../head/linkedList.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */

Status InitList(LinkedList *L) {
    *L = (LinkedList)malloc(sizeof(LNode));//一级指针
    if (!(*L)){
        return ERROR;
    }
    (*L)->next = NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LinkedList q;
    if (*L){
        while ((*L)!=NULL){
            q = (*L)->next;
            free(*L);
            *L = q;
        }
    }
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    if (p==NULL){
        return ERROR;
    }
    else {
        q->next = p->next;
        p->next = q;
        return SUCCESS;
    }
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e//赋值给e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    if (p==NULL || p->next==NULL || e==NULL)
        return ERROR;
    LinkedList cur;
    cur = p->next;
    *e = cur->data;
    p->next = cur->next;
    free(cur);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LinkedList temp;
    temp = L;
    while (temp){
        visit(temp->data);
        temp = temp->next;
    }
}

void visit (ElemType e){
    printf("%d ", e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    LinkedList entry;
    entry = L;
    while (entry){
        if (entry->data==e){
            return SUCCESS;
        }
        entry= entry->next;
    }
    return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    if (L==NULL || (*L)==NULL || ((*L)->next)==NULL)
        return ERROR;
    LinkedList pre = *L;  //记录原先的头;
    *L = NULL;            //让原先的头指向空;
    while (pre){
        LinkedList q = pre;
        pre = pre ->next;   //冲到尾节点后面的NUll;
        q->next = *L;       //反转;
        *L = q;          //未来的头,慢pre一步;
    }
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    LinkedList fast, slow;
    fast = slow = L;
    while (fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow){
            return SUCCESS;
        }
    }
    return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
    if (L==NULL || (*L)==NULL || ((*L)->next)==NULL){
        return ERROR;
    }
    LinkedList pre = *L;  //记录原先的头;
    *L = NULL;            //让原先的头指向空;
    int sum = 1;
    while (pre){
        LinkedList q = pre;
        pre = pre ->next;   //冲到尾节点后面的NUll;
        q->next = *L;       //反转;
        *L = q;          //未来的头,慢pre一步;
        sum ++;             //计数，每次双数，值交换;
        if (sum%2 == 0 && pre != NULL){
            int temp = pre ->data;
            pre ->data = (*L)->data;
            (*L) ->data = temp;
        }
    }
    return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    LinkedList slow, fast;
    fast = slow = *L;
    while (fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

