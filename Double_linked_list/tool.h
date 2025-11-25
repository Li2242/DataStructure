#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h> 

// 定义链表节点结构体  
typedef struct ListNode {  
    int value;  
    struct ListNode* next;  
		struct ListNode* prior;
}ln;

struct ListNode* createNode(int value);
void insertHead(struct ListNode** head, int value);
void printList(struct ListNode* head);
void freeList(struct ListNode* head);
void deleteList_value(ln** head, int value);
void insert(ln** head, int position);
void check(ln* head, int value);
struct ListNode* initList();