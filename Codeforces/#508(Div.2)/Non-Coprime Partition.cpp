#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;	cin >> n;
	if (n == 1 || n == 2) printf("No");
	else {
		printf("Yes\n");
		if (n % 2) {
			printf("%d", n / 2);
			for (int i = 2; i <= n; i += 2) printf(" %d", i);
			printf("\n%d", n / 2 + 1);
			for (int i = 1; i <= n; i += 2) printf(" %d", i);
		}
		else {
			printf("%d ", n / 2);
			for (int i = 1; i <= n; i += 2) printf("%d ", i);
			printf("\n%d ", n / 2);
			for (int i = 2; i <= n; i += 2) printf("%d ", i);
		}
	}

	return 0;
}