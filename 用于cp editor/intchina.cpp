inline void intchina(){
	for(register int i=1;i<=3;i++){
		exgcd(sum/a[i],a[i],x,y);
		ans=ans+(sum/a[i]*x*b[i])%mod;
		ans%=mod;
	}
}