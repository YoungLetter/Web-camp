#include <stdio.h>
#include <stdlib.h>
#include "qgsort/qgsort.h"
#include <time.h>

void createnumber (int *a, int length)
{
    //用来生成随机数
    srand((int)time(0));
	for (int i =0; i<length; i++) {
		a[i] = rand() % length + 1;
	}
}
int main()
{

    int a[10001];
    printf("|*****  10000个测试数据下各种排序所用时间   *****|\n");

    int start_time = clock();
    createnumber(a, 10000);
    int end_time = clock();
    printf("|**\t 获取10000个数据        用时:  %-3d ms       **|\n", end_time-start_time);

    start_time = clock();
    insertSort(a, 10000);
    end_time = clock();
    printf("|**      InsertSort             用时:  %-3d ms       **|\n", end_time-start_time);

    createnumber(a, 10000);
    start_time = clock();
    int *temp;
    MergeSort(a, 0, 9999, temp);
    end_time = clock();
    printf("|**      MergeSort              用时:  %-3d ms       **|\n", end_time-start_time);

    createnumber(a, 10000);
    start_time = clock();
    QuickSort_Recursion(a, 0 ,9999);
    end_time = clock();
    printf("|**      QuickSort_Recursion    用时:  %-3d ms       **|\n", end_time-start_time);

    createnumber(a, 10000);
    start_time = clock();
    CountSort(a, 10000);
    end_time = clock();
    printf("|**      CountSort              用时:  %-3d ms       **|\n", end_time-start_time);

    createnumber(a, 10000);
    start_time = clock();
    RadixCountSort(a, 10000);
    end_time = clock();
    printf("|**      RadixCountSort         用时:  %-3d ms       **|\n", end_time-start_time);

    createnumber(a, 10000);
    start_time = clock();
    QuickSort(a, 10000);
    end_time = clock();
    printf("|**      QuickSort              用时:  %-3d ms       **|\n", end_time-start_time);

    int b[50001];
    printf("|*****  50000个测试数据下各种排序所用时间   *****|\n");

    start_time = clock();
    createnumber(b, 50000);
    end_time = clock();
    printf("|**\t 获取50000个数据        用时:  %-3d ms       **|\n", end_time-start_time);

    start_time = clock();
    insertSort(b, 50000);
    end_time = clock();
    printf("|**      InsertSort             用时:  %-3d ms       **|\n", end_time-start_time);

    createnumber(b, 50000);
    start_time = clock();
    MergeSort(b, 0, 49999, temp);
    end_time = clock();
    printf("|**      MergeSort              用时:  %-3d ms       **|\n", end_time-start_time);

    createnumber(b, 50000);
    start_time = clock();
    QuickSort_Recursion(b, 0 ,49999);
    end_time = clock();
    printf("|**      QuickSort_Recursion    用时:  %-3d ms       **|\n", end_time-start_time);

    createnumber(b, 50000);
    start_time = clock();
    CountSort(b, 50000);
    end_time = clock();
    printf("|**      CountSort              用时:  %-3d ms       **|\n", end_time-start_time);

    createnumber(b, 50000);
    start_time = clock();
    RadixCountSort(b, 50000);
    end_time = clock();
    printf("|**      RadixCountSort         用时:  %-3d ms       **|\n", end_time-start_time);

//    createnumber(b, 50000);
//    start_time = clock();
//    QuickSort(b, 50000);
//    end_time = clock();
//    printf("|**      QuickSort              用时:  %-3d ms       **|\n", end_time-start_time);
    system("pause");
    return 0;
}
