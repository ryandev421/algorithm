#include <stdio.h>

FILE *fin = stdin;
FILE *fout = stdout;

int main()
{
    int t,p;
    fscanf(fin,"%d", &t);
    for (p = 1; p <= t; p++) {
        int n;
        int arr[1001] = {0};
        int sum = 0;
        int i;

        fscanf(fin,"%d", &n);
        for (i = 1; i <= n; i++) {
            fscanf(fin, "%d", &arr[i]);
            sum += arr[i];
        }
        double avg = (double)sum/n;
        int count = 0;
        for (i = 1; i <= n; i++) {
            if (avg < arr[i]) count++;
        }
        fprintf(fout, "%.3lf%%\n", double(count)/n*100);
    }

    return 0;
}
