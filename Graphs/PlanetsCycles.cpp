#include <bits/stdc++.h>
using namespace std;

// If an item is part of a cycle, return the length of the cycle
// Otherwise, return the length of the nearest cycle + the distance to the first element
// of that cycle (the node will be connected to only 1 cycle)

const int MXN = 2e5;
vector<int> p;
vector<bool> visited(MXN);
vector<int> pathlength(MXN);
int steps = 0;
queue<int> path;

void dfs(int n) {
	path.push(n);
	if (visited[n]) {
		steps += pathlength[n];
		return;
	}
	visited[n] = true;
	steps++;
	dfs(p[n]);
}

 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	p = vector<int>(n);
	for (int &i : p) {
		cin >> i;
		i--;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			steps = 0;
			dfs(i);
			int dec = 1;

			while (!path.empty()) {
				if (path.front() == path.back()) {
					dec = 0;
				}
				pathlength[path.front()] = steps;
				steps -= dec;
				path.pop();
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << pathlength[i] << " ";
	}
	cout << "\n";	
}
