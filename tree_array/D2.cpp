#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
#define L u<<1, l, mid
#define R u<<1|1, mid+1, r

const int MAXN = 1e5+5;
int tree[MAXN*3];

void build(int u, int l, int r) {
	tree[u] = 1;
	if(l == r) return;
	int mid = (l+r)>>1;
	build(L); build(R);
}

void update(int u, int l, int r, int ul, int ur, int val) {
	if(ul > r || ur < l) return;
	//当前区间在更新区间里
	if(l >= ul && r <= ur) {
		tree[u] = val;
		return;
	}
	if(tree[u] == val) return;//当前区间无需更新
	int mid = (l+r)>>1;
	//pushdown
	if(tree[u] != -1) {
		tree[u<<1] = tree[u];
		tree[u<<1|1] = tree[u];
		tree[u] = -1;
	}
	update(L, ul, ur, val);
	update(R, ul, ur, val);
}

int query(int u, int l, int r) {
	if(tree[u] != -1) return tree[u]*(r-l+1);
	int mid = (l+r)>>1;
	return query(L) + query(R);
}

int main() {
	int T;
	cin >> T;
	for(int i = 1; i <=T; i++) {
		int N, Q;
		cin >> N >> Q;
		build(1, 1, N);
		while(Q--) {
			int x, y, z; cin >> x >> y >>z;
			update(1, 1, N, x, y, z);
		}
		cout << "Case " << i << ": The total value of the hook is " << query(1, 1, N) << "." << endl;;

	}
	return 0;
}
