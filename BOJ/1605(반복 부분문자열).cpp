#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005

int n, ans, gap;
char str[MAXN];
int group[MAXN], SAgroup[MAXN], SA[MAXN], LCP[MAXN];

const bool cmp(int i, int j) {
	if (group[i] != group[j]) return group[i] < group[j];
	return group[i + gap] < group[j + gap];
}

void getSuffixArray() {
	for (int i = 0; i < n; i++) {
		SA[i] = i;
		group[i] = str[i];
	}

	gap = 1;
	while (gap < n) {
		sort(SA, SA + n, cmp);

		for (int i = 1; i < n; i++)
			SAgroup[i] = SAgroup[i - 1] + cmp(SA[i - 1], SA[i]);

		for (int i = 0; i < n; i++)
			group[SA[i]] = SAgroup[i];

		if (SAgroup[n - 1] == n - 1) break;

		gap *= 2;
	}
}

void getLCPArray() {
	for (int i = 0, k = 0; i < n; i++) {
		if (!group[i]) LCP[group[i]] = 0;
		else {
			for (int j = SA[group[i] - 1]; str[i + k] == str[j + k]; k++);

			LCP[group[i]] = k;
			ans = max(ans, k);
			k = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	scanf("%s", str);

	getSuffixArray();
	getLCPArray();

	printf("%d", ans);

	return 0;
}