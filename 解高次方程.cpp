#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
using namespace std;
int n,tot=0;
double a[100]={0},delta=0.000001;
double calc(double x)
{
	double ans=0,pow=1;
	int i;
	for(i=0;i<=n;i++)
	{
		ans+=pow*a[i];
		pow*=x;
	}
	return ans;
}
void root(double from,double to)
{
	double mid=(from+to)/2;
	double f=calc(from),t=calc(to),m=calc(mid);
	if(m>-delta&&m<delta)
	{
		printf("Root %d =%lf\n",++tot,mid);
		return;
	}
	if(m>0)
	{
		if(f<0) root(from,mid);
		if(t<0) root(mid,to);
	}
	else
	{
		if(f>0) root(from,mid);
		if(t>0) root(mid,to);
	}
}
int main()//有待修正 
{
	int i;
	printf("方程求根，\n输入最高次方数：\n");
	scanf("%d",&n);
	printf("输入从最高次项开始各项系数：\n");
	for(i=n;i>=0;i--) scanf("%lf",&a[i]);
	root(-2147483647,2147483647);
	if(tot==0) printf("此方程无解！\n");
	else printf("此方程在（-2^31,2^31）内共%d个根!\n",tot);
	return 0;
}
