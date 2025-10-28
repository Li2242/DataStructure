#include "tool.h"

int main() {  
    int values[] = {5, 4, 3, 2, 1}; // 初始值数组  
    int size = sizeof(values) / sizeof(values[0]); // 数组大小  
  
    // 初始化链表（现在直接初始化为NULL）  
    ln* head = NULL;  
  
    // 逐个插入元素到链表头部  
    for (int i = 0; i < size; i++) {  
        insertAtHead(&head, values[i]);  
    }  
		for(int i =0 ;i<=5;i++){
			deleteList_value(&head, i);
			// 打印链表  
    	printList(head); // 输出应该是：1 2 3 4 5  
		}

    // 释放链表占用的内存  
    freeList(head);  
  
    return 0;  
}
