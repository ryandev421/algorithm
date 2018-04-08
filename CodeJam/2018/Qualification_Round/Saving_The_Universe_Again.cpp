#include <stdio.h>
#include <string.h>
#define MAX_N 10000001

FILE *fin = stdin;
FILE *fout = stdout;

long long D;
int N;
char Pattern[MAX_N];

void input()
{
	fscanf(fin, "%lld %s", &D, &Pattern[1]);
	N = (int)strlen(&Pattern[1]);
}

long long calculate()
{
	long long c = 1, damage = 0;
	int i;
	for (i = 1; i <= N; i++) {
		if (Pattern[i] == 'C') {
			c *= 2;
		}
		else {
			damage += c;
		}
	}
	return damage;
}

int findLastPos()
{
	int i;
	for (i = N; i >= 1; i--) {
		if (Pattern[i] == 'C') continue;
		if (Pattern[i - 1] == 'S' || i == 1) continue;
		return i;
	}

	return -1;
}

int process()
{
	int ans = 0;
	while (1) {
		long long damage = calculate();
		if (damage <= D) {
			return ans;
		}
		else {
			int x = findLastPos();
			if (x != -1) {
				char tmp = Pattern[x];
				Pattern[x] = Pattern[x - 1];
				Pattern[x - 1] = tmp;
				ans++;
			}
			else {
				return -1;
			}
		}
	}
}

int main()
{
	int t, p;
	fscanf(fin, "%d", &t);
	for (p = 1; p <= t; p++) {
		input();
		int res = process();
		if (res == -1) fprintf(fout, "Case #%d: IMPOSSIBLE\n", p);
		else fprintf(fout, "Case #%d: %d\n", p, res);
	}

	return 0;
}
