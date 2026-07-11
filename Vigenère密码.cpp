#include<bits/stdc++.h>
using namespace std;
char key[101],m[1001],ans[1001];
int k[101],a[1001];
bool b[1001];
int lk,len;
int main(){
    scanf("%s%s",key,m);
    lk=strlen(key);len=strlen(m);
    for (int i=0;i<lk;i++)
        if(key[i]>='a') k[i]=key[i]-'a';
        else k[i]=key[i]-'A';
    for(int i=0;i<len;i++)
        if(m[i]>='a') a[i]=m[i]-'a';
        else{
            a[i]=m[i]-'A';
			b[i]=true;
        }
    int p=0;
    for(int i=0;i<len;i++){
        int num=a[i]-k[p++]; 
		if(p==lk) p=0;
        if(num<0) num+=26;
        if(b[i]) ans[i]=num+'A';
        else ans[i]=num+'a';
    }
    for(int i=0;i<len;i++)
        printf("%c",ans[i]);
    return 0;
}
