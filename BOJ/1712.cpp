#include <stdio.h>

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if (c-b<=0) printf("-1");
    else {
        int num = a/(c-b)+1;
        printf("%d",num);
    }
    return 0;
}
