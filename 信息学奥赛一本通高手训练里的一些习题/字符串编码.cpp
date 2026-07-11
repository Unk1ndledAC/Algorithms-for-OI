#include<bits/stdc++.h>
typedef long long ll;
const int N=2e5+5,base=7,mod1=1e9+7,mod2=1e9+9;
struct hash_val{
    int hash1,hash2;
    hash_val(){}
    hash_val(const int &a,const int &b):
        hash1(a),hash2(b){}
    inline bool operator == (const hash_val &rhs)const{
        return hash1==rhs.hash1&&hash2==rhs.hash2;
    }
    inline hash_val operator * (const int &rhs)const{
        return hash_val(1LL*hash1*rhs%mod1,1LL*hash2*rhs%mod2);
    }
    inline hash_val operator * (const hash_val &rhs)const{
        return hash_val(1LL*hash1*rhs.hash1%mod1,1LL*hash2*rhs.hash2%mod2);
    }
    inline hash_val operator - (const hash_val &rhs)const{
        int res1=hash1-rhs.hash1;if(res1<0)res1+=mod1;
        int res2=hash2-rhs.hash2;if(res2<0)res2+=mod2;
        return hash_val(res1,res2);
    }
    inline hash_val operator + (const int &rhs)const{
        int res1=hash1+rhs;if(res1>mod1)res1-=mod1;
        int res2=hash2+rhs;if(res2>mod2)res2-=mod2;
        return hash_val(res1,res2);
    }
}pre_s[26][N],h_t[26],p[N];
int n,m,totans,ans[N],lst[26][N];
char s[N],t[N];
bool vis[26];
inline hash_val get_hash(const int &l,const int &r,const int &c){
    return pre_s[c][r]-pre_s[c][l-1]*p[r-l+1];
}
int main(){
    scanf("%d %d %s %s",&n,&m,s+1,t+1);
    if(n<m){
        puts("0");
        return 0;
    }
    for(int i=0;i<26;++i)
        pre_s[i][0]=h_t[i]=hash_val(0,0);
    p[0]=hash_val(1,1);
    for(int i=1,c;i<=n;++i){
        p[i]=p[i-1]*base;
        for(int j=0;j<26;++j){
            lst[j][i]=lst[j][i-1];
            pre_s[j][i]=pre_s[j][i-1]*base;
        }
        c=s[i]-'a';
        lst[c][i]=i;
        pre_s[c][i]=pre_s[c][i]+1;
    }
    for(int i=1,c;i<=m;++i){
        for(int j=0;j<26;++j)
            h_t[j]=h_t[j]*base;
        c=t[i]-'a';
        h_t[c]=h_t[c]+1;
    }
    bool flg;
    for(int st=1,ed=m;ed<=n;++st,++ed){
        flg=true;
        memset(vis,0,sizeof(vis));
        for(int x=0,y;x<26;++x)
            if(lst[x][ed]>=st&&!vis[x]){
                y=t[lst[x][ed]-st+1]-'a';
                if(vis[y])
                    flg=false;
                else if(!(get_hash(st,ed,x)==h_t[y]))
                    flg=false;
                else if(!(get_hash(st,ed,y)==h_t[x]))
                    flg=false;
                else
                    vis[x]=vis[y]=true;
                if(!flg)break;
            }
        if(flg)
            ans[++totans]=st;
    }
    printf("%d\n",totans);
    for(int i=1;i<=totans;++i)
        printf("%d%c",ans[i],"\n"[i==totans]);
    return 0;
}