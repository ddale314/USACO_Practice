#include <bits/stdc++.h>
#define ll long long
using namespace std;

// n nodes, k edges
// the connected barns form a cycle, annabelle and bessie are describing the same cycle
// find longest matching substring (with wraparounds)
// add the number of matching non-connected barns

int lcs(string a, string b, int s) {
	vector<vector<int>> dp(s, vector<int>(s));
	for (int i = 0; i < s; i++) {
		if (a[i] == b[0]) {
			dp[i][0] = 1;
		}
		if (i != 0) {
			dp[i][0] = max(dp[i][0], dp[i - 1][0]);
		}	
	}
	for (int i = 0; i < s; i++) {
		if (a[0] == b[i]) {
			dp[0][i] = 1;
		}
		if (i != 0) {
			dp[0][i] = max(dp[0][i], dp[0][i - 1]);
		}
	}
	for (int i = 1; i < s; i++) {
		for (int j = 1; j < s; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} 
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[s - 1][s - 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;

	vector<bool> annabelleUsed(n+1);
	vector<bool> bessieUsed(n+1);

	string annabelle = "";
	for (int i = 0; i < k; i++) {
		int c; cin >> c;
		annabelle += c;
		annabelleUsed[c] = true;
	}
	annabelle += annabelle[0];

	string bessie = "";
	for (int i = 0; i < k; i++) {
		int c; cin >> c;
		bessie += c;
		bessieUsed[c] = true;
	}
	bessie += bessie[0];
	
	string rev = bessie;
	reverse(rev.begin(), rev.end());

	ll ans = max(lcs(annabelle, bessie, k+1), lcs(annabelle, rev, k+1));

	for (int i = 1; i < n+1; i++) {
		if (!annabelleUsed[i] && !bessieUsed[i]) {
			ans++;
		}
	}

	cout << ans << "\n";

}
