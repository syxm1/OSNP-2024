#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll b, y;

const int mod = 1e9+7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> b >> y;

	vector<int> v;

	while (y) {
		v.push_back(y % b);
		y /= b;
	}

	reverse(v.begin(), v.end());

	for (int i : v) {
		cout << i << ' ';
	} cout << '\n';
}

/*

*/