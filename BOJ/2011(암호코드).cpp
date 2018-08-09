#include<stdio.h>
#include<string.h>
#define mod 1000000

char str[5005];
int v[5005], d[5005];

int main() {
	scanf("%s", str);
	int n = strlen(str);
	for (int i = 1; i <= n; i++) v[i] = str[i - 1] - '0';

	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (v[i] != 0)		d[i] = d[i - 1];
		if (v[i - 1] * 10 + v[i] <= 26 && v[i - 1] != 0) d[i] += d[i - 2];
		d[i] %= mod;
	}

	printf("%d", d[n]);
	return 0;
}