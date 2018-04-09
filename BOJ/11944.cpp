#include <stdio.h>
#include <string.h>

int main()
{
    int n, m;
    char number[5];
    
    scanf("%d %d", &n,&m);
    sprintf(number, "%d", n);

    int len = strlen(number);
    int i;
    for(i=1;i<=n;i++) {
        if (m-len <= 0) {
            number[m] = '\0';
            printf("%s", number);
            break;
        } else {
            printf("%s", number);
            m -= len;
        }
    }
    return 0;
}
