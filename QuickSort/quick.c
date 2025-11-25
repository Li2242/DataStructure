#include <stdio.h>

int Partition(int *a, int low, int high){
	int pivot = a[low]; //中心
	while(low < high){
		while(low < high && a[high] >= pivot) high--;
		a[low] = a[high];
		while(low < high && a[low] <= pivot) low++;
		a[high] = a[low];
	}
	a[low] = pivot;
	return low;
}



int main(){


	return 0;
}
