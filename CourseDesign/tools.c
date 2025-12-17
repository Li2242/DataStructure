#include "tools.h"


// 全局变量用于统计
long long compare_count = 0;

// 2. 排序结构体数组
void DoubleBullSortCore(SortResult arr[], int n) {
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < n - i; j++) {
            if (arr[j].time_use > arr[j+1].time_use) {
                // 交换整个结构体（名称和耗时同步）
                SortResult temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if (!flag) break;
    }
}

//打印数组
void printArray(int *a, int n){
	printf("排序的结果为：");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//打印SortResult数组
void PrintSortResults(SortResult arr[], int n) {
    for (int i = 0; i < n; i++) {
        // 左对齐15字符
        printf("%-20s  \t时间:%fs\n", arr[i].name, arr[i].time_use);
    }
}

//1.快排
int Partition(int *a, int low, int high){
	int pivot = a[low]; //中心
	//low比high小就一直循环
	while(low < high){
		//a_high 比 pivot小就不关心他，high 左移
		while(low < high && a[high] >= pivot){
			high--;
			compare_count++;
		} 
		//交换
		a[low] = a[high];
		//a_low 比 pivot 大就不关心他，low 右移
		while(low < high && a[low] <= pivot){
			low++;
			compare_count++;
		}
		//交换
		a[high] = a[low];
	}
	a[low] = pivot;//或者 a_high = pivot
	return low;
}

void QuickSortCore(int *a, int low, int high){
	if(low < high){
		int pivotpos = Partition(a, low, high);
		QuickSortCore(a,low, pivotpos-1);
		QuickSortCore(a,pivotpos + 1, high);
	}
}
// 快排入口（统一结构：拷贝+计时+统计+释放）
double QuickSort(int *arr, int n) {
    int *a = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) a[i] = arr[i];

    printf("\n======== 快速排序 ======== \n");

    compare_count = 0;  // 重置统计

    clock_t start = clock();

	//核心
    QuickSortCore(a, 0, n - 1);

    clock_t end = clock();
    double cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("排序时间：%f 秒\n", cpu_time_used);
    printf("比较次数：%lld\n", compare_count);
    // printArray(a, n);

    free(a);  
	return cpu_time_used;
}



//2.冒泡核心
void BullSortCore(int *a, int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j+1]){
				compare_count++;
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}


//冒泡入口
double BullSort(int *arr, int n){
	//拷贝一份
	int *a = malloc(sizeof(int)*(n+1));
	for(int i = 0; i < n; i++){
		a[i] = arr[i];
	}

	printf("========  冒泡排序 ======== \n");
	compare_count = 0;

	clock_t start, end;
	double cpu_time_used;
	start = clock();
	//核心
	BullSortCore(a, n);

	end = clock();
	cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
	printf("排序时间为:%f秒\n排序次数为%lld\n",cpu_time_used,compare_count);
	// printArray(a, n);
	free(a);
	return cpu_time_used;
}



//3.选择
void SelectionSortCore(int *a , int n){

	for(int i = 0; i < n - 1; i++){
		int index = i;
		for(int j = i + 1; j < n; j++){
			compare_count++;
			if(a[index] > a[j]){
				index = j;
			}
		}
		int temp = a[i];
		a[i] = a[index];
		a[index] = temp;
	}
}
double SelectionSort(int *arr , int n){
	//拷贝一份
	int *a = malloc(sizeof(int)*(n+1));
	for(int i = 0; i < n; i++){
		a[i] = arr[i];
	}

	printf("========  选择排序 ======== \n");
	compare_count = 0;

	clock_t start, end;
	double cpu_time_used;

	start = clock();
	//核心
	SelectionSortCore(a, n);

	end = clock();
	cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
	printf("排序时间为:%f秒\n排序次数为%lld\n",cpu_time_used,compare_count);
	// printArray(a, n);
	free(a);
	return cpu_time_used;
}


