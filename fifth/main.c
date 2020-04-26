#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree/BinaryTree.h"

int initBT();
int flag = 0;
int main()
{
    int sign = 0;
    BiTree head;  //����ͷ
    int ret = initBT();
    while (ret != 8){
            switch (ret){
                case 0:                     //��ʼ��
                    if (sign == 2)
                        printf("\t���Ѵ����ˣ���ʼ����ݻ�ԭ������Ŷ\n");
                    if (sign)               //�����Ϊ�վ��ȴݻ�
                        DestroyBiTree(&head);
                    InitBiTree(&head);
                    printf("\t�����ɹ���\n");
                    printf("\t");
                    sign = 1;
                    system("pause");
                    break;
                case 1:             //ǰ��
                    if (sign < 1){
                        printf("\tδ��ʼ��\n");
                    }
                    else if (sign < 2) {
                        printf("\tδ����\n");
                    }
                    else {
                        printf("\t�������Ϊ:");
                        if (PreOrderTraverse(head, visit))
                            printf("\n");
                        else
                            printf("\t����ʧ��\n");
                    }
                    printf("\t");
                    system("pause");
                    break;
                case 2:
                     if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else if (sign == 2) {
                        printf("\t�Ѿ�������\n");
                    }
                    else {
                        printf("\t�밴���������˳���������������,���س�������һ���������,@�ַ��൱�ڿս��\n\t");
                        if (CreateBiTree(&head)) {
                            printf("\t����ɹ�\n");
                            sign = 2;
                        }
                    }
                    printf("\t");
                    system("pause");
                    break;
                case 3:             //����
                    if (sign < 1){
                        printf("\tδ��ʼ��\n");
                    }
                    else if (sign < 2) {
                        printf("\tδ����\n");
                    }
                    else {
                        printf("\t�������Ϊ:");
                        if (InOrderTraverse(head, visit))
                            printf("\n");
                        else
                            printf("\t����ʧ��\n");
                    }
                    printf("\t");
                    system("pause");
                    break;
                case 4:
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else {
                       if (DestroyBiTree(&head)) {
                            printf("\t�ݻٳɹ�\n");
                            sign = 0;
                       }
                       else
                            printf("\t�ݻ�ʧ��\n");
                    }
                    printf("\t");
                    system("pause");
                    break;
                case 5:
                   if (sign < 1){
                        printf("\tδ��ʼ��\n");
                    }
                    else if (sign < 2) {
                        printf("\tδ����\n");
                    }
                    else {
                        printf("\t�������Ϊ:");
                        if (PostOrderTraverse(head, visit))
                             printf("\n");
                        else
                            printf("\t����ʧ��\n");
                    }
                    printf("\t");
                    system("pause");
                    break;
                case 6:
                    printf("\n\t��������ȷ��ǰ׺���ʽ��ֻ����0~9 �� +-*/��\n\t");
                    BiTree expression;
                    InitBiTree(&expression);
                    Create(&expression);
                    if (!judge())
                        printf("\t������������\n");
                    else {
                        int result = Calculate(expression);
                        if (flag == 1) {
                            printf("\t�����������г��ֳ���Ϊ������\n");
                            flag = 0;
                        }
                        else
                            printf("\t���ʽ�Ľ����%d\n", result);
                    }
                    setzero();
                    DestroyBiTree(&expression);
                    printf("\t");
                    system("pause");
                    break;
                case 7:
                    if (sign < 1){
                        printf("\tδ��ʼ��\n");
                    }
                    else if (sign < 2) {
                        printf("\tδ����\n");
                    }
                    else {
                        printf("\t��α���Ϊ:");
                        if (LevelOrderTraverse(head, visit))
                             printf("\n");
                        else
                            printf("\t����ʧ��\n");
                    }
                    printf("\t");
                    system("pause");
                    break;
            }
            system("cls");
            ret = initBT();       //��������
    }
    printf("\t��л����ʹ��\n\t");
    system("pause");
}

int initBT()
{
    	printf(
		"\n\t|****************     BinaryTree��ز���         ****************|\t\n"
		"\t|***   ����      ����                  ����    ����           ***|\t\n"
		"\t|***   0         ��ʼ��������          1       �������       ***|\t\n"
		"\t|***   2         �����ַ�              3       �������       ***|\t\n"
		"\t|***   4         �ݻ���                5       �������       ***|\t\n"
		"\t|***   6         ǰ׺������            7       ��α���       ***|\t\n"
		"\t|***                     8  �� �� �� ��                       ***|\t\n"
		"\t|________________________________________________________________|\t\n\n"
	);
	printf("\t������������еĲ������Ե�һ���ַ�Ϊ׼����");
	char c;
	fflush(stdin);
	c = getchar();
	fflush(stdin);
	while (c>'8' || c<'0')//���Ϸ�����
	{
		printf("\t������������!���������룺\n\t\t\t\t");
		c = getchar();
		fflush(stdin);
	}
	return (c-'0');
}
