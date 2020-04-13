#include <stdlib.h>
#include "AQueue.h"
#include <string.h>
#include <stdio.h>

void InitAQueue(AQueue *Q)
{
    for (int i = 0; i<MAXQUEUE; i++){
        Q ->data[i] = (void *)malloc(type);
        if (Q ->data[i] == NULL){
            printf("\t����ռ�ʧ��\n");
            return;
        }
    }
    Q ->front = 0;  // 0 < front < MAX�� ���Կ��ܳ��� front + length > MAX;
    Q ->rear = 0;   //rear �� 0 < rear < MAX;
    Q ->length = 0;
}

void DestoryAQueue(AQueue *Q)
{
    for (int i = 0; i<MAXQUEUE; i++){
        free(Q ->data[i]);
    }
    ClearAQueue(Q);
}
status IsFullAQueue(const AQueue *Q)
{
    if (Q ->length == MAXQUEUE){
        return SUCCESS;
    }
    else
        return ERROR;
}

status IsEmptyAQueue(const AQueue *Q)
{
    if (Q ->length == 0)
        return SUCCESS;
    else
        return ERROR;
}

status GetHeadAQueue(AQueue *Q, void *e)
{
    if (IsEmptyAQueue(Q))
        return ERROR;
    else {
        e = (void *)malloc(type);
        memcpy(e, Q ->data[Q ->front], type);
        printf("\t�ö�ͷԪ��Ϊ\n\t\t\t");
        APrint(e);
        printf("\n");
        return SUCCESS;
    }
}
int LengthAQueue(AQueue *Q)
{
    return (int)(Q ->length);
}
status EnAQueue(AQueue *Q, void *data)
{
    if (IsFullAQueue(Q)){
        printf("\t��������\n");
        return ERROR;
    }
    else {
        memcpy(Q ->data[Q ->rear],data, type);
        Q ->length++;
        Q ->rear = (Q ->rear+1)%MAXQUEUE;   //ͨ��ȡ��ó���һ��λ��;
        return SUCCESS;
    }
}
status DeAQueue(AQueue *Q)
{
    if (IsEmptyAQueue(Q))
        return ERROR;
    else {
        Q ->front = (Q ->front+1)%MAXQUEUE;
        Q ->length--;
        return SUCCESS;
    }
}
void ClearAQueue(AQueue *Q) //ֻ��Ҫ��ն�����ɾ��
{
    Q ->front = 0;
    Q ->rear = 0;
    Q ->length = 0;//�ع����;
}

status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
    if (IsEmptyAQueue(Q))
        return ERROR;
    else {
        int i;
        printf("\t");
        if (Q ->length + Q->front > MAXQUEUE){  //���־ͻ����i���ż��žʹ���MAX;
            for (i = Q ->front; i < MAXQUEUE; i++){
                APrint(Q ->data[i]);
                printf(" --> ");
            }
            for (i = 0; i < Q ->rear; i++){
                APrint(Q ->data[i]);
                if (i != Q ->rear-1)
                    printf(" --> ");
            }
            printf("\n");
        }
        else {
            for (i = Q ->front; i < (Q ->length + Q ->front); i++){
                APrint(Q ->data[i]);
                if (i < (Q ->length + Q ->front -1)){
                    printf(" --> ");
                }
            }
            printf("\n");
        }
        return SUCCESS;
    }
}
void APrint(void *q)
{
    if (type == 1){
        printf("%c", *(char *)q);
    }
    else if (type == 2 || type == 4){
        printf("%d", *(int *)q);
    }
    else if (type == 8){
        printf("%f", *(double *)q);
    }
    else {
        printf("�������\n");
    }
}