//4.插入排序
void InsertSorCore(int *a, int n){


	int key, j;
	for(int i = 1; i < n; i++){
		key = a[i]; //拿到接下来要插入的值
		j = i - 1;  //左移准备找插入位置
		//往右移动，j最后停留的位置比key小，要把key插入到这个数后面
		while(j >= 0 && a[j] > key){
			compare_count++;
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}

}

double InsertSort(int *arr, int n){

	//拷贝一份
	int *a = malloc(sizeof(int)*(n+1));
	for(int i = 0; i < n; i++){
		a[i] = arr[i];
	}
	printf("========  插入排序 ======== \n");
	compare_count = 0;

	clock_t start, end;
	double cpu_time_used;

	start = clock();



	InsertSorCore(a, n);

	end = clock();
	cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
	printf("排序时间为:%f秒\n排序次数为%lld\n",cpu_time_used,compare_count);
	// printArray(a, n);
	free(a);
	return cpu_time_used;
}

//5.折半插入排序
void binaryInsertSortCore(int *a, int n){
	int key, low, mid, high;
	for(int i = 1; i < n ; i++){
		key = a[i];
		high = i - 1;
		low = 0;
		//找到位置
		while(low <= high){
			//计数
			compare_count++;

			mid = (high + low)/2;
			if(a[mid] > key){
				high = mid - 1;
			}else{
				low = mid + 1;
			}
		}
		//移动
		for(int j = i - 1; j >= low ;j--){
			a[j + 1] = a[j];
		}
		//插入
		a[low] = key;
	}
}

//5.折半插入排序
double binaryInsertSort(int *arr, int n){
	//拷贝一份
	int *a = malloc(sizeof(int)*(n+1));
	for(int i = 0; i < n; i++){
		a[i] = arr[i];
	}
	printf("========  折半插入排序 ======== \n");
	compare_count = 0;

	clock_t start, end;
	double cpu_time_used;

	start = clock();

	binaryInsertSortCore(a, n);

	end = clock();
	cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
	printf("排序时间为:%f秒\n排序次数为%lld\n",cpu_time_used,compare_count);
	// printArray(a, n);
	free(a);
	return cpu_time_used;
}
//7.希尔排序
void ShellSortCore(int *a, int n){
	for(int gap = n / 2; gap > 0; gap /= 2){
		//第一个数默认有序，所以从gap开始
		for(int i = gap; i < n ; i++){
			int key = a[i];
			int j;
			//找到插入位置
			for(j = i; j >= gap && a[j - gap] > key; j -= gap){
				compare_count++;
				a[j] = a[j - gap];
			}
			a[j] = key;
		}
	}
}
//7.希尔排序
double ShellSort(int *arr, int n){
	//拷贝一份
	int *a = malloc(sizeof(int)*(n+1));
	for(int i = 0; i < n; i++){
		a[i] = arr[i];
	}
	printf("========  希尔排序 ======== \n");
	compare_count = 0;

	clock_t start, end;
	double cpu_time_used;

	start = clock();

	ShellSortCore(a, n);

	end = clock();
	cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
	printf("排序时间为:%f秒\n排序次数为%lld\n",cpu_time_used,compare_count);
	// printArray(a, n);
	free(a);
	return cpu_time_used;
}


//6.归并排序
void Merge(int *a, int left, int mid, int right){

	int n = right - left + 1;

	int *temp = (int *)malloc(sizeof(int)*n);

	if(temp == NULL){
		printf("MergeSort 分配内存失败！\n");
		return;
	}

	int l_p = left; //左半区未排序的
	int r_p = mid + 1; //右半区未排序的
	int t_p = 0;

	while(l_p <= mid && r_p <= right){
		compare_count++;
		if(a[l_p] <= a[r_p]){
			temp[t_p++] = a[l_p++];
		}else{
			temp[t_p++] = a[r_p++];
		}
	}
	//左边没放完的
	while(l_p <= mid){
		temp[t_p++] = a[l_p++];
	}
	//右边没放完的
	while(r_p <= right){
		temp[t_p++] = a[r_p++];
	}
	// 将 temp中的有序数据复制回a的原来位置
    for (t_p = 0; t_p < n; t_p++) {
        a[left + t_p] = temp[t_p];
    }
    
    // 释放内存
    free(temp);
}

void MergeSortCore(int *a, int left, int right){
	if(left >= right){
		return;
	}

	int mid = (left + right) / 2;//拆分

	MergeSortCore(a, left , mid); //拆左侧

	MergeSortCore(a,mid + 1 , right); // 拆右侧

	Merge(a, left, mid, right);
}

// 归并排序
double MergeSort(int *arr, int n) {
    
    int *a = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        a[i] = arr[i]; 
    }

    printf("======== 归并排序 ======== \n");
    compare_count = 0;  
    clock_t start, end;
    double cpu_time_used;


    start = clock();
	//关键
    MergeSortCore(a, 0, n - 1);
    end = clock();

    cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("排序时间为:%f秒\n", cpu_time_used);
    printf("比较次数为%lld\n", compare_count);  
    // printArray(a, n);  

    // 5. 释放内存（修复内存泄漏）
    free(a);
	return cpu_time_used;
}

// 堆调整：将以parent为根的子树调整为大顶堆
void HeapAdjust(int *a, int parent, int n) {
    int temp = a[parent];  // 保存父节点值
    int child = 2 * parent + 1;  // 左孩子索引

    while (child < n) {
        // 比较左右孩子，选择较大值的孩子
        if (child + 1 < n && a[child] < a[child + 1]) {
            child++;
            compare_count++;  // 统计比较次数
        }

        // 父节点大于等于孩子节点，调整结束
        if (temp >= a[child]) {
            compare_count++;  // 统计比较次数
            break;
        }

        // 孩子节点值上移至父节点
        a[parent] = a[child];
        // 更新父节点和孩子节点索引，继续向下调整
        parent = child;
        child = 2 * parent + 1;
    }

    // 将原父节点值放入最终位置
    a[parent] = temp;
}

