#include<bits/stdc++.h>
using namespace std;

vector<int> ta(101), tb(101);

int main() {
	int n;	scanf("%d", &n);
	while (n--) {
		int a, b;	scanf("%d%d", &a, &b);
		ta[a]++, tb[b]++;

		vector<int> va = ta, vb = tb;
		int ans = 0, idx_a = 1, idx_b = 100;
		while (idx_b > 0 && idx_a <= 100) {
			while (idx_a <= 100 && !va[idx_a]) idx_a++;
			while (idx_b > 0 && !vb[idx_b]) idx_b--;

			if (idx_a > 100 || idx_b == 0) break;

			ans = max(ans, idx_a + idx_b);

			if (va[idx_a] > vb[idx_b]) va[idx_a] -= vb[idx_b], vb[idx_b] = 0;
			else vb[idx_b] -= va[idx_a], va[idx_a] = 0;
		}
		
		printf("%d\n", ans);
	}

	return 0;
}