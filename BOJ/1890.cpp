#include <stdio.h>
#define MAX_N 100

FILE *fin = stdin;
FILE *fout = stdout;

int N;
int Map[MAX_N+1][MAX_N+1];
long long Dy[MAX_N+1][MAX_N+1];

bool isWall(int y,int x)
{
    return !(y>=1 && x>=1 && y<=N && x<=N);
}

int main()
{
    int i,j;

    fscanf(fin,"%d",&N);
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++) fscanf(fin,"%d",&Map[i][j]);
    }

    Dy[1][1] = 1;
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            if (Map[i][j]==0) continue;
            if (!isWall(i, j+Map[i][j]))
                Dy[i][j+Map[i][j]] += Dy[i][j];
            if (!isWall(i+Map[i][j],j)) 
                Dy[i+Map[i][j]][j] += Dy[i][j];
        }
    }
    fprintf(fout,"%lld",Dy[N][N]);
    return 0;
}
