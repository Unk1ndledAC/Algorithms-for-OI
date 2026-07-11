#ifndef _BIG_INTEGER_H_
#define _BIG_INTEGER_H_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
class big_integer{
private:
    int value[2048];
    int len;
    char c;
public:
    friend ostream& operator<<(ostream&,big_integer);
    friend istream& operator>>(istream&,big_integer&);
    friend big_integer abs(big_integer);
    friend big_integer qf(big_integer);
    big_integer();
    big_integer(int);
    //---------------------------
    bool operator<(big_integer);
    bool operator>(big_integer);
    bool operator<=(big_integer);
    bool operator>=(big_integer);
    bool operator==(big_integer);
    //---------------------------
    big_integer operator+(big_integer);
    big_integer operator-(big_integer);
    big_integer operator*(big_integer);
    big_integer operator/(big_integer);
    big_integer operator%(big_integer);
    big_integer operator-(void);
    big_integer operator++(void);
    big_integer operator--(void);
    //---------------------------
    void operator+=(big_integer);
    void operator-=(big_integer);
    void operator*=(big_integer);
    void operator/=(big_integer);
    void operator%=(big_integer);
    
};
big_integer::big_integer(){
    len=0; memset(value,0,sizeof(value)); c='+';
}
big_integer::big_integer(int x){
    len=0; memset(value,0,sizeof(value)); c='+';
    if(x==0) 
    {
        value[++len]=0;
        return;
    }
    if(x<0) c='-',x=abs(x);
    while(x!=0) value[++len]=x%10,x/=10;
}
istream& operator>>(istream& in,big_integer& x){
    char c[2050]; int cnt=0;
    in>>c;
    int top=0; 
    if(c[0]=='-') x.c='-',top++;
    while(c[top]=='0') top++;
    for(int i=strlen(c)-1;i>=top;i--) x.value[++cnt]=c[i]-'0';
    x.len=cnt;
    return in;
}
ostream& operator<<(ostream& out,big_integer x){
    if(x.c=='-') out<<x.c;
    for(int i=x.len;i>=1;i--) out<<x.value[i];
    return out;
}
big_integer abs(big_integer x){
    if(x.c=='-') x.c='+';
    return x;
}
big_integer qf(big_integer x){
    if(x.c=='+') x.c='-';
    else x.c='+';
    return x;
}
//------------------------
big_integer qpow(big_integer a,int b){
	big_integer res=1;
	while(b){
		if(b&1)res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}
big_integer qmul(big_integer a,int b){
	big_integer res=0;
	while(b){
		if(b&1)res+=a;
		a+=a;
		b>>=1;
	}
	return res;
}
//-----------------------
bool big_integer::operator<(big_integer x){
    int flag=0;
    if(this->c=='+'&&x.c=='-') return 0;
    if(this->c=='-'&&x.c=='+') return 1;
    if(this->c=='-'&&x.c=='-') flag=1; 
    if(this->len<x.len) return 1^flag;
    if(this->len>x.len) return 0^flag;
    for(int i=x.len;i>=1;i--){
        if(this->value[i]==x.value[i]) continue;
        return (this->value[i]<x.value[i])^flag;
    }
    return 0;
}
bool big_integer::operator<=(big_integer x){
    int flag=0;
    if(this->c=='+'&&x.c=='-') return 0;
    if(this->c=='-'&&x.c=='+') return 1;
    if(this->c=='-'&&x.c=='-') flag=1; 
    if(this->len<x.len) return 1^flag;
    if(this->len>x.len) return 0^flag;
    for(int i=x.len;i>=1;i--){
        if(this->value[i]==x.value[i]) continue;
        return (this->value[i]<x.value[i])^flag;
    }
    return 1;
}
bool big_integer::operator>(big_integer x){
    int flag=0;
    if(this->c=='+'&&x.c=='-') return 1;
    if(this->c=='-'&&x.c=='+') return 0;
    if(this->c=='-'&&x.c=='-') flag=1; 
    if(this->len>x.len) return 1^flag;
    if(this->len<x.len) return 0^flag;
    for(int i=x.len;i>=1;i--){
        if(this->value[i]==x.value[i]) continue;
        return (this->value[i]>x.value[i])^flag;
    }
    return 0;
}
bool big_integer::operator>=(big_integer x){
    int flag=0;
    if(this->c=='+'&&x.c=='-') return 1;
    if(this->c=='-'&&x.c=='+') return 0;
    if(this->c=='-'&&x.c=='-') flag=1; 
    if(this->len>x.len) return 1^flag;
    if(this->len<x.len) return 0^flag;
    for(int i=x.len;i>=1;i--){
        if(this->value[i]==x.value[i]) continue;
        return (this->value[i]>x.value[i])^flag;
    }
    return 1;
}
bool big_integer::operator==(big_integer x){
    if(this->c!=x.c) return 0;
    if(this->len!=x.len) return 0;
    for(int i=1;i<=x.len;i++) if(this->value[i]!=x.value[i]) return 0;
    return 1;
}
big_integer big_integer::operator+(big_integer x){
    big_integer res;
    if(this->c=='+'&&x.c=='+') res.c='+';
    else if(this->c=='-'&&x.c=='-') res.c='-';
    else if(this->c=='+'&&x.c=='-') return *this-abs(x);
    else return x-abs(*this);
    res.len=max(this->len,x.len);
    int nxt=0;
    for(int i=1;i<=res.len;i++){
        res.value[i]=this->value[i]+x.value[i]+nxt;
        nxt=res.value[i]/10;
        res.value[i]%=10;
    }
    if(nxt!=0) res.value[++res.len]=nxt;
    return res;
}
void big_integer::operator+=(big_integer x){
    big_integer res;
    if(this->c=='+'&&x.c=='+') res.c='+';
    else if(this->c=='-'&&x.c=='-') res.c='-';
    else if(this->c=='+'&&x.c=='-') {
        *this=*this-abs(x);
        return;
    }
    else {
        *this=x-abs(*this);
        return;
    }
    res.len=max(this->len,x.len);
    int nxt=0;
    for(int i=1;i<=res.len;i++){
        res.value[i]=this->value[i]+x.value[i]+nxt;
        nxt=res.value[i]/10;
        res.value[i]%=10;
    }
    if(nxt!=0) res.value[++res.len]=nxt;
    *this=res;
}
big_integer big_integer::operator-(big_integer x){
    big_integer a,b,res;
    if(this->c=='+'&&x.c=='+');
    else if(this->c=='-'&&x.c=='-') return abs(x)-abs(*this);
    else if(this->c=='-'&&x.c=='+') return qf(abs(*this)+x);
    else if(this->c=='+'&&x.c=='-') return *this+abs(x);
    //--------
    if(*this>=x) a=*this,b=x;
    else a=x,b=*this,res.c='-';
    int i=1;
    for(i=1;i<=a.len;i++){
        if(a.value[i]<b.value[i]) res.value[i]=a.value[i]-b.value[i]+10,a.value[i+1]--;
        else res.value[i]=a.value[i]-b.value[i];
    }
    while(i>1&&res.value[i]==0) i--;
    res.len=i;
    return res;
}
void big_integer::operator-=(big_integer x){
    big_integer a,b,res;
    if(this->c=='+'&&x.c=='+');
    else if(this->c=='-'&&x.c=='-'){
        *this=abs(x)-abs(*this);
        return;
    }
    else if(this->c=='-'&&x.c=='+'){
        *this=qf(abs(*this)+x);
        return;
    }
    else if(this->c=='+'&&x.c=='-'){
        *this=*this+abs(x);
        return;
    }
    //--------
    if(*this>=x) a=*this,b=x;
    else a=x,b=*this,res.c='-';
    int i=1;
    for(i=1;i<=a.len;i++){
        if(a.value[i]<b.value[i]) res.value[i]=a.value[i]-b.value[i]+10,a.value[i+1]--;
        else res.value[i]=a.value[i]-b.value[i];
    }
    while(i>1&&res.value[i]==0) i--;
    res.len=i;
    *this=res;
}
big_integer big_integer::operator*(big_integer x){
    if(*this==0||x==0) return 0;
    big_integer res;
    if(this->c!=x.c) res.c='-';
    for(int i=1;i<=this->len;i++){
        for(int j=1;j<=x.len;j++){
            res.value[i+j-1]+=this->value[i]*x.value[j];
            res.value[i+j]+=res.value[i+j-1]/10;
            res.value[i+j-1]%=10;
        }
    }
    int l=this->len+x.len;
    while(res.value[l]>0) res.value[l+1]+=res.value[l]/10,res.value[l++]%=10;
    res.len=l-1;
    return res;
}
void big_integer::operator*=(big_integer x){
    if(*this==0||x==0) {
        *this=0;
        return;
    }
    big_integer res;
    if(this->c!=x.c) res.c='-';
    for(int i=1;i<=this->len;i++){
        for(int j=1;j<=x.len;j++){
            res.value[i+j-1]+=this->value[i]*x.value[j];
            res.value[i+j]+=res.value[i+j-1]/10;
            res.value[i+j-1]%=10;
        }
    }
    int l=this->len+x.len;
    while(res.value[l]>0) res.value[l+1]+=res.value[l]/10,res.value[l++]%=10;
    res.len=l-1;
    *this=res;
}
big_integer big_integer::operator/(big_integer x){
    if(abs(*this)<abs(x)) return 0;
    big_integer res,b=0;
    if(this->c!=x.c) res.c='-';
    x=abs(x);
    for(int i=this->len;i>=1;i--){
        b=b*10+this->value[i];
        if(b>=x) {
            res.len=max(res.len,i);
            while(b>=x) b=b-x,res.value[i]++;
        }
        else res.value[i]=0;
    }
    return res;
}
void big_integer::operator/=(big_integer x){
    if(abs(*this)<abs(x)) {
        *this=0;
        return;
    }
    big_integer res,b=0;
    if(this->c!=x.c) res.c='-';
    x=abs(x);
    for(int i=this->len;i>=1;i--){
        b=b*10+this->value[i];
        if(b>=x) {
            res.len=max(res.len,i);
            while(b>=x) b=b-x,res.value[i]++;
        }
        else res.value[i]=0;
    }
    *this=res;
}
big_integer big_integer::operator%(big_integer x){
    big_integer t=*this/x;
    return *this-t*x;
}
void big_integer::operator%=(big_integer x){
    big_integer t=*this/x;
    *this=*this-t*x;
}
big_integer big_integer::operator-(void){
    if(*this==0) return 0;
    this->c='-'; return *this;
}
big_integer big_integer::operator++(void){
    *this=*this+1;
    return *this;
}
big_integer big_integer::operator--(void){
    *this=*this-1;
    return *this;
}
//----
#endif
