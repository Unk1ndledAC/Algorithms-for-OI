inline int prime(int x){
	int p[262144]={2},num=1;
	int i,t=sqrt(x);
	for(register i=0;i<num;i++){
		if(x%p[i]==0) return 0;
		if(p[i]>t) break;
	}
	p[num++]=x;
	return 1;
}