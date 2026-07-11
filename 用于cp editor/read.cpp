template<class T>
inline void read(T &res){
	register char ch;
	register bool bo=false;
	while(ch=getchar(),!isdigit(ch));
		if(ch=='-')bo=true;
	res=ch-'0';
	while(ch=getchar(),isdigit(ch))
		res=(res<<1)+(res<<3)+ch-'0';
	if(bo)res=~res+1;
	return;
}