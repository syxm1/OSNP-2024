#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

signed main() {
	int n = 5, m = 15, k = 0;
	cout << n << ' ' << m << ' ' << k << '\n';
	for (int i = 0; i < n; i++) cout << rand(1, 10) << ' '; cout << '\n';
	for (int i = 0; i < m; i++) cout << rand(1, 10) << ' '; cout << '\n';
}