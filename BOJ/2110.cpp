#include <stdio.h>
#include <algorithm>
#include <functional>
#define MAX_N 200000
using namespace std;

FILE *fin = stdin;
FILE *fout = stdout;

int N, C;
int Arr[MAX_N+1];

int main()
{
    int i;
    fscanf(fin,"%d %d",&N,&C);
    for(i=1;i<=N;i++) fscanf(fin,"%d",&Arr[i]);
    sort(Arr+1,Arr+1+N, less<int>());
    
    int s = 0, e = 1000000000, mid;
    while(s<=e) {
        mid = (s+e)/2;
        int count = 1, wifi_pos = 1;
        for(i=2;i<=N;i++) {
            if (Arr[i] - Arr[wifi_pos] >= mid) {
                wifi_pos = i;
                count ++;
            }
        }
        if (count < C) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    fprintf(fout,"%d", e);
    return 0;
}
