#include<bits/stdc++.h>
using namespace std;

int main() {
	double h, v;	scanf("%lf%lf", &h, &v);
	double a, b, c, d, e;
	a = sqrt(h*h + v * v);
	b = (a - h)*h / v;
	c = sqrt(h*h + b * b);
	d = h / c;
	e = (v - b)*d;
	printf("%.2lf %.2lf", c / 2.0, e);

	return 0;
}