#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5;
vector<vector<int>> adj(MXN);
int ans = 0;

int mult(int n) {
	if (n == 0) {
		return 0;
	}
	int log = __lg(n);
	if (1 << log != n) {
		log++;
	}
	return log;
}

void dfs(int s, int e) {
	if (s == 0) {
		ans += mult(adj[s].size()+1);
	}
	else {
		ans += mult(adj[s].size());
	}
	for (auto u : adj[s]) {
		if (u != e) {
			dfs(u, s);
			ans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0, -1);
	cout << ans << "\n";
}