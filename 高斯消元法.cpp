#include<stdio.h>
#define MAX 10
 
double A[MAX][MAX]; //系数矩阵
double b[MAX];      //右端项
double X[MAX];      //迭代向量
int NUM;            //A的阶数
int size;           //最大迭代次数
 
 
 
int main(void)
{
    int i,j,k;     //计数器
    float Aik;     //正消过程用到的变量名
    float S;       //回代过程用到的变量名
    //以下代码输入系数矩阵A,右端项b
    printf("请输入系数矩阵A的阶数：");
    scanf("%d",&NUM);;
    size=NUM;
    for(i=1;i<=size;i++)
    {
        printf("请输入A的第%d行元素,各元素间以空格间隔:\n",i);
        for(j=1;j<=size;j++)
            scanf("%lf",&A[i-1][j-1]);
    }
    
    printf("输入右端项b,各元素间以空格间隔:\n");
    for(i=1;i<=size;i++)
    {
        scanf("%lf",&b[i-1]);
    }
    
    
    //在屏幕中输出用户输入的系数矩阵A和矩阵B
    printf("\n亲爱的，您输入的维度是%d!\n您输入的矩阵A[][]:\n\n",NUM);    //在屏幕中输出用户输入的矩阵A
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            printf("%f\t",A[i][j]);
        printf("\n\n");
    }
    printf("\n您输入的矩阵b[]：\n\n");
    for(i=0;i<size;i++)
        printf("\t%f\t\n\n",b[i]);
    printf("\n\v");//打印矩阵b[]
 
    
    //以下代码是高斯消去法的主要步骤
    for(k=0;k<size-1;k++)
    {
        if(!A[k][k])
            return -1;
        for(i=k+1;i<size;i++)
        {
            Aik=A[i][k]/A[k][k];
            for(j=k;j<size;j++)
            {
                A[i][j]=A[i][j]-Aik*A[k][j];
            }
            b[i]=b[i]-Aik*b[k];
        }
    }//首先通过正消过程，参见书本137页
    printf("A[]\n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            printf("%f\t",A[i][j]);
        printf("\n\n");
    }
    printf("\nb[]\n");
    for(i=0;i<size;i++)
        printf("\t%f\t\n\n",b[i]);
    printf("\n\n"); //此处返回正消过程的结果
    X[size-1]=b[size-1]/A[size-1][size-1];
    for(k=size-2;k>=0;k--)
    {
        S=b[k];
        for(j=k+1;j<size;j++)
        {
            S=S-A[k][j]*X[j];
        }
        X[k]=S/A[k][k];
    }    //回代
    
    //此处打印出向量X
    printf("The solution x[]=\n\n");
    for(i=0;i<size;i++)
        printf("\t%f\t\n\n",X[i]);
    return 0;
}
