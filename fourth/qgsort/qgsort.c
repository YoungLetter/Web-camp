#include "qgsort.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
//插入排序
void insertSort(int *a,int n)
{
    int i, j;
    int new;//储存新数据
    for(i=1; i<n; i++){ //第零位是排列好的
        new = a[i];
        j = i-1;
        while( a[j]>new && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=new;
    }
}

//合并数组
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    int length = end-begin+1;
    temp = (int *)malloc(sizeof(int)*length);
    assert(temp!=NULL);
    int i = begin;  //i走到mid
    int j = mid+1;  //j走到end
    int index = 0;  //记录临时数组的位置
    while (i<=mid && j<=end) {
        temp[index++] = a[i]<=a[j]? a[i++]:a[j++];//"<="稳定排序
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

//交换函数
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
    for(; i<size; i++){//找出最大最小
        if (a[i]<min){
            min=a[i];
        }
        if (a[i]>max){
            max = a[i];
        }
    }
    int range = max-min+1;
    int *stack = (int*)malloc(sizeof(int)*range);//构建空间
    assert(stack!=NULL);   //判断是否为空
    memset(stack,0,range*sizeof(int));//初始化为零

    for(i=0; i<size; i++){//统计出现次数
        stack[a[i]-min]++;
    }
    int count=0;
    for(i=0; i<range; i++){//读出数字
        while(stack[i]--){
            a[count++]=min+i;
        }
    }
    free(stack);
}
//划定基准函数
int Partition(int *a, int begin, int end)
{
    /*  三数取中  */
    int mid = (begin+end)/2;
    if(a[mid] > a[end]){
        swap(a,mid,end);
    }
    if(a[begin]>a[end]){
        swap(a, begin, end);
    }       //通过这两个判断使得最高数字在end位上;
    if(a[begin]<a[mid]){
        swap(a, begin, mid);
    }       //再将中位数放在begin位

    int temp = a[begin];//首先保存第一个数,让它成为基准;
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
            if(a[begin]<=temp){//因为这个算法不稳定，当两个数的值与temp一样大,
                continue;    // 如果还是单纯让a[low]<temp,会让程序过不去进而产生错误;
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

//快排递归版
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
    int temp = (int)ceil((log((double)size)/log((double)2)));//假设最坏情况每次都是中分；
    int *stack = (int*)malloc(temp*2*sizeof(int));//因为基准有左右两边,即是一个数对，所以要乘以2;
    assert(stack!=NULL);
    int top = 0;//设置这个stack空间起点;
    int low = 0;
    int high = size-1;
    int mid = Partition(a,low,high);//找出第一个基准
    if(mid-1>low){         //判断左边是否至少两个数字
        stack[top++] = low;//先赋值再自增
        stack[top++] = mid-1;//保存基准左边的首尾
    }
    if(mid+1<high){
        stack[top++]=mid+1;
        stack[top++]=high;
    }
    while(top>0){          //先自减再赋值
        high = stack[--top];//栈：后进先出
        low = stack[--top]; //取出右边的
        mid = Partition(a,low,high);//再次进行循环，相当于递归了
        if(mid-1>low){
        stack[top++] = low;
        stack[top++] = mid-1;
        }
        if(mid+1<high){
            stack[top++] = mid+1;
            stack[top++] = high;
        }
        //一次循环结束，返回判断top是否为零，即栈是否为空，还是说剩下一个top而已了
    }
    free(stack);
}

//得出对应位数的尾数
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

//对应尾数的数字入桶
void inputarray(int size,int a[10][size], int num, int b)
{
    for(int i=0; i<size; i++){
        if(a[num][i] == 0){
            a[num][i] = b;
            break;
        }
    }
}

//改变a数组中的排序
void outputarray(int *a,int size,int b[10][size])
{
    int i = 0;
    int x,y;    //二维数组的坐标
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
//基数排序
void RadixCountSort(int *a,int size)
{
    int i,j;
    int max = a[0];         //先找出数组中的最大数
    for(i=1; i<size; i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    int mask = 1;       //确定整个数组的最大位数;
    while(max/10){
        mask++;
        max /= 10;
    }

    int radio[10][size];          //创建一个数组 行为10，即0~9桶，列为数组最大长度
    int num;                        //记录对应位数的尾数
    for(i=1; i<=mask; i++){//i从1到mask-1;
        memset(radio,0,sizeof(radio));
        for(j=0; j<size; j++){                  //遍历原数组
            num = figueofnum(a[j],i);           //数对应位数的尾数;
            inputarray(size, radio, num, a[j]);//入桶
        }
        outputarray(a,size,radio);
    }
}

//颜色排序
void ColorSort(int *a,int size)
{
    int p0=0, p2=size-1, index;//p0用来交换a[index]=0的数字，p2用来交换a[index]=2的数字，index作为移动数组
    for (index=0; index<=p2; index++){
        if (a[index]==0){   //如果是零，交换
            swap(a, index, p0);
            p0++;
        }
        if (a[index]==2){   //既可以判断当前的index，也可以判断上面交换后的index
            swap(a, index, p2);
            p2--;
            index--;    //先减1，再加1，判断交换后a[index]的值;
        }

    }
}

//找到第k小的
int find_k_min (int *a, int size, int k)
{
    int left = 0;
    int right = size-1;
    int mid;
    while(left <= right){
	    mid = Partition(a, left, right);
		if(mid+1 == k){ //找到
            return a[mid];
        }
        else if(mid+1< k){ //在右边序列找
		    left = mid+1;
	    }
	    else{ //在左边序列找
	        right = mid-1;
	    }
	}
	return a[mid];
}
