#include <stdio.h>
#include <algorithm>
using namespace std;

FILE *fin = stdin;
FILE *fout = stdout;

int Dy[2][3][31];

int main()
{
    int n,w;
    int i;
    int ans = 0;

    fscanf(fin,"%d%d",&n,&w);
    
    Dy[0][2][0] = -(1<<20);
    for(i=1;i<=n;i++){
        int tree;
        fscanf(fin,"%d",&tree);
        
        if (tree == 1) {
            for (int j = 0; j <= w; j++) {
                Dy[i%2][1][j] = max(Dy[(i-1)%2][1][j], Dy[(i-1)%2][2][j-1]) + 1;
                ans = max(ans, Dy[i%2][1][j]);
            }
        } else {
            for (int j = 0; j <= w; j++) {
                Dy[i%2][2][j] = max(Dy[(i-1)%2][1][j-1], Dy[(i-1)%2][2][j]) + 1;
                ans = max(ans, Dy[i%2][2][j]);
            }
        }
    }

    fprintf(fout,"%d",ans);
    return 0;
}
