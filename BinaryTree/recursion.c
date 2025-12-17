#include <stdio.h>
#include <stdlib.h>

// 二叉树节点定义
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

// 函数声明
void CreateBiTree(BiTree *T);        // 创建二叉树
void PreOrderTraverse(BiTree T);     // 先序遍历
void InOrderTraverse(BiTree T);      // 中序遍历
void PostOrderTraverse(BiTree T);    // 后序遍历
void PrintMenu();                    // 打印菜单

int main() {
    BiTree T = NULL;  // C语言用NULL表示空指针
    int choice;

    printf("=== 链式二叉树遍历系统 ===\n");
    printf("请输入先序扩展序列构建二叉树(# 表示空节点，例如 AB#C##D##):\n");
    CreateBiTree(&T);

    do {
        PrintMenu();
        // 读取整数（处理输入缓冲区残留的换行符）
        while (scanf("%d", &choice) != 1) {
            // 清空输入缓冲区
            while (getchar() != '\n');
            printf("输入错误，请输入数字！请重新选择 (1-4): ");
        }

        switch (choice) {
            case 1:
                printf("先序遍历结果: ");
                PreOrderTraverse(T);
                printf("\n");
                break;
            case 2:
                printf("中序遍历结果: ");
                InOrderTraverse(T);
                printf("\n");
                break;
            case 3:
                printf("后序遍历结果: ");
                PostOrderTraverse(T);
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

// 创建二叉树（先序扩展输入）
// 二级指针，要修改主函数中T的指向
void CreateBiTree(BiTree *T) {
    char ch;
    // 读取一个字符
    scanf(" %c", &ch);  // 空格用于跳过输入缓冲区的空白字符

    if (ch == '#') {
        *T = NULL;  //空节点
    } else {
        // 动态分配节点内存
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (*T == NULL) {  // 内存分配失败检查
            printf("内存分配失败！\n");
            exit(1);
        }
        (*T)->data = ch;
        CreateBiTree(&((*T)->lchild));  // 递归创建左子树
        CreateBiTree(&((*T)->rchild));  // 递归创建右子树
    }
}

// 先序遍历：根左右
void PreOrderTraverse(BiTree T) {
    if (T != NULL) {
        printf("%c ", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

// 中序遍历：左根右
void InOrderTraverse(BiTree T) {
    if (T != NULL) {
        InOrderTraverse(T->lchild);
        printf("%c ", T->data);
        InOrderTraverse(T->rchild);
    }
}

// 后序遍历：左右根
void PostOrderTraverse(BiTree T) {
    if (T != NULL) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c ", T->data);
    }
}

// 打印菜单
void PrintMenu() {
    printf("\n--- 选择遍历方式 ---\n");
    printf("1. 先序遍历\n");
    printf("2. 中序遍历\n");
    printf("3. 后序遍历\n");
    printf("4. 退出\n");
    printf("请输入选择 (1-4): ");
}