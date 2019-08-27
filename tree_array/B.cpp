#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

const int MAXN = 500005;
int a[MAXN];
int tree[MAXN];

struct node{
	int val,pos;
}p[MAXN];

bool cmp(node a, node b) {
	return a.val < b.val;
}

void add(int k, int val, int len) {
	while(k <= len) {
		tree[k] += val;
		k += k&-k;
	}
} 

int read(int k) {
	int sum = 0;
	while(k >= 1) {
		sum += tree[k];
		k -= k&-k;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	int N;
	while(cin >> N, N) {
		for(int i = 1; i <= N ;i++) {
			cin >> p[i].val;
			p[i].pos = i;
		}
		//离散化
		sort(p+1, p+N+1, cmp);
		for(int i = 1; i <= N; i++) a[p[i].pos] = i;

		memset(tree, 0, sizeof(tree));
		long long sum = 0;
		for(int i = 1; i <= N; i++) {
			add(a[i], 1, N);
			sum += (i-read(a[i]));
		}
		cout << sum << endl;
	}	
	return 0;

}


