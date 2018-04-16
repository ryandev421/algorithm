#include <stdio.h>
#define MAX_N 100000

FILE *fin = stdin;
FILE *fout = stdout;

int N;
int Arr[MAX_N+1];

int main()
{
    int i, sum = 0;
    long long ans = 0;
    fscanf(fin,"%d",&N);

    for(i=1;i<=N;i++) {
        fscanf(fin,"%d",&Arr[i]);
        sum += Arr[i];
    }
    for(i=1;i<=N;i++) {
        ans += (long long)(sum-Arr[i]) * Arr[i];
    }
    fprintf(fout,"%lld",ans/2);
    return 0;
}
