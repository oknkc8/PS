#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;	scanf("%d", &n);
	vector<int> v1, v2, v3;
	for (int i = 0; i < n; i++) {
		int a;	scanf("%d", &a);
		if (a < 0) v1.push_back(a);
		else if (a == 0) v2.push_back(a);
		else v3.push_back(a);
	}
	sort(v1.begin(), v1.end());
	sort(v3.begin(), v3.end());

	if (v1.size() == 0 || v1.size() == 1) {
		if (v3.size() <= 1)	printf("0");
		else if (v3.size() == 2) printf("%d", v3[0] * v3[1]);
		else printf("%d", v3[v3.size() - 1] * v3[v3.size() - 2] * v3[v3.size() - 3]);
	}
	else {
		if (v3.size() == 0) printf("%d", v1[0] * v1[1]);
		else printf("%d", max(v1[0] * v1[1] * v3[v3.size() - 1], v3[v3.size() - 1] * v3[v3.size() - 2] * v3[v3.size() - 3]));
	}

	return 0;
}