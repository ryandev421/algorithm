#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <functional>
#define MAX_N 500000

int N;
int Arr[MAX_N+1];

int main()
{
    int i;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        scanf("%d",&Arr[i]);
    std::sort(Arr+1,Arr+1+N, std::less<int>());

    int sum = 0;
    for(i=1;i<=N;i++){
        sum += Arr[i];
    }
    printf("%d\n",(int)round(double(sum)/N));
    printf("%d\n",Arr[N/2+1]);
    int num1, num2=-1, max=0, count=0;
    for(i=1;i<=N;i++) {
        if(Arr[i-1] != Arr[i]) {
            if (max < count) {
                max = count;
                num1 = Arr[i-1];
                num2 = -1;
            } else if (max == count){
                if (num2==-1) {
                    num2= num1;
                    num1 = Arr[i-1];
                }
            }
            count = 1;
        } else {
            count++;
        }
    }
    if (max < count) {
        num1 = Arr[i-1];
    } else if (max == count) {
       if (num2 == -1) {
           num1 = Arr[i-1];
       }
    }
    printf("%d\n", num1);
    printf("%d\n", Arr[N]- Arr[1]);
    return 0;
}
