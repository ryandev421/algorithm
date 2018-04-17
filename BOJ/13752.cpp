#include <stdio.h>

int main()
{
    int i,n,s;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&s);
        for(int j=1;j<=s;j++){
            printf("=");
        }
        printf("\n");
    }
    return 0;
}
