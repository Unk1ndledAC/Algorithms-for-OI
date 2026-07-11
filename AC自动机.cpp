namespace AC {
    const int maxn = 2;
    struct Tree {
        int fail;
        int vis[maxn];
        int edn;
    } AC[N];
    int cnt = 0;
    inline void clear(int x) {
        memset(AC[x].vis, 0, sizeof(AC[x].vis));
        AC[x].fail = 0;
        AC[x].edn = 0;
    }
    inline void build(string s) {
        int len = s.length();
        int now = 0;
        for (int i = 0; i < len; ++i) {
            if (AC[now].vis[s[i] - '0'] == 0) {
                AC[now].vis[s[i] - '0'] = ++cnt;
                clear(cnt);
            }
            now = AC[now].vis[s[i] - '0'];
        }
        AC[now].edn = 1;
    }
    queue<int> q;
    inline void get_fail() {
        for (int i = 0; i < maxn; ++i) {
            if (AC[0].vis[i]) {
                AC[AC[0].vis[i]].fail = 0;
                q.push(AC[0].vis[i]);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < maxn; ++i) {
                if (AC[u].vis[i]) {
                    AC[AC[u].vis[i]].fail = AC[AC[u].fail].vis[i];
                    AC[AC[u].vis[i]].edn |= AC[AC[AC[u].fail].vis[i]].edn;
                    q.push(AC[u].vis[i]);
                } else 
                    AC[u].vis[i] = AC[AC[u].fail].vis[i];
            }
        }
    }
    inline int AC_Query(string s) {
        int len = s.length();
        int now = 0, ans = 0;
        for (int i = 0; i < len; ++i) {
            now = AC[now].vis[s[i] - '0'];
            for (int j = now; j && AC[j].edn != -1; j = AC[j].fail) {
                ans += AC[j].edn;
                AC[j].edn = -1;
            }
        }
        return ans;
    }
    void init() {
        cnt = 0;
        clear(0);
    }
}