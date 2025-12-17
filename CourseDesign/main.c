#include "tools.h"
#define NUMBER 100000


int main(){
	//随机数生成
	srand((unsigned int)time(NULL));
	int *a = (int *)malloc(sizeof(int)*(NUMBER + 1));
	for(int i = 0; i < NUMBER + 1; i++){
		a[i] = rand() % (NUMBER * 2) + 1;
	}
	//定义数组
    SortResult sortResults[10] = {
        {"快速排序", 0.0},
        {"希尔排序", 0.0},
        {"归并排序", 0.0},
        {"折半插入排序", 0.0},
        {"直接插入排序", 0.0},
        {"选择排序", 0.0},
        {"冒泡排序", 0.0},
        {"堆排序", 0.0},
        {"计数排序", 0.0},
        {"基数排序", 0.0}
    };

	// 执行每种排序,记录耗时
    sortResults[0].time_use = QuickSort(a, NUMBER);
    sortResults[1].time_use = ShellSort(a, NUMBER);
    sortResults[2].time_use = MergeSort(a, NUMBER);
    sortResults[3].time_use = binaryInsertSort(a, NUMBER);
    sortResults[4].time_use = InsertSort(a, NUMBER);
    sortResults[5].time_use = SelectionSort(a, NUMBER);
    sortResults[6].time_use = BullSort(a, NUMBER);
    sortResults[7].time_use = HeapSort(a, NUMBER);
    sortResults[8].time_use = CountingSort(a, NUMBER);
    sortResults[9].time_use = RadixSort(a, NUMBER);

    // 对运行时间进行排序
    DoubleBullSortCore(sortResults, 9);

	printf("\n========== 排名 ==========\n");

	printf("测试的随机数有: %d个\n",NUMBER);

    //输出时间排名
    PrintSortResults(sortResults, 10);

	free(a);

	return 0;
}