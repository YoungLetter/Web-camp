#include "qgsort.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
//��������
void insertSort(int *a,int n)
{
    int i, j;
    int new;//����������
    for(i=1; i<n; i++){ //����λ�����кõ�
        new = a[i];
        j = i-1;
        while( a[j]>new && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=new;
    }
}

//�ϲ�����
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    int length = end-begin+1;
    temp = (int *)malloc(sizeof(int)*length);
    assert(temp!=NULL);
    int i = begin;  //i�ߵ�mid
    int j = mid+1;  //j�ߵ�end
    int index = 0;  //��¼��ʱ�����λ��
    while (i<=mid && j<=end) {
        temp[index++] = a[i]<=a[j]? a[i++]:a[j++];//"<="�ȶ�����
    }
    while (i<=mid) {
        temp[index++] = a[i++];
    }
    while (j<=end) {
        temp[index++] = a[j++];
    }
    for (i=0; i<length; i++) {
        a[begin++] = temp[i];
    }
    free(temp);
}

void MergeSort(int *a,int begin,int end,int *temp)
{
    if (begin >= end) {
        return;
    }
    int mid = (begin+end)/2;
    MergeSort(a, begin, mid, temp);
    MergeSort(a, mid+1, end, temp);
    MergeArray(a, begin, mid, end, temp);
}

//��������
void swap(int *a,int i,int j)
{
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}

void CountSort(int *a, int size)
{
    int min = a[0];
    int max = a[0];
    int i = 1;
    for(; i<size; i++){//�ҳ������С
        if (a[i]<min){
            min=a[i];
        }
        if (a[i]>max){
            max = a[i];
        }
    }
    int range = max-min+1;
    int *stack = (int*)malloc(sizeof(int)*range);//�����ռ�
    assert(stack!=NULL);   //�ж��Ƿ�Ϊ��
    memset(stack,0,range*sizeof(int));//��ʼ��Ϊ��

    for(i=0; i<size; i++){//ͳ�Ƴ��ִ���
        stack[a[i]-min]++;
    }
    int count=0;
    for(i=0; i<range; i++){//��������
        while(stack[i]--){
            a[count++]=min+i;
        }
    }
    free(stack);
}
//������׼����
int Partition(int *a, int begin, int end)
{
    /*  ����ȡ��  */
    int mid = (begin+end)/2;
    if(a[mid] > a[end]){
        swap(a,mid,end);
    }
    if(a[begin]>a[end]){
        swap(a, begin, end);
    }       //ͨ���������ж�ʹ�����������endλ��;
    if(a[begin]<a[mid]){
        swap(a, begin, mid);
    }       //�ٽ���λ������beginλ

    int temp = a[begin];//���ȱ����һ����,������Ϊ��׼;
    while(end != begin){
        for(; end>begin; end--){
            if(a[end] > temp){
                continue;
            }else break;
        }
        if(end == begin){
                break;
        }
        a[begin]=a[end];

        for(; begin<end; begin++){
            if(a[begin]<=temp){//��Ϊ����㷨���ȶ�������������ֵ��tempһ����,
                continue;    // ������ǵ�����a[low]<temp,���ó������ȥ������������;
            }else break;
        }
        if(end==begin){
                break;
        }
        a[end]=a[begin];
    }
    a[begin]=temp;
    return begin;
}

//���ŵݹ��
void QuickSort_Recursion(int *a, int begin, int end)
{
    int pivot = -1;
	while(begin < end)
	{
		pivot = Partition(a, begin, end);
		QuickSort_Recursion(a, begin, pivot-1);
		begin = pivot + 1;
	}

}

