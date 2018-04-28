#include <stdio.h>
#include <string.h>

FILE *fin = stdin;
FILE *fout = stdout;

int main()
{
    char s[105];
    int len, i;
    int ans = 0;

    fscanf(fin,"%s",&s);
    len = (int)strlen(s);

    for(i=0;i<len;i++) {
        if (s[i]=='c') {
            if (s[i+1]=='=' || s[i+1]=='-'){
                ans++;
                i++;
                continue;
            }
        } else if (s[i]=='d') {
            if (s[i+1]=='z' && s[i+2]=='='){
                ans++;
                i+=2;
                continue;
            }else if (s[i+1]=='-'){
                ans++;
                i++;
                continue;
            }
        } else if (s[i]=='l') {
            if(s[i+1]=='j') {
                ans++;
                i++;
                continue;
            }
        } else if(s[i]=='n'){
            if (s[i+1]=='j') {
                ans++;
                i++;
                continue;
            }
        } else if(s[i]=='s'){
            if (s[i+1]=='='){
                ans++;
                i++;
                continue;
            }
        } else if(s[i]=='z'){
            if(s[i+1]=='='){
                ans++;
                i++;
                continue;
            }
        } 
        ans++;
    }
    fprintf(fout,"%d",ans);
    return 0;
}
