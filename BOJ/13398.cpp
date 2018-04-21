#include <stdio.h>
#include <limits>
#define MAX_N 100000

FILE *fin = stdin;
FILE *fout = stdout;

int N;
int Arr[MAX_N+1];
int Le[MAX_N+1],Ri[MAX_N+1];
int Ans = std::numeric_limits<int>::min();

int main()
{
    int i;
    fscanf(fin,"%d",&N);
    for(i=1;i<=N;i++) fscanf(fin,"%d",&Arr[i]);

    for(i=1;i<=N;i++){
        if(Le[i-1]+Arr[i] > Arr[i]) Le[i] = Le[i-1]+Arr[i];
        else Le[i] = Arr[i];
        Ans = (Ans < Le[i]) ? Le[i] : Ans;
    }
    for(i=N;i>=1;i--) {
        if(Ri[i+1]+Arr[i] > Arr[i]) Ri[i] = Ri[i+1] + Arr[i];
        else Ri[i] = Arr[i];
    }
    for(i=1;i<=N;i++){
        int num = Le[i-1] + Ri[i+1];
        Ans = (Ans < num) ? num : Ans;
    }

    fprintf(fout,"%d",Ans);
    return 0;
}
