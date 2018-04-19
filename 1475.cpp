#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <limits.h>
#include <math.h>
#include <queue>
#define MAX 400005

using namespace std;

FILE *fin = stdin;
FILE *fout = stdout;

int N;
int Arr[10];
int Ans;

void Input()
{
	fscanf(fin, "%d", &N);
}

void Process()
{
	int i;
	while (N > 0) {
		Arr[N % 10]++;
		N /= 10;
	}
	for (i = 0; i <= 9; i++) {
		int num = Arr[i];
		if (i == 6 || i == 9) {
            num = Arr[6] + Arr[9];
            if (num%2==1) num = num/2 +1;
            else num /= 2;
		}
		Ans = std::max(Ans, num);
	}
}

void Output()
{
	fprintf(fout, "%d", Ans);
}

int main()
{
	int t, p;

	//    fscanf(fin,"%d",&t);
	t = 1;
	for (p = 1; p <= t; p++) {
		Input();
		Process();
		Output();
	}
	return 0;
}
