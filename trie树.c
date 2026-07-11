#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODE 1000000 // Trie树最大节点数
#define MAX_LEN 30 // 字符串最大长度

int trie[MAX_NODE][26]; // Trie树的存储
bool is_end[MAX_NODE]; // 标记是否为某个字符串的结尾
int cnt = 1; // Trie树的节点计数

// 插入字符串s
void insert(char* s) {
    int p = 1;
    for (int i = 0; s[i]; ++i) {
        int ch = s[i] - 'a';
        if (!trie[p][ch])
            trie[p][ch] = ++cnt;
        p = trie[p][ch];
    }
    is_end[p] = true;
}

// 查找字符串s
bool find(char* s) {
    int p = 1;
    for (int i = 0; s[i]; ++i) {
        int ch = s[i] - 'a';
        if (!trie[p][ch])
            return false;
        p = trie[p][ch];
    }
    return is_end[p];
}
// 删除字符串s
void remove(char* s) {
    int p = 1;
    for (int i = 0; s[i]; ++i) {
        int ch = s[i] - 'a';
        if (!trie[p][ch])
            return;
        p = trie[p][ch];
    }
    is_end[p] = false;
}

// 计算以prefix为前缀的字符串数
int count_prefix(char* prefix) {
    int p = 1, cnt = 0;
    for (int i = 0; prefix[i]; ++i) {
        int ch = prefix[i] - 'a';
        if (!trie[p][ch])
            return 0;
        p = trie[p][ch];
    }
    // BFS遍历Trie树
    int queue[MAX_NODE] = { 0 }, front = 0, rear = 0;
    queue[rear++] = p;
    while (front != rear) {
        int u = queue[front++];
        if (is_end[u]) ++cnt;
        for (int i = 0; i < 26; ++i)
            if (trie[u][i])
                queue[rear++] = trie[u][i];
    }
    return cnt;
}
