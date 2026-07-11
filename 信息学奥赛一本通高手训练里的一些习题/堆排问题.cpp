#include<bits/stdc++.h>
template<class T>
inline void tense(T &x,const T &y){
    if(x>y)x=y;
}
#define  pi std::pair<int,int>
#define mp(x,y) std::make_pair(x,y)
const int mod=1e6+3,base=19260817,INF=0x3f3f3f3f,N=17,M=121,S=1e6+5;
pi del[M];
int n,m,ret,rt,lc[N],rc[N],fa[N];
inline int find_max(int x,int *a){
    if(!x)return 0;
    int res=x,l=find_max(lc[x],a),r=find_max(rc[x],a);
    if(a[l]>a[res])res=l;
    if(a[r]>a[res])res=r;
    return res;
}
inline void dfs(int x,int *a){
    if(!x)return;
    int v=find_max(x,a);
    if(x!=v)++ret,std::swap(a[x],a[v]);
    dfs(lc[x],a),dfs(rc[x],a);
}
struct sta{
    int a[N],dis,val;
    inline void scan(){
        dis=0;
        for(int i=1;i<=n;++i)
            scanf("%d",a+i);
    }
    inline bool operator == (const sta &rhs)const{
        for(int i=1;i<=n;++i)
            if(a[i]!=rhs.a[i])return false;
        return true;
    }
    inline sta operator + (const pi &p)const{
        sta res=*this;
        std::swap(res.a[p.first],res.a[p.second]),++res.dis;
        return res;
    }
    inline bool operator < (const sta &rhs)const{
        return val>rhs.val;
    }
    inline int solve(){
        ret=0;
        static int t[N];
        for(int i=1;i<=n;++i)
            t[i]=a[i];
        dfs(rt,t);
        return ret;
    }
    inline void init(int *x){
        dis=0;
        for(int i=1;i<=n;++i)
            a[i]=x[i];
    }
    inline bool check(){
        for(int i=1;i<=n;++i)
            if(fa[i]&&a[i]>a[fa[i]])
                return false;
            return true;
    }
}src;
struct hash_table{
    sta to[S];
    int ect,adj[mod],nxt[S];
    #define trav(u) for(int e=adj[u];e;e=nxt[e])
    inline void clear(){
        ect=0;
        memset(adj,0,sizeof(adj));
    }
    inline void add(int x,sta p){
        nxt[++ect]=adj[x];
        adj[x]=ect;
        to[ect]=p;
    }
    inline int get_hash(sta p){
        int res=0;
        for(int i=1;i<=n;++i)
            res=(1LL*base*res+1004235809LL*p.a[i])%mod;
        return res;
    }
    inline void insert(sta p){
        int x=get_hash(p);
        add(x,p);
    }
    inline bool query(sta p){
        int x=get_hash(p);
        trav(x)if(to[e]==p)return true;
        return false;
    }
    #undef trav
}H;
std::priority_queue<sta> que;
inline int bfs(){
    int qr=0;
    H.insert(src),que.push(src);
    while(!que.empty()){
        sta u=que.top();que.pop();
        for(int dir=1;dir<=m;++dir){
            sta v=u+del[dir];
            if(H.query(v))continue;
            if(v.check())return v.dis;
            v.val=v.dis+v.solve();
            H.insert(v),que.push(v);
        }
    }
    return -1;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",fa+i);
        if(fa[i])
            (lc[fa[i]]? lc[fa[i]]:rc[fa[i]])=i;
        else
            rt=i;
    }
    src.scan();
    for(int i=1;i<=m;++i){
        int x,y;
        scanf("%d %d",&x,&y);
        del[i]=mp(x,y);
    }
    if(m==(n*(n-1)>>1))printf("%d\n",src.solve());
    else if(src.check())puts("0");
    else printf("%d\n",bfs());
    return 0;
}