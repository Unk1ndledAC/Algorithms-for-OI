template<class T>
inline void read(T &res){
	char ch;
	bool bo=false;
	while(ch=getchar(),!isdigit(ch));
		if(ch=='-')bo=true;
	res=ch-'0';
	while(ch=getchar(),isdigit(ch))
		res=(res<<1)+(res<<3)+ch-'0';
	if(bo)res=~res+1;
	return;
}
template<class T>
inline void put(T x){
	if(x<0){
		putchar('-');
		x=~x+1;
	}
	if(x>9)put(x/10);
	putchar(x%10+'0');
	return;
}
