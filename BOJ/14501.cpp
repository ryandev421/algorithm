#include <stdio.h>
#include <vector>
#define MAX_N 15
using namespace std;

int N;
vector<pair<int, int> > Arr;
int Dy[MAX_N+1];
int Ans;

int main()
{
    int i,j;
    scanf("%d",&N);
    for(i=0;i<N;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        Arr.push_back(make_pair(a,b));
    }
    for(i=0;i<N;i++){
        for(j=i+Arr[i].first;j<=N;j++) {
            Dy[j] = Dy[j] < Dy[i] + Arr[i].second ? Dy[i]+Arr[i].second : Dy[j];
            Ans = Ans > Dy[j] ? Ans : Dy[j];
        }
    }
    printf("%d",Ans);
    return 0;
}
