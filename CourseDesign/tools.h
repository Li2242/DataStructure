#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    char name[20];    // 名称
    double time_use;  // 耗时
} SortResult;

double QuickSort(int *a, int n);
double BullSort(int *a, int n);
double SelectionSort(int *a , int n);
void printArray(int *a, int n);

void PrintSortResults(SortResult arr[], int n);

double InsertSort(int *a, int n);
//归并排序
double MergeSort(int *a, int n);
//
double binaryInsertSort(int *a, int n);
//希尔
double ShellSort(int *a, int n );
//堆
double HeapSort(int *arr, int n);
//
double CountingSort(int *a, int n) ;
//
double RadixSort(int *arr, int n);

void DoubleBullSortCore(SortResult arr[], int n);