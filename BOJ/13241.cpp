#include <stdio.h>

long long getGCD(long long a, long long b)
{
    if (a%b==0) return b;
    else return getGCD(b, a%b);
}
int main()
{
    long long a, b, gcd;
   
    scanf("%lld%lld",&a,&b);
    gcd = getGCD(a, b);
    printf("%lld", a*b/gcd);
    return 0;
}
