#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 200005;
struct node {
	int pos;
	int val;
}tree[MAXN*4];

int k = 1;

int w, h, n;

void build(int root, int l, int r) {
	if(l == r) {
		tree[root].val = w; //该叶子节点表示的高度剩余的最大值
		tree[root].pos = k++;
	}
	else {
		int mid = (l+r)/2;
		build(root*2+1, l, mid);
		build(root*2+2, mid+1, r);
		tree[root].val = w;
	}
}

//保证一定有一条查询路径
int query(int root, int l, int r, int w) {
	int ans;
	if(l == r) {
		tree[root].val -= w;
		return tree[root].pos;
	}
	else {
		int mid = (l+r)/2;
		//先进入左子树，左子树不满足在选择右子树
		if(tree[root*2+1].val >= w) ans = query(root*2+1, l, mid, w);
		else ans = query(root*2+2, mid+1, r, w);
	}
	//update
	tree[root].val = max(tree[root*2+1].val, tree[root*2+2].val);
	return ans;
	
}

int main() {
	ios::sync_with_stdio(false);
	while(cin >> h >> w >> n) {
		if(h > n) h = n;
		k = 1;
		build(0, 0, h-1);
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cout << (x <= tree[0].val ? query(0, 0, h-1, x) : -1) << endl;
		}
		
	}
}
