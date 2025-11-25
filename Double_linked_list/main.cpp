#include "tool.h"

int main() {
    // 1. 初始化空链表
    ln* head = initList();
    printf("=== 初始化后 ===\n");
    printList(head); // 预期：链表为空

    // 2. 头插多个节点（头插后链表顺序：3 → 2 → 1）
    printf("\n=== 开始头插节点 ===\n");
    insertHead(&head, 1); // 插1 → 链表：1
    insertHead(&head, 2); // 插2 → 链表：2 ←→ 1
    insertHead(&head, 3); // 插3 → 链表：3 ←→ 2 ←→ 1
    printList(head); // 预期：3 2 1

    // 3. 查找节点（存在+不存在）
    printf("\n=== 开始查找节点 ===\n");
    check(head, 2);    // 预期：找到第一个值为2的节点，索引1
    check(head, 4);    // 预期：未找到值为4的节点
    check(NULL, 1);    // 预期：链表为空，无法查找

    // 4. 删除节点（头节点+中间节点+尾节点+不存在值）
    printf("\n=== 开始删除节点 ===\n");
    deleteList_value(&head, 3); // 删除头节点3 → 链表：2 ←→ 1
    printList(head);            // 预期：2 1

    deleteList_value(&head, 2); // 删除中间节点2 → 链表：1
    printList(head);            // 预期：1

    deleteList_value(&head, 1); // 删除尾节点1 → 链表为空
    printList(head);            // 预期：链表为空

    deleteList_value(&head, 5); // 预期：未找到值为5的节点

    // 5. 释放链表内存
    printf("\n=== 释放链表 ===\n");
    freeList(head);
    head = NULL; // 避免野指针

    return 0;
}