#include <iostream> 
using namespace std; 
#include <stdlib.h>
#include <time.h>

// 定义结构体 
struct MyArray { 
	int arr[100]; // 数组，假设最大长度为100 
	int size; // 数组当前元素数量 
};

void insert(MyArray& myArray, int position, int value);
void myDelete(MyArray& myArray, int position);
void modify(MyArray& myArray, int position, int value);
int seek_index(const MyArray& myArray, int position);
int seek_value(const MyArray& myArray, int value);
void sort(MyArray& myArray);

void print(const MyArray& myArray);