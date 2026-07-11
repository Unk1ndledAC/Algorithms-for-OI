inline void ecgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1,y=0;
		return;
	}
	int tmp=x;
	x=y;
	y=tmp-(a/b)*y;`
}