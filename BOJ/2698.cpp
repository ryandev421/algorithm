#include <stdio.h>
#include <string.h>
#define MAX_N 100

FILE *fin = stdin;
FILE *fout = stdout;

int Dy[MAX_N + 1][MAX_N + 1][2];

void process()
{
	int i, j;
	Dy[2][0][0] = 2;
	Dy[2][0][1] = 1;
	Dy[2][1][0] = 0;
	Dy[2][1][1] = 1;
	
	for (i = 3; i <= MAX_N; i++) {
		Dy[i][0][0] = Dy[i-1][0][0] + Dy[i-1][0][1];
		Dy[i][0][1] = Dy[i - 1][0][0];
		for (j = 1; j <= MAX_N; j++) {
			Dy[i][j][0] = Dy[i - 1][j][0] + Dy[i - 1][j][1];
			Dy[i][j][1] = Dy[i - 1][j][0] + Dy[i - 1][j - 1][1];
		}
	}
}

int main()
{
	process();

	int t, p;
	fscanf(fin, "%d", &t);
	for (p = 1; p <= t; p++) {
		int n, k;
		fscanf(fin, "%d %d", &n, &k);
		fprintf(fout, "%d\n", Dy[n][k][0] + Dy[n][k][1]);
	}
	return 0;
}
