#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Partition(int *a, int low, int high){
	int pivot = a[low]; //中心
	//low比high小就一直循环
	while(low < high){
		//a_high 比 pivot小就不关心他，high 左移
		while(low < high && a[high] >= pivot) high--;
		//交换
		a[low] = a[high];
		//a_low 比 pivot 大就不关心他，low 右移
		while(low < high && a[low] <= pivot) low++;
		//交换
		a[high] = a[low];
	}
	a[low] = pivot;//或者 a_high = pivot
	return low;
}

void QuickSort(int *a, int low, int high){
	if(low < high){
		int pivotpos = Partition(a, low, high);
		QuickSort(a,low, pivotpos-1);
		QuickSort(a,pivotpos + 1, high);
	}
}


int main(){
	srand((unsigned int)time(NULL));
	int *a = (int *)malloc(sizeof(int)*1001);
	for(int i = 0; i < 1001; i++){
		a[i] = rand() % 1000 + 1;
	}
	int low = 0;
	int high = 1000;
	QuickSort(a, low, high);

	printf("快速排序的结果为： ");
	for (int i = 0; i < 1000; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
