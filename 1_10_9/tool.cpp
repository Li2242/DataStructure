#include "tool.h"


// 插入函数，作为结构体外部的成员函数 
void insert(MyArray& myArray, int position, int value) {
	if (position < 0 || position > myArray.size || myArray.size >= 100) { 
		// 处理错误情况，例如位置无效或数组已满 
		cout << "无效位置或者数组已满" << endl; 
		return; 
	} 
	// 将从插入位置开始的元素向后移动一位 
	for (int i = myArray.size; i > position; i--) { 
		myArray.arr[i] = myArray.arr[i - 1]; 
	} 
	// 在指定位置插入新值 
	myArray.arr[position] = value; 
	// 更新数组大小 
	myArray.size++; 
} 

//删除
void myDelete(MyArray& myArray, int position){
	if(position < 0 || position > myArray.size || myArray.size >= 100 ){
		cout << "无效位置" << endl;
		return;
	}
	for(int i = position; i < myArray.size - 1; i++){
		myArray.arr[i] = myArray.arr[i+1];
	}
	myArray.size--;
}

//修改
void modify(MyArray& myArray, int position, int value){
	if(position < 0 || position >= myArray.size || position >= 100){
		cout << "无效位置" << endl;
		return;
	}
	myArray.arr[position] = value;
}

//seek
int seek_index(const MyArray& myArray, int position){
	if(position < 0 || position >= myArray.size || position >= 100){
		cout << "无效位置" << endl;
		return -1;
	}
	cout << "根据索引找数值" << myArray.arr[position] << endl;
	
	return myArray.arr[position];
}
int seek_value(const MyArray& myArray, int value){
	int index = -1;
	for(int i = 0; i < myArray.size; i++){
		if(myArray.arr[i] == value){
			index = i;
			break;
		}
	}
	if(index == -1){
		cout << "未找到"<< value <<"对应的Index" << endl;
	}
	cout << "根据数值找索引" << index << endl;
	return index; 
}

//Sort
void sort(MyArray& myArray){
	for(int i = 0;i < myArray.size; i++ ){
		for(int j = 0; j < myArray.size - i; j++){
			if(myArray.arr[j] > myArray.arr[j+1]){
				int temp = myArray.arr[j + 1];
				myArray.arr[j + 1] = myArray.arr[j];
				myArray.arr[j] = temp;
			}
		}
	}
	cout << "排序已完成" << endl;
	return;
}



// 打印函数，作为结构体外部的成员函数 
void print(const MyArray& myArray) { 
	for (int i = 0; i < myArray.size; i++) { 
		cout << myArray.arr[i] << " "; 
	} 
	cout << endl; 
} 