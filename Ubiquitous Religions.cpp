/*
 * Author: Phan Quang Nguyen
 * email: pqnguyen1996@gmail.com 
 */

#include <bits/stdc++.h>

using namespace std;

//typedef long long ll;
//typedef pair<int, int>  pii;

int findParent(vector<int> &parent, int v) {
	if (parent[v] != -1) {
		parent[v] = findParent(parent, parent[v]);
		return parent[v];
	}
	return v;
}

void unionSet(vector<int> &parent, int u, int v) {
	int parentU = findParent(parent, u);
	int parentV = findParent(parent, v);
	if (parentU != parentV) {
		if (parentU > parentV) {
			parent[parentV] = parentU;
		} else 
			parent[parentU] = parentV;
	}
}

int solve(int n, int m) {
	int u, v;
	vector<int> parent;
	parent.resize(n, -1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		unionSet(parent, u - 1, v - 1);
	}

	int count = 0;
	for (int ele : parent)
		if (ele == -1)
			count++;
	return count;
}

int main() {
	ios::sync_with_stdio(false);
	/*freopen("input.txt", "rt", stdin);*/
	/*freopen("output.txt", "wt", stdout);*/
	int n, m;
	int i = 1;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		int res = solve(n, m);
		printf("Case %d: %d\n", i, res);
		i++;
	}
	return 0;
}