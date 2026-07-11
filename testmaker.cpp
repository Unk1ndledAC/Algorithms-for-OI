#include<cstdio>
char fre[64],fre2[64],infre[64],outfre[64],ansfre[64];
int main(){
    printf("Please input the name of the test file:");
    scanf("%s",fre);
    printf("Please input the form of the input file:");
    scanf("%s",infre);
    printf("Please input the form of the output file:");
    scanf("%s",outfre);
    printf("Please inpur the form of the answer file:");
    scanf("%s",ansfre);
    sprintf(fre2,"test%s.bat",fre);
    freopen(fre2,"w",stdout);
    printf("@echo off\n");
    for(int i0=1;i0<=20;++i0){
        printf("copy \"%s%d.in\" \"%s.%s\" >nul\n",fre,i0,fre,infre);
        printf("echo Test Case: %d\n",i0);
        printf("set kai="); putchar('%');printf("time");putchar('%'); printf("\n");
        printf("\"%s.exe\"\n",fre);
        printf("set jie="); putchar('%');printf("time");putchar('%'); printf("\n");
        printf("set TotalTime=0\n");
        printf("set /a second1=1");putchar('%'); printf("kai:~-5,2");putchar('%'); putchar('%'); printf("kai:~-2");putchar('%'); printf("0-100000\n");
        printf("set /a second2=1");putchar('%'); printf("jie:~-5,2");putchar('%'); putchar('%'); printf("jie:~-2");putchar('%'); printf("0-100000\n");
        printf("set /a TotalTime+=");putchar('%'); printf("second2");putchar('%'); printf("-");putchar('%'); printf("second1");putchar('%'); printf("\n");
        printf("fc \"%s.%s\" \"%s%d.%s\" /W\n",fre,outfre,fre,i0,ansfre);
        printf("echo time=");putchar('%'); printf("TotalTime");putchar('%'); printf("ms\n");
        printf("echo.\n");
        printf("del \"%s.%s\"\n",fre,infre);
        printf("del \"%s.%s\"\n",fre,outfre);
    }
    printf("pause");
}