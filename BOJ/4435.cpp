#include <stdio.h>

int A[6]= {1, 2, 3, 3, 4, 10};
int B[7]= {1,2,2,2,3,5,10};

int main()
{
    int t, p;
    scanf("%d",&t);
    for(p=1;p<=t;p++) {
        int i;
        int sum1 = 0, sum2 = 0;
        int num;
        for(i=0;i<6;i++){
            scanf("%d",&num);
            sum1 += A[i]*num;
        }
        for(i=0;i<7;i++){
            scanf("%d",&num);
            sum2 += B[i]*num;
        }
        printf("Battle %d: ", p);
        if (sum1 > sum2) {
            printf("Good triumphs over Evil\n");
        } else if (sum1 < sum2) {
            printf("Evil eradicates all trace of Good\n");
        } else {
            printf("No victor on this battle field\n");
        }
    }
    return 0;
}
