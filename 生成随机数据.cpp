#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
typedef long long ll;
inline int random(int n){
    return (ll)rand()*rand()%n;
}
inline void integers(int n,int m){ //create n integers [-m,m]
    for(register int i=1;i<=n;i++)  
        printf("%d\n",random((m<<1)+1)-m);
}
inline void sections(int n,int m){//create n sections [1,m]
    for(register int i=1;i<=n;i++){
        int l=random(m)+1,r=random(m)+1;
        if(l>r)swap(l,r);
        printf("%d %d\n",l,r);
    }
}
inline void tree(int n){//create a tree with n points(a undirected graph with n points ans n-1 edges),and the value of edges range from 1 to 1e9
    for(register int i=2;i<=n;i++){
        int fa=random(i-1)+1,val=random(1e9)+1;
        printf("%d %d %d\n",fa,i,val);
    }
}
inline void graph(int n,int m){//create a undirected graph with n points and m edges,there are no heavy edges,self rings,and must be connected,5<=n<=m<=n*(n-1)/4<=1e6
    pair<int,int>e[1000005];//save data
    map< pair<int,int>,bool >h;//prevent heavy edges
    //generate a tree first to ensure connectivity
    for(register int i=1;i<n;i++){
        int fa=random(i)+1;
        e[i]=make_pair(fa,i+1);
        h[e[i]]=h[make_pair(i+1,fa)]=1;
        
    }
    //then generate the remaining m-n+1 edges
    for(register int i=n;i<=m;i++){
        int x,y;
        do{
            x=random(n)+1,y=random(n)+1;
        }while(x==y||h[make_pair(x,y)]);
        e[i]=make_pair(x,y);
        h[e[i]]=h[make_pair(y,x)]=1;
    }
    //random disruption,output
    random_shuffle(e+1,e+m+1);
    for(register int i=1;i<=m;i++)
        printf("%d %d\n",e[i].first,e[i].second);
}
int main(){
    srand((unsigned)time(0));
    
    return 0;
}