// 堆排序核心函数
void HeapSortCore(int *a, int n) {
    // 1. 构建大顶堆：从最后一个非叶子节点开始调整
    for (int i = n / 2 - 1; i >= 0; i--) {
        HeapAdjust(a, i, n);
    }

    //堆排序：逐步提取堆顶元素
    for (int i = n - 1; i > 0; i--) {
        // 交换堆顶（最大值）和数组末尾元素
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // 调整剩余元素为大顶堆
        HeapAdjust(a, 0, i);
    }
}

// 堆排序入口函数
double HeapSort(int *arr, int n) {
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        a[i] = arr[i];
    }

    printf("======== 堆排序 ======== \n");
    compare_count = 0;  

    clock_t start = clock();  
	//核心
    HeapSortCore(a, n);       
    clock_t end = clock();

  
    double cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("排序时间为:%f秒\n比较次数为%lld\n", cpu_time_used, compare_count);

    free(a);  
    return cpu_time_used;
}
// 计数排序
void CountingSortCore(int *a, int n) {
	//找到数组范围
    int min = a[0], max = a[0];
    for (int i = 1; i < n; i++) {
		compare_count++;
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }
	//分配数组
	int range = max - min + 1;
    int* count = (int*)calloc(range, sizeof(int));

	//计数
    for (int i = 0; i < n; i++) {
		compare_count++;
		//找到对应的位置进行计数
        count[a[i] - min]++; 
    }

	//返回到原来的数组种
    int idx = 0;
    for (int i = 0; i < range; i++) {
        while (count[i]-- > 0) {
			compare_count++;
            a[idx++] = i + min;
        }
    }
    free(count);
}

// 计数排序
double CountingSort(int *arr, int n) {
    int *a = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        a[i] = arr[i]; 
    }

    printf("======== 计数排序 ======== \n");
    compare_count = 0;  
    clock_t start, end;
    double cpu_time_used;


    start = clock();
	//关键
    CountingSortCore(a, n);
    end = clock();

    cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("排序时间为:%f秒\n", cpu_time_used);
    printf("比较次数为%lld\n", compare_count);  
    // printArray(a, n);  

    // 5. 释放内存（修复内存泄漏）
    free(a);
	return cpu_time_used;
}


//基数排序

//获得位数
int getDigit(int num, int digit) {
    for (int i = 0; i < digit; i++) {
        num /= 10;
    }
    return num % 10;
}

//找数组中数字的最大位数
int getMaxDigits(int a[], int n) {
    if (n <= 1) return 1;
    int max_num = a[0];
    // 找最大数
    for (int i = 1; i < n; i++) {
        if (a[i] > max_num) {
            max_num = a[i];
        }
    }
    // 计算最大数的位数
    int digits = 0;
    while (max_num > 0) {
        max_num /= 10;
        digits++;
    }
    return digits;
}
// 简化版基数排序（
void RadixSortCore(int a[], int n) {
    if (n <= 1) return;

    int max_digits = getMaxDigits(a, n); // 最大位数

    int* temp = (int*)malloc(n * sizeof(int)); // 临时数组

    // 按位排序,从个位到最高位
    for (int digit = 0; digit < max_digits; digit++) {
        int count[10] = {0}; // 每一位只有 0~9，固定大小10

        //统计当前位上 0~9 的出现次数
        for (int i = 0; i < n; i++) {
			compare_count++;
            int d = getDigit(a[i], digit);
            count[d]++;
        }

        //计算前缀和
        for (int i = 1; i < 10; i++) {
			compare_count++;
            count[i] += count[i - 1];
        }

        // 倒序回填到临时数组
        for (int i = n - 1; i >= 0; i--) {
			compare_count++;
            int d = getDigit(a[i], digit);
            temp[--count[d]] = a[i];
        }

        // 临时数组结果拷贝回原数组
        for (int i = 0; i < n; i++) {
			compare_count++;
            a[i] = temp[i];
        }
    }

    free(temp); 
}

// 基数排序
double RadixSort(int *arr, int n) {
    
    int *a = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        a[i] = arr[i]; 
    }

    printf("======== 基数排序 ======== \n");
    compare_count = 0;  
    clock_t start, end;
    double cpu_time_used;


    start = clock();
	//关键
    RadixSortCore(a, n);
    end = clock();

    cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("排序时间为:%f秒\n", cpu_time_used);
    printf("比较次数为%lld\n", compare_count);  
    // printArray(a, n);  

    // 5. 释放内存（修复内存泄漏）
    free(a);
	return cpu_time_used;
}