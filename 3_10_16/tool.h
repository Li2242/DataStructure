#include <stdio.h>  
#include <stdlib.h> 

// 定义链表节点结构体  
typedef struct ListNode {  
    int value;  
    struct ListNode* next;  
}ln;

struct ListNode* createNode(int value);
void insertAtHead(struct ListNode** head, int value);
void printList(struct ListNode* head);
void freeList(struct ListNode* head);
void deleteList_value(ln** head, int value);