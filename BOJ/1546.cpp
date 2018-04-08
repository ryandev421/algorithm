#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <limits.h>
#include <math.h>
#include <stack>
#define MAX 1005

using namespace std;

FILE *fin = stdin;
FILE *fout = stdout;

int N;
int Arr[MAX];
int Max;
int Sum;

void Input()
{
	int i;
	fscanf(fin, "%d", &N);
	for (i = 1; i <= N; i++) {
		fscanf(fin, "%d", &Arr[i]);
		Max = max(Max, Arr[i]);
		Sum += Arr[i];
	}
}

void Output()
{
	char ans[MAX];
	sprintf(ans, "%.3lf", (double)Sum / Max * 100 / N);
	int len = strlen(ans);
	ans[len - 1] = '\0';
	fprintf(fout, "%s", ans);
}

int main()
{
	Input();
	Output();
	return 0;
}
