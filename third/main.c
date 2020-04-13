#include <stdio.h>
#include <stdlib.h>
#include "LQueue/LQueue.h"
#include <string.h>
#include "AQueue/AQueue.h"

int space = 0;  //ͨ����������.c�����䴫�������������ʹ�С
int initLQ();     //��ʼ��ͼ

char type = 0;
int initAQ();
int main()
{
    char choice;
    printf("����������ѡ��:(��һ������Ϊ׼)\n");
    printf("\t��1�� ˳�����   ��2�� ѭ������ \n");
    fflush(stdin);
    choice = getchar();
    fflush(stdin);
    while (choice < '1' || choice >'2'){
        printf("\t�����������������:\n\t\t\t\t");
        choice = getchar();
		fflush(stdin);
    }
    system("cls");
    if (choice == '1'){
        int sign = 0;
        LQueue head ;  //����ͷ
        head.length = 0;    //��ʼ��ͷ��
        int a = initLQ(); //��ȡҪ����ʲô����
        void *data;     //����Ҫ�����������memcpy������ͨ������������
        while (a!=9){
            switch (a){

                case 0:             //��ʼ��
                    if (sign)    //�����Ϊ�վ��ȴݻ�
                        DestoryLQueue(&head);
                    InitLQueue(&head);
                    printf("\t�����ɹ���\n");
                    printf("\t");
                    sign = 1;
                    system("pause");
                    break;

                case 1:                     //���
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else {
                        printf("\t��ѡ����ӵ��������ͣ�\n\t");
                        printf("\t1 char    2  int   3  double\n\t\t\t\t");
                        fflush(stdin);
                        char c = getchar();
                        fflush(stdin);
                        while (c < '1' || c > '3'){     //ȷ����ȷ������
                            printf("\t������������!���������룺\n\t\t\t\t");
                            c = getchar();
                            fflush(stdin);
                        }
                        fflush(stdin);

                        printf("\t���������ֻ��ַ�\n\t\t\t\t");
                        if (c == '1'){
                            char num;
                            while (scanf("%c", &num) != 1){
                                fflush(stdin);
                                printf("\t�����������������:\n\t\t\t\t");
                            }
                            data = (void *)malloc(sizeof(char));
                            memcpy(data, &num, sizeof(char));
                            space = sizeof(char);
                            if (EnLQueue(&head, data))
                                printf("\t��%c����ӳɹ�\n", num);
                            else
                                printf("\t���ʧ��\n");
                            data = NULL;
                            free(data);
                        }
                        else if (c == '2'){
                            int num;//00720D38
                            while (scanf("%d", &num) != 1){
                                fflush(stdin);
                                printf("\t�����������������:\n\t\t\t\t");
                            }
                            data = (void *)malloc(sizeof(int));
                            memcpy(data, &num, sizeof(int));
                            space = sizeof(int);
                            //printf("��ַΪ%p\n", data);
                            if (EnLQueue(&head, data))
                                printf("\t��%d����ӳɹ�\n", num);
                            else
                                printf("\t���ʧ��\n");
                            data = NULL;
                            free(data);
                        }
                        else if (c == '3'){
                            double num;
                            while (scanf("%lf", &num) != 1){
                                fflush(stdin);
                                printf("\t�����������������:\n\t\t\t\t");
                            }
                            data = (void *)malloc(sizeof(double));
                            memcpy(data, &num, sizeof(double));
                            space = sizeof(double);
                            if (EnLQueue(&head, data))
                                printf("\t��%f����ӳɹ�\n", num);
                            else
                                printf("\t���ʧ��\n");
                            data = NULL;
                            free(data);
                        }
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 2:             //�������
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else if (IsEmptyLQueue(&head)){
                        printf("\t����Ϊ��\n");
                    }
                    else {
                        TraverseLQueue(&head);
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 3:             //����
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else if (IsEmptyLQueue(&head)){
                        printf("\t����Ϊ��\n");
                    }
                    else {
                        if(DeLQueue(&head))
                            printf("\t�������\n");
                        else
                            printf("\t����ʧ��\n");
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 4:             //�ж��Ƿ�Ϊ��
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else {
                        if (IsEmptyLQueue(&head))
                            printf("\t����Ϊ��\n");
                        else {
                            printf("\t���в�Ϊ��\n");
                        }
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 5:             //���
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else if (IsEmptyLQueue(&head)){
                        printf("\t����Ϊ��\n");
                    }
                    else {
                        ClearLQueue(&head);
                        printf("\t��ճɹ�\n");
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 6:             //����ͷ
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else if (IsEmptyLQueue(&head)){
                        printf("\t����Ϊ��\n");
                    }
                    else {
                        void *get;
                        GetHeadLQueue(&head, get);
                        free(get);
                        get = NULL;
                    }

                    printf("\t");
                    system("pause");
                    break;

                case 7:             //�ݻ�
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else {
                        DestoryLQueue(&head);
                        printf("\t�ݻٳɹ�\n"); //problem
                        sign = 0;
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 8:                     //ȷ������
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else if (IsEmptyLQueue(&head)){
                        printf("\t����Ϊ��\n");
                    }
                    else {
                        printf("\t���г���Ϊ%d\n", LengthLQueue(&head));
                    }
                    printf("\t");
                    system("pause");
                    break;

            }
            system("cls");
            a = initLQ();//��������
        }
    }
    else if (choice == '2'){
        int sign = 0;
        int flag = 0; //����ȷ���Ƿ��Ѿ�ȷ���������
        AQueue head ;  //����ͷ
        int a = initAQ(); //��ȡҪ����ʲô����
        void *data = NULL;     //����Ҫ�����������memcpy������ͨ������������
        while (a!=9){
            switch (a){

                case 0:             //��ʼ��
                    if (sign)    //�����Ϊ�վ��ȴݻ�
                        DestoryAQueue(&head);
                    InitAQueue(&head);
                    printf("\t�����ɹ���\n");
                    printf("\t");
                    sign = 1;
                    system("pause");
                    break;

                case 1:                     //���
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else {
                        if (!flag){
                            flag = 1;
                            printf("\t��ѡ���������ͣ�\n\t");
                            printf("\t1 char    2  int   3  double\n\t\t\t\t");
                            fflush(stdin);
                            char c = getchar();
                            fflush(stdin);
                            while (c < '1' || c > '3'){     //ȷ����ȷ������
                                printf("\t������������!���������룺\n\t\t\t\t");
                                c = getchar();
                                fflush(stdin);
                            }
                            fflush(stdin);
                            if (c == '1')
                                type = sizeof(char);
                            else if (c == '2')
                                type = sizeof(int);
                            else if (c == '3')
                                type = sizeof(double);
                        }

                        printf("\t���������ֻ��ַ�\n\t\t\t\t");
                        if (type == sizeof(char)){
                            char num;
                            while (scanf("%c", &num) != 1){
                                fflush(stdin);
                                printf("\t�����������������:\n\t\t\t\t");
                            }
                            data = (void *)malloc(sizeof(char));
                            memcpy(data, &num, sizeof(char));
                            if (EnAQueue(&head, data))
                                printf("\t��%c����ӳɹ�\n", num);
                            else
                                printf("\t���ʧ��\n");
                            data = NULL;
                            free(data);
                        }
                        else if (type== sizeof(int)){
                            int num;
                            while (scanf("%d", &num) != 1){
                                fflush(stdin);
                                printf("\t�����������������:\n\t\t\t\t");
                            }
                            data = (void *)malloc(sizeof(int));
                            memcpy(data, &num, sizeof(int));
                            if (EnAQueue(&head, data))
                                printf("\t��%d����ӳɹ�\n", num);
                            else
                                printf("\t���ʧ��\n");
                            data = NULL;
                            free(data);
                        }
                        else if (type == sizeof(double)){
                            double num;
                            while (scanf("%lf", &num) != 1){
                                fflush(stdin);
                                printf("\t�����������������:\n\t\t\t\t");
                            }
                            data = (void *)malloc(sizeof(double));
                            memcpy(data, &num, sizeof(double));
                            if (EnAQueue(&head, data))
                                printf("\t��%f����ӳɹ�\n", num);
                            else
                                printf("\t���ʧ��\n");
                            data = NULL;
                            free(data);
                        }
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 2:             //�������
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else if (IsEmptyAQueue(&head)){
                        printf("\t����Ϊ��\n");
                    }
                    else {
                        TraverseAQueue(&head, data);
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 3:             //����
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else if (IsEmptyAQueue(&head)){
                        printf("\t����Ϊ��\n");
                    }
                    else {
                        if(DeAQueue(&head))
                            printf("\t�������\n");
                        else
                            printf("\t����ʧ��\n");
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 4:             //�ж��Ƿ�Ϊ��
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else {
                        if (IsEmptyAQueue(&head))
                            printf("\t����Ϊ��\n");
                        else {
                            if (IsFullAQueue(&head))
                                printf("\t����Ϊ��\n");
                            else {
                                printf("\t���в�Ϊ��\n");
                            }
                        }
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 5:             //���
                   if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else if (IsEmptyAQueue(&head)){
                        printf("\t����Ϊ��\n");
                    }
                    else {
                        ClearAQueue(&head);
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 6:             //����ͷ
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else if (IsEmptyAQueue(&head)){
                        printf("\t����Ϊ��\n");
                    }
                    else {
                        void *get = NULL;
                        GetHeadAQueue(&head, get);
                        free(get);
                        get = NULL;
                    }

                    printf("\t");
                    system("pause");
                    break;

                case 7:             //�ݻ�
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else {
                        DestoryAQueue(&head);
                        printf("\t�ݻٳɹ�\n"); //problem
                        sign = 0;
                    }
                    printf("\t");
                    system("pause");
                    break;

                case 8:                     //ȷ������
                    if (!sign){
                        printf("\tδ��ʼ��\n");
                    }
                    else if (IsEmptyAQueue(&head)){
                        printf("\t����Ϊ��\n");
                    }
                    else {
                        printf("\t���г���Ϊ%d\n", LengthAQueue(&head));
                    }
                    printf("\t");
                    system("pause");
                    break;

            }
            system("cls");
            a = initAQ();//��������
        }
    }
    printf("\n\t�����������л����ʹ��\n");
    printf("\t");
   // free(head);
	system("pause");
    return 0;
}


int initLQ()
{
    	printf(
		"\n\t|****************     LQueue��ز���         ****************|\t\n"
		"\t|***   ����      ����                  ����    ����       ***|\t\n"
		"\t|***   0         ��ʼ������            1       ���       ***|\t\n"
		"\t|***   2         �������              3       ����       ***|\t\n"
		"\t|***   4         �ж϶����Ƿ�Ϊ��      5       ���       ***|\t\n"
		"\t|***   6         ����ͷԪ��          7       ����       ***|\t\n"
		"\t|***   8         ȷ�����г���          9       �˳�����   ***|\t\n"
		"\t|____________________________________________________________|\t\n\n"
	);
	printf("\t������������еĲ������Ե�һ���ַ�Ϊ׼����");
	char c;
	fflush(stdin);
	c = getchar();
	fflush(stdin);
	while (c>'9' || c<'0')//���Ϸ�����
	{
		printf("\t������������!���������룺\n\t\t\t\t");
		c = getchar();
		fflush(stdin);
	}
	return (c-'0');
}

int initAQ()
{
    	printf(
		"\n\t|****************     AQueue��ز���         ****************|\t\n"
		"\t|***   ����      ����                  ����    ����       ***|\t\n"
		"\t|***   0         ��ʼ������            1       ���       ***|\t\n"
		"\t|***   2         �������              3       ����       ***|\t\n"
		"\t|***   4         �ж϶����Ƿ������    5       ���       ***|\t\n"
		"\t|***   6         ����ͷԪ��          7       ����       ***|\t\n"
		"\t|***   8         ȷ�����г���          9       �˳�����   ***|\t\n"
		"\t|____________________________________________________________|\t\n\n"
	);
	printf("\t������������еĲ������Ե�һ���ַ�Ϊ׼����");
	char c;
	fflush(stdin);
	c = getchar();
	fflush(stdin);
	while (c>'9' || c<'0')//���Ϸ�����
	{
		printf("\t������������!���������룺\n\t\t\t\t");
		c = getchar();
		fflush(stdin);
	}
	return (c-'0');
}
