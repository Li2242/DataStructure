#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

// 数字栈结构（存储整数）
typedef struct {
    int top;
    int *v;
    int m;
} NumStack;

// 运算符栈结构（存储字符）
typedef struct {
    int top;
    char *v;
    int m;
} OpStack;

// 数字栈操作函数
bool numEmpty(NumStack s) {
    return s.top == -1;
}

bool numFull(NumStack s) {
    return s.top == s.m - 1;
}

bool numPush(NumStack &s, int value) {
    if (numFull(s)) return false;
    s.v[++s.top] = value;
    return true;
}

bool numPop(NumStack &s, int &val) {
    if (numEmpty(s)) return false;
    val = s.v[s.top--];
    return true;
}

// 运算符栈操作函数
bool opEmpty(OpStack s) {
    return s.top == -1;
}

bool opFull(OpStack s) {
    return s.top == s.m - 1;
}

bool opPush(OpStack &s, char op) {
    if (opFull(s)) return false;
    s.v[++s.top] = op;
    return true;
}

bool opPop(OpStack &s, char &op) {
    if (opEmpty(s)) return false;
    op = s.v[s.top--];
    return true;
}

char opTop(OpStack s) {
    if (opEmpty(s)) return '\0';
    return s.v[s.top];
}

// 获取运算符优先级（*、/ 优先级高于 +、-）
int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    int maxSize = 10000;

    // 初始化数字栈
    NumStack numStack;
    numStack.m = maxSize;
    numStack.top = -1;
    numStack.v = (int*)malloc(maxSize * sizeof(int));
    if (numStack.v == NULL) {
        cerr << "内存分配失败" << endl;
        return 1;
    }

    // 初始化运算符栈
    OpStack opStack;
    opStack.m = maxSize;
    opStack.top = -1;
    opStack.v = (char*)malloc(maxSize * sizeof(char));
    if (opStack.v == NULL) {
        cerr << "内存分配失败" << endl;
        free(numStack.v);
        return 1;
    }

    string input;
    getline(cin, input); // 读取含空格的整行输入
    int n = input.size();
    int i = 0;

    while (i < n) {
        char c = input[i];
        if (c == ' ') { // 跳过空格
            i++;
            continue;
        } else if (c >= '0' && c <= '9') { // 解析多位数
            int num = 0;
            while (i < n && input[i] >= '0' && input[i] <= '9') {
                num = num * 10 + (input[i] - '0');
                i++;
            }
            numPush(numStack, num); // 压入数字栈
        } else { // 处理运算符（+、-、*、/）
            // 若栈顶运算符优先级 >= 当前运算符，先计算栈顶运算符
            while (!opEmpty(opStack)) {
                char topOp = opTop(opStack);
                if (getPriority(topOp) >= getPriority(c)) {
                    char op;
                    opPop(opStack, op);
                    int b, a; // 注意顺序：a是左操作数，b是右操作数
                    numPop(numStack, b);
                    numPop(numStack, a);
                    int res;
                    switch (op) {
                        case '+': res = a + b; break;
                        case '-': res = a - b; break;
                        case '*': res = a * b; break;
                        case '/': res = a / b; break; // 除法截断为零
                    }
                    numPush(numStack, res); // 结果压回数字栈
                } else {
                    break; // 栈顶优先级低，停止计算
                }
            }
            opPush(opStack, c); // 当前运算符入栈
            i++;
        }
    }

    // 处理剩余未计算的运算符
    while (!opEmpty(opStack)) {
        char op;
        opPop(opStack, op);
        int b, a;
        numPop(numStack, b);
        numPop(numStack, a);
        int res;
        switch (op) {
            case '+': res = a + b; break;
            case '-': res = a - b; break;
            case '*': res = a * b; break;
            case '/': res = a / b; break;
        }
        numPush(numStack, res);
    }

    // 输出结果（数字栈顶即为最终结果）
    int result;
    numPop(numStack, result);
    cout << result << endl;

    // 释放内存
    free(numStack.v);
    free(opStack.v);
    return 0;
}