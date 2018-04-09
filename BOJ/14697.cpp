#include <stdio.h>
#define MAX_N 300

FILE *fin = stdin;
FILE *fout = stdout;

int Dy[MAX_N+1];
int Room[4];
int N;

int main()
{
    int i,j ;
    for(i=1;i<=3;i++) fscanf(fin,"%d", &Room[i]);
    fscanf(fin,"%d",&N);

    Dy[0] = 1;
    for(j=1;j<=N;j++) {
        for(i=1;i<=3;i++) {
            if(Room[i] > j) continue;
            Dy[j] = (Dy[j] | Dy[j-Room[i]]);
        }
    }
    fprintf(fout,"%d", Dy[N]);
    return 0;
}
