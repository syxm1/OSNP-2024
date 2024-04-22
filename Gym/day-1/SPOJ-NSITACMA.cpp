#include<bits/stdc++.h>
using namespace std;

void tc() {
	int n;
	cin >> n;

	int ans = 0;

	for (int i = 1; i * i <= n - 1; i++) {
		if ((n - 1) % i == 0) {
			ans++;
			if ((n - 1) / i != i) ans++;
		}
	}

	cout << ans - 1 << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		tc();
	}	
}
