/*
*    syxm1
*    simple math.
*/

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

void test_case() 
{
    int n, k1, k2, w, b;
    cin >> n >> k1 >> k2 >> w >> b;

    int W = min(k1, k2) + abs(k1 - k2) / 2;
    int B = min(n-k1, n-k2) + abs(n-k1 - (n-k2)) / 2;

    cout << (w <= W && b <= B ? "YES\n" : "NO\n");
}

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;

    while (tc--) {
        test_case();
    }
}
