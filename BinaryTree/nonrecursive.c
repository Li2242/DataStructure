#include <stdio.h>
#include <stdlib.h>

// 二叉树节点定义
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

// 栈节点定义
typedef struct StackNode {
    BiTree ptr;          // 指向二叉树节点的指针
    int flag;            // 后序遍历标记：0-未处理，1-已处理左子树（可选）
} StackNode;

// 栈的结构
#define MAX_STACK_SIZE 1000
typedef struct {
    StackNode data[MAX_STACK_SIZE];
    int top;             // 栈顶指针，-1为空
} Stack;

// 栈操作函数
// 初始化栈
void InitStack(Stack *S){ 
	S->top = -1; 
}

int IsEmpty(Stack *S){ 
	return S->top == -1;
}

int  IsFull(Stack *S){
	return S->top == MAX_STACK_SIZE - 1;
}

// 压栈（返回0失败，1成功）
int Push(Stack *S, BiTree p, int flag) {
    if (IsFull(S)) return 0;
    S->data[++S->top].ptr = p;
    S->data[S->top].flag = flag;
    return 1;
}

// 弹栈（返回0失败，1成功，数据通过参数返回）
int Pop(Stack *S, BiTree *p, int *flag) {
    if (IsEmpty(S)) return 0;
    *p = S->data[S->top].ptr;
    *flag = S->data[S->top].flag;
    S->top--;
    return 1;
}

// 函数声明
void CreateBiTree(BiTree *T);            // 创建二叉树
void PreOrderTraverse_NonRec(BiTree T);  // 非递归先序遍历
void InOrderTraverse_NonRec(BiTree T);   // 非递归中序遍历
void PostOrderTraverse_NonRec(BiTree T); // 非递归后序遍历
void PrintMenu();                        // 打印菜单

int main() {
    BiTree T = NULL;
    int choice;

    printf("=== 链式二叉树非递归遍历系统 ===\n");
    printf("请输入先序扩展序列构建二叉树(# 表示空节点，例如 AB#C##D##):\n");
    CreateBiTree(&T);

    do {
        PrintMenu();
        // 处理输入合法性
        while (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // 清空缓冲区
            printf("输入错误，请输入数字！请重新选择 (1-4): ");
        }

        switch (choice) {
            case 1:
                printf("非递归先序遍历结果: ");
                PreOrderTraverse_NonRec(T);
                printf("\n");
                break;
            case 2:
                printf("非递归中序遍历结果: ");
                InOrderTraverse_NonRec(T);
                printf("\n");
                break;
            case 3:
                printf("非递归后序遍历结果: ");
                PostOrderTraverse_NonRec(T);
                printf("\n");
                break;
            case 4:
                printf("程序已退出。\n");
                break;
            default:
                printf("无效输入，请输入 1~4 之间的数字！\n");
        }
    } while (choice != 4);

    return 0;
}

// 创建二叉树（递归，逻辑不变）
void CreateBiTree(BiTree *T) {
    char ch;
    scanf(" %c", &ch); // 跳过空白符读取字符

    if (ch == '#') {
        *T = NULL;
    } else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (*T == NULL) {
            printf("内存分配失败！\n");
            exit(1);
        }
        (*T)->data = ch;
        CreateBiTree(&((*T)->lchild));
        CreateBiTree(&((*T)->rchild));
    }
}

// 非递归先序遍历：根 → 左 → 右
void PreOrderTraverse_NonRec(BiTree T) {
    if (T == NULL) return;

    Stack S;
    InitStack(&S);
    Push(&S, T, 0); // 根节点入栈

    while (!IsEmpty(&S)){
        BiTree p;
        int flag;
        Pop(&S, &p, &flag); // 弹出栈顶节点

        if (p != NULL) {
            printf("%c ", p->data); // 访问当前节点
            Push(&S, p->rchild, 0); // 先压右子节点（后进先出）
            Push(&S, p->lchild, 0); // 再压左子节点
        }
    }
}

// 非递归中序遍历：左 → 根 → 右
void InOrderTraverse_NonRec(BiTree T) {
    Stack S;
    InitStack(&S);
    BiTree p = T;

    // 循环条件：节点非空 或 栈非空
    while (p != NULL || !IsEmpty(&S)) {
        // 1. 先将所有左子节点压栈
        if (p != NULL) {
            Push(&S, p, 0);
            p = p->lchild;
        } else {
            // 2. 弹出节点，访问，再处理右子节点
            Pop(&S, &p, &(int){0}); // 忽略flag
            printf("%c ", p->data);
            p = p->rchild;
        }
    }
}

// 非递归后序遍历：左 → 右 → 根（用flag标记是否处理过右子树）
void PostOrderTraverse_NonRec(BiTree T) {
    if (T == NULL) return;

    Stack S;
    InitStack(&S);
    BiTree p = T;
    int flag;

    while (p != NULL || !IsEmpty(&S)) {
        // 1. 压入所有左子节点（flag=0：未处理）
        while (p != NULL) {
            Push(&S, p, 0);
            p = p->lchild;
        }

        // 2. 弹出节点检查
        Pop(&S, &p, &flag);
        if (flag == 0) {
            // 首次弹出：标记为已处理左子树，重新入栈，处理右子树
            Push(&S, p, 1);
            p = p->rchild;
        } else {
            // 二次弹出：右子树已处理，访问当前节点
            printf("%c ", p->data);
            p = NULL; // 避免重复压栈
        }
    }
}

// 打印菜单
void PrintMenu() {
    printf("\n--- 选择遍历方式 ---\n");
    printf("1. 非递归先序遍历\n");
    printf("2. 非递归中序遍历\n");
    printf("3. 非递归后序遍历\n");
    printf("4. 退出\n");
    printf("请输入选择 (1-4): ");
}