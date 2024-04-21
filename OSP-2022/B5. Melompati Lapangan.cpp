#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define dbg(x) cerr << #x << " : " << x << '\n' 

const int mod = 1e9+7;

signed main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	ll dp[n+5][m+5], suff[n+5][m+5];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			suff[i][j] = 0;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (i == n-1 && j == m-1) {
				dp[i][j] = 1;
				suff[i][j] = 1;
				continue;
			}

			suff[i][j] = (suff[i+1][j] + suff[i][j+1] - suff[i+1][j+1]) % mod;
			
			int k = min(i + a[i][j] + 1, n), l = min(j + a[i][j] + 1, m);
			dp[i][j] = (suff[i][j] - suff[k][j] - suff[i][l] + suff[k][l]) % mod;
			suff[i][j] = (suff[i][j] + dp[i][j]) % mod;

			if (dp[i][j] < 0) dp[i][j] += mod;
			if (suff[i][j] < 0) suff[i][j] += mod;
		}
	}

	cout << dp[0][0] << '\n';
}
