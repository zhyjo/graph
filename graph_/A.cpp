//已知N个点的联通情况，无向，求还需多少条路可以实现畅通

// 1 并查集的模版题

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 100000;
int father[MAXN];
int root[MAXN];

int find(int i);
void unit(int a, int b);
int main() {
	ios::sync_with_stdio(false);
	int N, M;
	while(cin >> N, N) {
		cin >> M;
		//init
		for(int i = 1; i <= N; i++) father[i] = i; //注意初始化的边界
		for(int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			unit(x, y);
		}
		int c = 0;
		memset(root, 0, sizeof(root));
		for(int i = 1; i <= N; i++) {
			root[find(i)] = 1;
		}
		for(int i = 1; i <= N; i++) {
			if(root[i]) c++;
		}

		cout << c-1 << endl;
	}
}

int find(int i) {
	int r = i;
	while(r != father[r]) {
		r = father[r];
	}

	//路径压缩
	int a = i, b;
	while(father[i] != r) {
		b = father[a];
		father[a] = r;
		a = b;
	}
	return r;
}

void unit(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	if(fa != fb) 
		father[fa] = fb;
}
