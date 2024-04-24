// Fun Fibonacci

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 505;

int x, y, m;
ll F[N], f[N][N];

ll solve(int x, int y) {
	if (x <= 0 || y <= 0) return 0;
	else if (f[x][y] != -1) return f[x][y]; 
	else if (x <= y) return f[x][y] = (solve(x - 2, y - 1) + solve(x - 1, y - 2) + F[x]) % m;
	else return f[x][y] = (solve(x - 2, y - 2) + F[y]) % m;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> x >> y >> m;
	
	F[0] = 2;
	F[1] = 3;
	
	for (int i = 2; i < N; i++) {
		F[i] = (F[i-1] + F[i-2]) % m;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			f[i][j] = -1;
		}
	}

	cout << solve(x, y) << '\n';
}
