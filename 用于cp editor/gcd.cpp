inline int gcd(int m,int n){
	if(m==n) return m;
	if(m<n) return gcd(n,m);
	if(m%2==0){
		if(n%2==0) return gcd(m/2,n/2)<<1;
		else return gcd(m/2,n);
	}
	else{
		if(n%2==0) return gcd(m,n/2);
		else return gcd(n,m-n);
	}
}