#include<bits/stdc++.h>
using namespace std;

bool prime(int x) {
	if (x == 1) return false;
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}

bool pal(int x) {
	string str = "";
	while (x) str += (x % 10) + '0', x /= 10;

	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - 1 - i]) return false;
	}
	return true;
}

int main() {
	int n;	scanf("%d", &n);

	for (int i = n;; i++) {
		if (prime(i) && pal(i)) {
			printf("%d", i);	return 0;
		}
	}

	return 0;
}