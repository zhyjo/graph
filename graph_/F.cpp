#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 1005;
const int INF = 1000000000;

int d[MAXN], cost[MAXN][MAXN];
bool used[MAXN];
int V;

void dij(int s) {
	for(int i = 0; i <= V; i++) {
		d[i] = INF;
		used[i] = false;
	}

	d[s] = 0;
	while(true) {
		int v = -1;

		for(int u = 0; u <= V; u++) {
			if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}

		if(v == -1) break;
		used[v] = true;

		for(int u = 0; u <= V; u++) {
			if(cost[v][u] != -1)
				d[u] = min(d[u], d[v] + cost[v][u]);
		}
	}
}


int main() {
	int T, S, D;
	int maxi = 0;
	while(cin >> T >> S >> D) {
		memset(cost, -1, sizeof(cost));
		for(int i = 0; i < T; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			maxi = max(maxi, max(x, y));
			if(cost[x][y] == -1 || cost[y][x] > z)
			cost[x][y] = cost[y][x] = z;	
		}
		while(S--) {
			int x;
			cin >> x;
			maxi = max(maxi, x);
			cost[0][x] = cost[x][0] = 0;	
		}
		V = maxi;
		dij(0);
		int minx = INF;
		for(int i = 0; i < D; i++) {
			int x;
			cin >> x;
			minx = min(minx, d[x]);
		}
		cout << minx << endl;
	       	
	}
}
