#include <stdio.h>
#define N 9
int board[N][N];
void print(){
    for(int i=0;i<N;i++,putchar('\n'))
        for(int j=0;j<N;j++)
            printf("%2d",board[i][j]);
}
int judge(int row,int col,int num){
    for(int x=0;x<N;x++)
        if(board[row][x]==num||board[x][col]==num)
            return 0;
    int startRow=row-row%3,startCol=col-col%3;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i+startRow][j+startCol]==num)
                return 0;
    return 1;
}
int solve(int row,int col){
    if(row==N-1&&col==N)
        return 1;
    if(col==N)
        row++,col=0;
    if(board[row][col])
        return solve(row,col+1);
    for(int num=1;num<=N;num++) 
        if(judge(row,col,num)){
            board[row][col]=num;
            if(solve(row,col+1))
                return 1;
            board[row][col]=0;
        }
    return 0;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&board[i][j]);
    if (solve(0,0))
        print(board);
    else
        puts("Отсутствует решение");
    return 0;
}
