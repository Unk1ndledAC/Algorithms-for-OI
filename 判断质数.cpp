#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<math.h>
using namespace std;

int prime(int x)//ÖÊÊı 
{
	int p[262144]={2},num=1;
	int i,t=sqrt(x);
	for(i=0;i<num;i++)
	{
		if(x%p[i]==0) return 0;
		if(p[i]>t) break;
	}
	p[num++]=x;
	return 1;
}
int main()
{
	
	return 0;
}
