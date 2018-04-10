#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX_N 4000

FILE *fin = stdin;
FILE *fout = stdout;

int Dy[MAX_N+1][MAX_N+1];
char A[MAX_N+2], B[MAX_N+2];
int N,M;

int main()
{
    fscanf(fin,"%s%s",&A[1],&B[1]);
    N = (int)strlen(&A[1]);
    M = (int)strlen(&B[1]);

    int i,j;
    int ans = 0;
    for(i=1;i<=N;i++) {
        for(j=1;j<=M;j++) {
            if (A[i] == B[j]) {
                Dy[i][j] = Dy[i-1][j-1] + 1;
            }
            ans = std::max(ans, Dy[i][j]);
        }
    }
    fprintf(fout,"%d",ans);
    return 0;
}
