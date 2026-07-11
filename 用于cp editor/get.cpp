inline int get(){
	register char ch;
	register bool bo=false;
	register int res=0;
	while(ch=getchar(),!isdigit(ch));
		if(ch=='-')bo=true;
	res=ch-'0';
	while(ch=getchar(),isdigit(ch))
		res=(res<<1)+(res<<3)+ch-'0';
	return bo? ~res+1:res;
}