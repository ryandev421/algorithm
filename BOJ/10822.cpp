#include <stdio.h>

int main()
{
    char s[101];
    scanf("%s", s);

    int index = 0;
    int num = 0;
    int sum = 0;
    while(s[index] != '\0') {
        if (s[index] == ',') {
            sum += num;
            num = 0;
        }else {
            num = num*10 + s[index] - '0';
        }
        index++;
    }
    sum+=num;
    printf("%d",sum);
    return 0;
}
