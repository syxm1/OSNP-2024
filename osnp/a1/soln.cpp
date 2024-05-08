#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const string osn[] = {"OSN", "SON", "ONS", "NOS", "SNO", "NSO"};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int n = s.length(), ans = -1, l = 0, id = 0;

	for (int k = 0; k < 6; k++, l = 0, id = 0) {
		for (int i = 0; i < n; i++) {
			if (osn[k][id] == s[i]) {
				l++, id = (id + 1) % 3;
			}
		}
		if (l >= 3) ans = max(ans, l);
	}

	cout << ans << '\n';
}

/*
OSN
NASIONAL
INFORMATIKA
OSNNSONO
*/