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