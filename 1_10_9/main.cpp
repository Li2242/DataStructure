#include "tool.h"

int main() { 
	srand((unsigned int)time(NULL)); //设置当前时间作为随机数的种子

	MyArray myArray; // 创建MyArray实例 
	// 初始化数组和size 
	for (int i = 0; i < 5; i++) { 
		myArray.arr[i] = rand() % 100 + 1; 
	}
	myArray.size = 5; // 设置数组当前大小 

	//插入
	int insertPos = 2; 
	int newValue = 10; 
	insert(myArray, insertPos, newValue); 
	cout << "insert" << endl;
	print(myArray); 

	//delete
	int deletePos = 3;
	myDelete(myArray,deletePos);
	cout << "delete" << endl;
	print(myArray); 

	//修改
	int modifyPos = 4;
	int modifyValue = 69;
	modify(myArray,modifyPos,modifyValue);
	cout << "modify" << endl;
	print(myArray);

	//查找
	int index = seek_index(myArray,1 );
	int value = seek_value(myArray, 69);

	//排序
	cout << "sort" << endl;
	sort(myArray);
	print(myArray);
	return 0; 
}
