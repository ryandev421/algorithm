#include <stdio.h>
#define MAX_N 100
#define REMAIN 1000000007

int N,L,R;
long long Dy[MAX_N+1][MAX_N+1][MAX_N+1];

int main()
{
    int i,j,k;
    scanf("%d %d %d",&N,&L,&R);

    Dy[1][1][1] = 1;
    for(i=2;i<=N;i++) {
        for(j=1;j<=i;j++) {
            for(k=1;k<=i-j+1;k++) {
                Dy[i][j][k] = Dy[i-1][j-1][k] + Dy[i-1][j][k-1] + Dy[i-1][j][k] * (i-2);
                Dy[i][j][k] %= REMAIN;
            }
        }
    }
    printf("%lld",Dy[N][L][R]);
    return 0;
}
