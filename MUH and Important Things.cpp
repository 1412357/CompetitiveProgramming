/*
 * Author: Phan Quang Nguyen
 * email: pqnguyen1996@gmail.com 
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int>  pii;

void traveserVector(vector<pii> &a) {
	for (pii ele : a) {
		cout << ele.second + 1 << ' ';
	}
	cout << '\n';
}

int comparefunc(const void *a, const void *b) {
	pii pa = *(pii*)a;
	pii pb = *(pii*)b;
	return pa.first - pb.first;
}

void input(vector<pii> &a, int &n) {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
}

bool isSatify(vector<pii> &a) {
	int count = 0;
	map<int, int> dub;
	for (pii ele : a)
		if (dub[ele.first] == 0) {
			dub[ele.first] = 1;
		} else {
			count++;
		}
	if (count > 1)
		return true;
	return false;
}

void listResult(vector<pii> &a) {
	int count = 0;
	while (count < 3) {
		for (int i = 0; i < a.size() - 1; i++) 
		if (a[i].first == a[i + 1].first) {
			swap(a[i], a[i + 1]);
			traveserVector(a);
			count++;
			if (count == 3)
				return;
		}
	}
}

int main() {
	/*freopen("input.txt", "rt", stdin);*/
	/*freopen("output.txt", "wt", stdout);*/
	int n;
	vector<pii> a;
	input(a, n);
	qsort(&a[0], a.size(), sizeof(pii), comparefunc);
	if (isSatify(a)) {
		cout << "YES" << endl;
		listResult(a);
	} else {
		cout << "NO" << endl;
	}
	return 0;
}