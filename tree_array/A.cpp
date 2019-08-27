#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int MAXN = 50005;
int N;
int a[MAXN];
int tree[MAXN * 3];

void build(int root, int l, int r) {
	if(l == r) tree[root] = a[l];
	else {
		int mid = (l+r)/2;
		build(root*2+1, l, mid);
		build(root*2+2, mid+1, r);

		tree[root] = tree[root*2+1] + tree[root*2+2];
	}
}

void update(int root, int l, int r, int index, int val) {
	if(l == r) {
		if(index == l)	{
			tree[root] += val;
		}
	
	
	} 
	else {
		int mid = (l+r)/2;
		if(index <= mid) 
			 update(root*2+1, l, mid, index, val);
		else 
			 update(root*2+2, mid+1, r, index, val);

		tree[root] = tree[root*2+1] + tree[root*2+2];
	}
}


int  query(int root, int nl, int nr, int ql, int qr) {	
	if(ql < nl || qr > nr) return 0;

	if(nl == ql && nr == qr) return tree[root];

	int mid = (nl+nr)/2;
	if(qr <= mid) 
		return query(root*2+1, nl, mid, ql, qr);
	else if(ql > mid) 
		return query(root*2+2, mid+1, nr, ql, qr);
	else 
		return query(root*2+1, nl, mid, ql, mid) + query(root*2+2, mid+1, nr, mid+1, qr);

}





int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++) {
		cout <<  "Case" << i << ":" << endl;
		cin >> N;
		for(int i = 0; i < N; i++) cin >> a[i];
		build(0, 0, N-1);
		string s;
		int x, y;
		while(cin >> s, s != "End") {
			cin >> x >> y;
			x--;
			if(s == "Query") y--, cout << query(0, 0, N-1, x, y) << endl;
			else if(s == "Add") update(0, 0, N-1, x, y);
			else if(s == "Sub") update(0, 0, N-1, x, (-1)*y);
		}
	}
	return 0;
}


