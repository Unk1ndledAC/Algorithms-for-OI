inline void kmp(){
    nxt[1]=0;
	int j=0;
    for(register nt i=2;i<=m;i++){//t
        while(j>0&&t[j+1]!=t[i])j=nxt[j];
        if(t[j+1]==t[i])j++;
        nxt[i]=j;
    }
    j=0;
	for(register int i=1;i<=n;i++){//t-->s
		while(j>0&&t[j+1]!=s[i])j=nxt[j];
		if(t[j+1]==s[i])j++;
		if(j==m){
			printf("%d\n",i-j+1);
			j=nxt[j];
		}
	}
}