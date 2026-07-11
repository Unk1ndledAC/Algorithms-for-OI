inline void transfer(int n,int i){
	if(n==0) return;
	int x=n/i,y=n%i;
	transfer(x,i);
	char j[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	printf("%c",j[y]);
}