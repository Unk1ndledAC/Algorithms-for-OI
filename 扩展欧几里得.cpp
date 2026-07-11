#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<math.h>
using namespace std;
int extendgcd(int a,int b){//ax+by=d,Çó(x,y) {
	int x,y,t;
	if(b==0){
		x=1,y=0;
		return a;
	}
	t=x,x=y,y=t-(a/b)*y;
	return extendgcd(b,a%b);
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<< extendgcd(a,b);
	return 0;
}
