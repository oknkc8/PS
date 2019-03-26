#include<bits//stdc++.h>
using namespace std;

int min_val(int a, int b) {
	if (a > b) return b;
	return a;
}

int max_val(int a, int b) {
	if (a > b) return a;
	return b;
}

void update_min(vector<int> &tree_min, int node, int start, int end, int index, int val) {
	if (index < start || end < index) return;
	if (start == end) {
		tree_min[node] =  val;
		return;
	}

	update_min(tree_min, node * 2, start, (start + end) / 2, index, val);
	update_min(tree_min, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	tree_min[node] = min(tree_min[node * 2], tree_min[node * 2 + 1]);
}

void update_max(vector<int> &tree_max, int node, int start, int end, int index, int val) {
	if (index < start || end < index) return;
	if (start == end) {
		tree_max[node] = val;
		return;
	}

	update_max(tree_max, node * 2, start, (start + end) / 2, index, val);
	update_max(tree_max, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	tree_max[node] = max(tree_max[node * 2], tree_max[node * 2 + 1]);
}

int find_min(vector<int> &tree_min, int node, int start, int end, int left, int right) {
	if (right < start || end < left) return 1e7;
	if (left <= start && end <= right) return tree_min[node];

	return min_val(find_min(tree_min, node * 2, start, (start + end) / 2, left, right), find_min(tree_min, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int find_max(vector<int> &tree_max, int node, int start, int end, int left, int right) {
	if (right < start || end < left) return -1;
	if (left <= start && end <= right) return tree_max[node];

	return max_val(find_max(tree_max, node * 2, start, (start + end) / 2, left, right), find_max(tree_max, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main() {
	int T;	scanf("%d", &T);
	while (T--) {
		int n, k;
		scanf("%d%d", &n, &k);

		int h = (int)ceil(log2(n));
		int tree_size = (1 << (h + 1));
		vector<int> tree_min(tree_size, -1), tree_max(tree_size, -1);
		vector<int> c(n, 0);

		for (int i = 0; i < n; i++) {
			update_min(tree_min, 1, 1, n, i + 1, i);
			update_max(tree_max, 1, 1, n, i + 1, i);
			c[i] = i;
		}

		while(k--){
			int q, a, b;	scanf("%d%d%d", &q, &a, &b);
			if (!q) {
				swap(c[a], c[b]);
				update_min(tree_min, 1, 1, n, c[a] + 1, a);
				update_max(tree_max, 1, 1, n, c[a] + 1, a);
				update_min(tree_min, 1, 1, n, c[b] + 1, b);
				update_max(tree_max, 1, 1, n, c[b] + 1, b);
			}
			else {
				int fmin = find_min(tree_min, 1, 1, n, a + 1, b + 1), fmax = find_max(tree_max, 1, 1, n, a + 1, b + 1);
				if (a == fmin && b == fmax) printf("YES\n");
				else printf("NO\n");
			}
		}
	}

	return 0;
}