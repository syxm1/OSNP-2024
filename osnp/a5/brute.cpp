#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

using ll = long long;

ll n, m, k, lo, hi, md, id, lhs, rhs, val = 1e18, ans = 0;
vector<ll> b, g, v;
vector<vector<ll>> adj;

vector<bool> vis;
stack<ll> dfs;

ll f(ll x) {
	ll ret = 0;
	for (ll i : v) {
		ret += abs(i - g[x]);
	}
	return ret;
}

signed main() {
	cin >> n >> m >> k;

	b.resize(n);
	g.resize(m);
	adj.resize(n);
	vis.assign(n, 0);

	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < m; i++) cin >> g[i];
	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	

	sort(all(g));

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			v.clear();

			dfs.push(i);
			v.push_back(b[i]);
			vis[i] = 1;

			while (!dfs.empty()) {
				ll cur = dfs.top();
				dfs.pop();

				for (ll nxt : adj[cur]) {
					if (!vis[nxt]) {
						dfs.push(nxt);
						vis[nxt] = 1;
						v.push_back(b[nxt]);
 					}
				}
			}

			if (m == 1) {
				ans += f(0);
				continue;
			}

			val = 1e18;

			for (int i = 0; i < m; i++) {
				val = min(val, f(i));
			}

			ans += val;
		}
	}

	cout << ans << '\n';
}

/*
tc1:
8 4 6
10 20 30 40 50 60 70 80
30 40 50 60
1 8
2 7
3 5
3 6
5 6
6 8
--
150

tc2:
4 3 0
1 2 13 14
20 10 20
--
24

tc3:

*/