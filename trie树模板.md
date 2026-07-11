```c++
inline bool ins(char* t){
    int now=0;
    for(int i=0;i<strlen(t);i++){
        if(!trie[now][t[i]-'0'])trie[now][t[i]-'0']=++trie_num;
        now=trie[now][t[i]-'0'];
    }
    vis[now]=1;
    return true;
}
```