void QuickSort(int *a,int size)
{
    int temp = (int)ceil((log((double)size)/log((double)2)));//��������ÿ�ζ����з֣�
    int *stack = (int*)malloc(temp*2*sizeof(int));//��Ϊ��׼����������,����һ�����ԣ�����Ҫ����2;
    assert(stack!=NULL);
    int top = 0;//�������stack�ռ����;
    int low = 0;
    int high = size-1;
    int mid = Partition(a,low,high);//�ҳ���һ����׼
    if(mid-1>low){         //�ж�����Ƿ�������������
        stack[top++] = low;//�ȸ�ֵ������
        stack[top++] = mid-1;//�����׼��ߵ���β
    }
    if(mid+1<high){
        stack[top++]=mid+1;
        stack[top++]=high;
    }
    while(top>0){          //���Լ��ٸ�ֵ
        high = stack[--top];//ջ������ȳ�
        low = stack[--top]; //ȡ���ұߵ�
        mid = Partition(a,low,high);//�ٴν���ѭ�����൱�ڵݹ���
        if(mid-1>low){
        stack[top++] = low;
        stack[top++] = mid-1;
        }
        if(mid+1<high){
            stack[top++] = mid+1;
            stack[top++] = high;
        }
        //һ��ѭ�������������ж�top�Ƿ�Ϊ�㣬��ջ�Ƿ�Ϊ�գ�����˵ʣ��һ��top������
    }
    free(stack);
}

//�ó���Ӧλ����β��
int figueofnum(int a,int i)
{
    int ret;
    int mask = 1;
    for(; i>1; i--){
        mask *= 10;
    }
    ret = (a/mask)%10;
    return ret;
}

//��Ӧβ����������Ͱ
void inputarray(int size,int a[10][size], int num, int b)
{
    for(int i=0; i<size; i++){
        if(a[num][i] == 0){
            a[num][i] = b;
            break;
        }
    }
}

//�ı�a�����е�����
void outputarray(int *a,int size,int b[10][size])
{
    int i = 0;
    int x,y;    //��ά���������
    for(x=0; x<10; x++){
        for(y=0; y<size; y++){
            if(b[x][y]!=0 && i<size){
                a[i++] = b[x][y];
            }else break;
        }
        if(i>=size){
            break;
        }
    }
}
//��������
void RadixCountSort(int *a,int size)
{
    int i,j;
    int max = a[0];         //���ҳ������е������
    for(i=1; i<size; i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    int mask = 1;       //ȷ��������������λ��;
    while(max/10){
        mask++;
        max /= 10;
    }

    int radio[10][size];          //����һ������ ��Ϊ10����0~9Ͱ����Ϊ������󳤶�
    int num;                        //��¼��Ӧλ����β��
    for(i=1; i<=mask; i++){//i��1��mask-1;
        memset(radio,0,sizeof(radio));
        for(j=0; j<size; j++){                  //����ԭ����
            num = figueofnum(a[j],i);           //����Ӧλ����β��;
            inputarray(size, radio, num, a[j]);//��Ͱ
        }
        outputarray(a,size,radio);
    }
}

//��ɫ����
void ColorSort(int *a,int size)
{
    int p0=0, p2=size-1, index;//p0��������a[index]=0�����֣�p2��������a[index]=2�����֣�index��Ϊ�ƶ�����
    for (index=0; index<=p2; index++){
        if (a[index]==0){   //������㣬����
            swap(a, index, p0);
            p0++;
        }
        if (a[index]==2){   //�ȿ����жϵ�ǰ��index��Ҳ�����ж����潻�����index
            swap(a, index, p2);
            p2--;
            index--;    //�ȼ�1���ټ�1���жϽ�����a[index]��ֵ;
        }

    }
}

//�ҵ���kС��
int find_k_min (int *a, int size, int k)
{
    int left = 0;
    int right = size-1;
    int mid;
    while(left <= right){
	    mid = Partition(a, left, right);
		if(mid+1 == k){ //�ҵ�
            return a[mid];
        }
        else if(mid+1< k){ //���ұ�������
		    left = mid+1;
	    }
	    else{ //�����������
	        right = mid-1;
	    }
	}
	return a[mid];
}
