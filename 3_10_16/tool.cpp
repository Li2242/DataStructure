#include "tool.h"

// 创建一个新节点的函数  
struct ListNode* createNode(int value) {  
    ln* newNode = (ln*)malloc(sizeof(ln));
    if (newNode == NULL){
        // 处理内存分配失败的情况  
        printf("Memory allocation failed\n");  
        exit(1);  
    }  
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
  
// 在链表头部插入新节点的函数  
void insertAtHead(ln** head, int value) {
    ln* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// 打印链表  
void printList(struct ListNode* head) {  
    ln* current = head;  
    while (current != NULL) {  
        printf("%d ", current->value);  
        current = current->next;  
    }  
    printf("\n");  
}
  
// 释放链表占用的内存  
void freeList(struct ListNode* head) {  
    ln* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);  
    }
}

// 删除节点 
void deleteList_value(ln** head, int value){  

	ln** pp = head; // pp指向"当前节点的指针"（初始为头指针的地址）
	while(*pp != NULL ){
		if((*pp)->value == value){
			ln *temp = *pp;
			*pp = temp->next; //修改next里面的内容
			free(temp);
			printf("删除成功！");
			return;
		}
		pp = &((*pp)->next);// 移动temp，指向"下一个节点的指针"（即当前节点next的地址）
	}
	printf("删除失败!");
	return;

	// // 处理空链表
	// if (head == NULL || *head == NULL) {
	// 	printf("链表为空，无法删除！\n");
	// 	return;
	// }
	// ln* temp = NULL;
	// //头节点就是目标节点
	// if ((*head)->value == value) {
	// 		temp = *head;          
	// 		*head = (*head)->next; 
	// 		free(temp);
	// 		return;
	// }

	// ln* current = *head;
	// while( current->next != NULL){
	// 	if((current->next)->value == value){
	// 	  temp = current->next;
	// 		current->next = temp->next;
	// 		free(temp);
	// 		return ;
	// 	}else{
	// 		current = current->next;
	// 	}
	// }
	// // 遍历完未找到目标值
  // printf("ERROR! 未找到值为%d的节点\n", value);
	// return;
}  


// 初始化链表的函数，只创建一个空节点（但这里其实不需要空节点，因为头节点可以直接是数据节点）  
struct ListNode* initList() {  
    // 原本这里创建了一个空节点，但根据后续操作，我们可以直接不创建空节点  
    // 这里返回NULL作为初始的空链表头  
    return NULL;  
}  
