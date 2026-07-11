int Sunday(const string &T, const string &P){
    int m=P.length(),n=T.length();
    for(register int i = 0; i < maxNum; i++)
        shift[i]=m+1;
    for(register int i=0;i<m;i++)
        shift[P[i]]=m-i;
    int s=0,j;
    while(s<=n-m){
        j=0;
        while(T[s+j]==P[j]){
            j++;
            if(j>=m)return s;
        }
        s+=shift[T[s+m]];
    }
    return -1;
}
