#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 50005
struct node{
	int min;
	int max;
}tree[MAXN*3];
int s[MAXN];

void build(int root, int l, int r) {
	if(l == r) {
		tree[root].min = tree[root].max = s[l];

	}
	else {
		int mid = (l+r)/2;
		build(root*2+1, l, mid);
		build(root*2+2, mid+1, r);
		tree[root].min = min(tree[root*2+1].min, tree[root*2+2].min);
		tree[root].max = max(tree[root*2+1].max, tree[root*2+2].max);

	}
}

int query1(int root, int nl, int nr, int ql, int qr) {
	if(ql > nr || qr < nl) {
		return 1000000;
	}
	if(ql <= nl && qr >= nr) return tree[root].min;
	int mid = (nl+nr)/2;
	int ans1 = query1(root*2+1, nl, mid, ql, qr);
	int ans2 = query1(root*2+2, mid+1, nr, ql, qr);
	return min(ans1, ans2);
}

int query2(int root, int nl, int nr, int ql, int qr) {
	if(ql > nr || qr < nl) {
		return -1;
	}
	if(ql <= nl && qr >= nr) return tree[root].max;
	int mid = (nl+nr)/2;
	int ans1 = query2(root*2+1, nl, mid, ql, qr);
	int ans2 = query2(root*2+2, mid+1, nr, ql, qr);
	return max(ans1, ans2);
}

int main() {
	int M, N;
	ios_base::sync_with_stdio(false);
	cin >> M >> N;
	for(int i = 0; i < M; i++) {
		cin >> s[i];
	}
	build(0, 0, M-1);
	for(int i = 0; i < N; i++) {
		int l ,r;
		cin >> l >> r;
		cout << query2(0, 0, M-1, l-1, r-1) - query1(0, 0, M-1, l-1, r-1) << endl;
	}
	return 0;

}
