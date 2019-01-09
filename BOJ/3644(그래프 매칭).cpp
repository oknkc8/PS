#include<bits/stdc++.h>
using namespace std;

vector<int> v[10001];

void add(int idx, int idx1, int idx2) {
	int l1 = v[idx1].size() , l2 = v[idx2].size(), r = 0;
	vector<int> ret;
	for (int i = l1 - 1, j = l2 - 1; i >= 0; i--, j--) {
		if (j >= 0) {
			int t = v[idx1][i] + v[idx2][j] + r;
			r = t / 10;
			ret.push_back(t % 10);
		}
		else {
			int t = v[idx1][i] + r;
			r = t / 10;
			ret.push_back(t % 10);
		}
	}
	if (r) ret.push_back(r);

	int cc = 0;
	for (int i = ret.size() - 1; i >= 0; i--) v[idx].push_back(ret[i]);
}

void init() {
	v[1].resize(1), v[2].resize(1);
	v[1][0] = 1, v[2][0] = 3;
	for (int i = 3; i <= 10000; i++) {
		add(i, i - 1, i - 2);
	}
}

int main() {
	init();
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < v[n].size(); i++) printf("%d", v[n][i]);
		printf("\n");
	}

	return 0;
}