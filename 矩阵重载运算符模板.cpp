#include<string.h>
const int mod=1e9+7,N=5005;
struct Matrix{
	int num[2][2];
	Matrix(){
		num[0][0]=1,num[1][0]=num[0][1]=0,num[1][1]=1;
	}
	Matrix(int x){
		if(!x)
			num[0][0]=num[1][0]=num[0][1]=num[1][1]=0;
		else if(x==1)
			num[0][0]=num[1][0]=num[0][1]=1,num[1][1]=0;
		else
			num[1][1]=-1,num[1][0]=num[0][1]=1,num[0][0]=0;
	}
	inline Matrix operator * (const Matrix &a) const{
		Matrix tmp=Matrix(0);
		for(register int i=0;i<2;i++)
			for(register int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					(tmp.num[i][j]+=1ll*num[i][k]*a.num[k][j]%mod)%=mod;
		return tmp;
	}
	inline Matrix operator + (const Matrix &a) const{
		Matrix tmp;
		for(register int i=0;i<2;i++)
			for(register int j=0;j<2;j++)
				tmp.num[i][j]=(num[i][j]+a.num[i][j])%mod;
		return tmp;
	}
	inline Matrix operator - (const Matrix &a) const{
		Matrix tmp;
		for(register int i=0;i<2;i++)
			for(register int j=0;j<2;j++)
				tmp.num[i][j]=(num[i][j]-a.num[i][j])%mod;
		return tmp;
	}
	inline Matrix operator ^ (const long long &a) const{
		Matrix x,tmp;
		long long y=a;
		memcpy(x.num,num,sizeof(num));
		while(y){
			if(y&1)
				tmp=tmp*x;
			y>>=1,x=x*x;
		}
		return tmp;
	}
}uni,ans,all,val[N<<2];
int main(){
	return 0;
}
