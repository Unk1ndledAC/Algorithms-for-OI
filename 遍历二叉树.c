#include <stdio.h>

// 定义二叉树节点个数的最大值
#define MAX_NODES 100

// 创建二叉树
void createTree(int tree[], int data, int pos) {
    if (tree[pos] == 0) {
        tree[pos] = data;
        printf("Node %d inserted at position %d\n", data, pos);
    } else {
        printf("Position %d is occupied\n", pos);
    }
}

// 先序遍历
void preOrderTraversal(int tree[], int pos) {
    if (tree[pos] != 0) {
        printf("%d ", tree[pos]);
        preOrderTraversal(tree, 2 * pos + 1);
        preOrderTraversal(tree, 2 * pos + 2);
    }
}

// 中序遍历
void inOrderTraversal(int tree[], int pos) {
    if (tree[pos] != 0) {
        inOrderTraversal(tree, 2 * pos + 1);
        printf("%d ", tree[pos]);
        inOrderTraversal(tree, 2 * pos + 2);
    }
}

// 后序遍历
void postOrderTraversal(int tree[], int pos) {
    if (tree[pos] != 0) {
        postOrderTraversal(tree, 2 * pos + 1);
        postOrderTraversal(tree, 2 * pos + 2);
        printf("%d ", tree[pos]);
    }
}

int main() {
    int tree[MAX_NODES] = {0};

    // 创建节点并插入二叉树
    createTree(tree, 50, 0);
    createTree(tree, 30, 1);
    createTree(tree, 20, 3);
    createTree(tree, 40, 4);
    createTree(tree, 70, 2);
    createTree(tree, 60, 5);
    createTree(tree, 80, 6);

    // 遍历二叉树
    printf("Preorder traversal: ");
    preOrderTraversal(tree, 0);
    printf("\n");

    printf("Inorder traversal: ");
    inOrderTraversal(tree, 0);
    printf("\n");

    printf("Postorder traversal: ");
    postOrderTraversal(tree, 0);
    printf("\n");

    return 0;
}
