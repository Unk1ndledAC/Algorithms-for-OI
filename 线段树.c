#include <stdio.h>
#include <stdlib.h>

// 线段树节点
struct SegmentTreeNode {
    int start;  // 节点代表的区间起始位置
    int end;    // 节点代表的区间结束位置
    int sum;    // 节点保存的区间和
    struct SegmentTreeNode* left;   // 左子节点
    struct SegmentTreeNode* right;  // 右子节点
};

// 创建线段树节点
struct SegmentTreeNode* createNode(int start, int end) {
    struct SegmentTreeNode* node = (struct SegmentTreeNode*)malloc(sizeof(struct SegmentTreeNode));
    node->start = start;
    node->end = end;
    node->sum = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 构建线段树
struct SegmentTreeNode* buildSegmentTree(int* nums, int start, int end) {
    if (start > end) {
        return NULL;
    }

    struct SegmentTreeNode* root = createNode(start, end);
    if (start == end) {
        root->sum = nums[start];
    } else {
        int mid = start + (end - start) / 2;
        root->left = buildSegmentTree(nums, start, mid);
        root->right = buildSegmentTree(nums, mid + 1, end);
        root->sum = root->left->sum + root->right->sum;
    }

    return root;
}

// 区间查询
int querySegmentTree(struct SegmentTreeNode* root, int start, int end) {
    if (root == NULL || start > root->end || end < root->start) {
        return 0;
    }

    if (start <= root->start && end >= root->end) {
        return root->sum;
    }

    return querySegmentTree(root->left, start, end) + querySegmentTree(root->right, start, end);
}

// 区间更新
void updateSegmentTree(struct SegmentTreeNode* root, int index, int newValue) {
    if (root == NULL || index < root->start || index > root->end) {
        return;
    }

    if (root->start == root->end && root->start == index) {
        root->sum = newValue;
        return;
    }

    updateSegmentTree(root->left, index, newValue);
    updateSegmentTree(root->right, index, newValue);
    root->sum = root->left->sum + root->right->sum;
}

// 主函数
int main() {
    int nums[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(nums) / sizeof(nums[0]);

    struct SegmentTreeNode* root = buildSegmentTree(nums, 0, n - 1);

    printf("Sum of elements in the range [1, 4]: %d\n", querySegmentTree(root, 1, 4));

    updateSegmentTree(root, 2, 6);

    printf("Sum of elements in the range [1, 4] after update: %d\n", querySegmentTree(root, 1, 4));

    return 0;
}
