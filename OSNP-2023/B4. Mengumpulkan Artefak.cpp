#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

const int N = 1e5+5;

int n, k, x, l, r, st, ans, gain[N];
vector<pair<int, int>> v;

int val(int lf, int rg) {
    return gain[rg] - gain[lf - 1];
}

int dist(int l, int r) {
    return v[r].fi - v[l].fi;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> x;

    v.resize(n+1);
    v.push_back(make_pair(x, 0LL));

    for (int i = 1; i <= n; i++) cin >> v[i].fi;
    for (int i = 1; i <= n; i++) cin >> v[i].se;

    sort(v.begin(), v.end());

    for (int i = 1; i <= n+1; i++) {
        gain[i] = gain[i - 1] + v[i].se;
        if (v[i] == make_pair(x, 0LL)) st = i;
    }

    for (l = r = 1; l <= st; l++, r = max(l, r)) {
        if (dist(l, st) > k) continue;
        while (r + 1 <= n + 1 && dist(l, st) + dist(l, r + 1) <= k) r++;
        ans = max(ans, val(l, max(st, r)));
    }

    for (l = r = n + 1; r >= st; r--, l = min(l, r)) {
        if (dist(st, r) > k) continue;
        while (l - 1 > 0 && dist(st, r) + dist(l - 1, r) <= k) l--;
        ans = max(ans, val(min(st, l), r));
    }

    cout << ans << '\n';
}
