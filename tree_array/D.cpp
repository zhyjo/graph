#include<iostream>
#include<cstdio>
#include<cstring>
using namespace  std;
#define L u<<1, l, mid
#define R u<<1|1, mid+1, r

const int MAXN = 100005;
int tree[MAXN*3]; 
int vis[MAXN*3];
int N;

void build(int u, int l, int r) {
	vis[u] = 0;
	if(l == r) {
		tree[u] = 1;
		return;
	}
	int mid = (l+r)>>1;
	build(L), build(R);
	tree[u] = tree[u<<1] + tree[u<<1|1];
}

void pushdown(int u, int l, int r) {
	if(vis[u]) {
		int mid = (l+r)>>1;
		int x = vis[u];
		tree[u<<1] = x*(mid-l+1), vis[u<<1] = x;
		tree[u<<1|1] = x*(r-mid), vis[u<<1|1] = x;
		vis[u] = 0;			
	}
}


void update(int u, int l, int r, int ul, int ur, int val) {
	if(ul > r || ur < l) return ;
	if(l >= ul && r <= ur) {
		vis[u] = val;
		tree[u] = val*(r-l+1);
		return;
	}
	pushdown(u, l, r);
	int mid = (l+r)>>1;
	update(L, ul, ur, val);
	update(R, ul, ur, val);	
	tree[u] = tree[u<<1] + tree[u<<1|1];	
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++) {
		int Q;
		cin >> N >> Q;
		build(1, 1, N);

		while(Q--) {
			int x, y, z; cin >> x >> y >> z;
			update(1, 1, N, x, y, z);
		}
		cout << "Case " << i <<  ": The total value of the hook is " << tree[1] << "." << endl;
	}	
}




