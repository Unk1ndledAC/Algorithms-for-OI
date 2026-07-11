#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("output3.txt","r",stdin);//**********
	freopen("out.cpp","w",stdout);//********
	printf("#include<bits/stdc++.h>\nusing namespace std;\nint main(){\n");
	char s[25];
	while(cin>>s)
		printf("\tprintf(\"%s\\n\");\n",s);
	printf("return 0;\n}");
	return 0;
} 
