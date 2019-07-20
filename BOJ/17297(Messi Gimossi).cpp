#include<bits/stdc++.h>
using namespace std;

int f[41] = { 6,14 };
string str = "Messi Gimossi ";

int main() {
	int n;	scanf("%d", &n);
	for (int i = 2; i <= 40; i++) f[i] = f[i - 1] + f[i - 2];

	while (1) {
		int idx;
		for (idx = 0; f[idx] <= n; idx++);
		idx--;
		n -= f[idx];
		if (n <= 14) break;
	}

	if (n == 0 || n == 6 || n == 14) cout << "Messi Messi Gimossi";
	else cout << str[n - 1];

	return 0;
}