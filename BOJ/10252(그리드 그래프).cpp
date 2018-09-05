#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;	cin >> t; 
	while (t--) {
		int n, m;	cin >> n >> m;
		int x = 0, y = 0;
		printf("1\n");
		if (!(n % 2)) {
			for (int i = 0; i < n; i++) {
				if (i % 2) {
					for (int j = m - 1; j >= 0; j--) printf("(%d,%d)\n", i, j);
				}
				else {
					for (int j = 0; j < m; j++) printf("(%d,%d)\n", i, j);
				}
			}
		}
		else if (!(m % 2)) {
			for (int j = 0; j < m; j++) {
				if (j % 2) {
					for (int i = n - 1; i >= 0; i--) printf("(%d,%d)\n", i, j);
				}
				else {
					for (int i = 0; i < n; i++) printf("(%d,%d)\n", i, j);
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				if (i % 2) printf("(%d,%d)\n(%d,%d)\n", i, 1, i, 0);
				else printf("(%d,%d)\n(%d,%d)\n", i, 0, i, 1);
			}
			for (int j = 2; j < m; j++) {
				if (j % 2) {
					for (int i = 0; i < n; i++) printf("(%d,%d)\n", i, j);
				}
				else {
					for (int i = n - 1; i >= 0; i--) printf("(%d,%d)\n", i, j);
				}
			}
		}
	}

	return 0;
}