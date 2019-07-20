#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int T;	scanf("%d", &T);
	while (T--) {
		int p, m, f, c;	scanf("%d%d%d%d", &p, &m, &f, &c);

		ll ans2 = 0;
		ll co = ((m / p)*c) % f + (((m / p)*c) / f)*c;
		co -= f;
		if (co < 0) printf("0\n");
		else if (co == 0) printf("1\n");
		//else if (!(co % (f - c))) printf("%lld\n", 1 + co / (f - c));
		else printf("%lld\n", 1 + co / (f - c));
		//else printf("%lld\n", 2 + co / (f - c));
	}

	return 0;
}