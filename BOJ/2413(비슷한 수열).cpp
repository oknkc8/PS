#include<bits/stdc++.h>
using namespace std;

int n, v[50005], c[50005], flag;
bool check[50005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		c[v[i]] = i;
	}
	c[0] = -1;

	for (int i = 0; i < n; i++) {
		if (c[v[i]] < c[v[i] - 1] && !check[v[i]] && !check[v[i] - 1]) {
			check[v[i]] = check[v[i] - 1] = 1;
			swap(v[c[v[i]]], v[c[v[i] - 1]]);
		}
		printf("%d ", v[i]);
	}

	return 0;
}