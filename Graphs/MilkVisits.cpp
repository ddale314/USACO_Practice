#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5;
vector<vector<int>> adj(MXN);
vector<int> visited(MXN);
vector<int> comps(MXN);
string breeds;

void dfs(int s, int e, char compt, int c) {
	comps[s] = c;
	visited[s] = true;
	for (auto u : adj[s]) {
		if (u != e && breeds[u] == compt) {
			dfs(u, s, compt, c);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	int n, m; cin >> n >> m;
	cin >> breeds;
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int co = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, -1, breeds[i], co++);
		}
	}

	string ans = "";
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		char c; cin >> c;

		if (comps[a] == comps[b]) {
			ans += (breeds[a] == c ? "1" : "0");
		}
		else {
			ans += "1";
		}
	}

	cout << ans << "\n";

}
