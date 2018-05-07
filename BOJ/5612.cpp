#include <stdio.h>

FILE *fin = stdin;
FILE *fout = stdout;

int N;
int Count;
int Ans;

int main()
{
    int i;
    fscanf(fin,"%d",&N);
    fscanf(fin,"%d",&Count);
    Ans = Count;

    for(i=1;i<=N;i++){
        int s,e;
        fscanf(fin,"%d %d",&s,&e);
        if (Count + s - e <0){
            Ans = 0;
            break;
        }
        Count += s-e;
        Ans = Ans < Count ? Count : Ans;
    }
    fprintf(fout,"%d",Ans);
    return 0;
}
