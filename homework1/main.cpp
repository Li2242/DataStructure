#include "tool.h"

int main(){
		DblStack s;
    int maxSize = 5;
    init(s, maxSize);
    s.V = (int*)malloc(maxSize * sizeof(int)); // 为栈数组分配内存

    printf("测试栈0和栈1的初始化、进栈、出栈、判空、判满操作：\n\n");

    // 测试栈0的进栈和出栈
    printf("===== 测试栈0 =====\n");
    printf("栈0是否为空：%s\n", empty0(s) ? "是" : "否");
    push0(s, 10);
    push0(s, 20);
    push0(s, 30);
    printf("栈0进栈10、20、30后，是否已满：%s\n", full(s) ? "是" : "否");
    int popVal0;
    pop0(s, popVal0);
    printf("栈0出栈元素：%d\n", popVal0);
    pop0(s, popVal0);
    printf("栈0出栈元素：%d\n", popVal0);
    printf("栈0是否为空：%s\n", empty0(s) ? "是" : "否");

    // 测试栈1的进栈和出栈
    printf("\n===== 测试栈1 =====\n");
    printf("栈1是否为空：%s\n", empty1(s) ? "是" : "否");
    push1(s, 100);
    push1(s, 200);
    push1(s, 300);
    printf("栈1进栈100、200、300后，是否已满：%s\n", full(s) ? "是" : "否");
    int popVal1;
    pop1(s, popVal1);
    printf("栈1出栈元素：%d\n", popVal1);
    pop1(s, popVal1);
    printf("栈1出栈元素：%d\n", popVal1);
    printf("栈1是否为空：%s\n", empty1(s) ? "是" : "否");

    free(s.V); // 释放内存


	return 0;
}