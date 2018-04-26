#include <stdio.h>
#include <string.h>

FILE *fin = stdin;
FILE *fout = stdout;

int main()
{
    char s[20];
    fscanf(fin,"%s",&s);
    int len = (int)strlen(s);
    int i,ans = 0;
    for(i=0;i<len;i++){
        int num = s[i]-'A';
        if (num >= 22){
            ans += 10;
        } else if (num>=19) {
            ans += 9;
        } else if (num>=15) {
            ans += 8;
        } else if (num>=12) {
            ans += 7;
        } else if (num>=9){
            ans += 6;
        } else if (num>=6){
            ans += 5;
        } else if (num>=3){
            ans += 4;
        } else if(num>=0) {
            ans += 3;
        }
    }
    fprintf(fout,"%d",ans);
    return 0;
}
