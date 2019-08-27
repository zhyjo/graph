#include<iostream>
#include<cstdio>
using namespace std;

const int  MAXN = 200;
const int  INF = 1000000000;

int d[MAXN], cost[MAXN][MAXN];
bool used[MAXN];
int V, E;
int prim() {
	for(int i = 1; i <= V; i++) {
		d[i] = INF;
		used[i] = false;
	}
	d[1] = 0;
	int res = 0;
	while(true) {
		int v = -1;
		for(int u = 1; u <= V; u++) {
			if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}
		if(v == -1) break;
		used[v] = true;
		res += d[v];
		for(int u = 1; u <= V; u++) {
			d[u] = min(d[u], cost[v][u]);
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	while(cin >> V, V) {
		int E = V*(V-1)/2;
		for(int i = 0; i < E; i++) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			if(d)
				cost[a][b] = cost[b][a] = 0;
			else 
				cost[a][b] = cost[b][a] = c;
		}
		cout << prim() << endl;
	}
}
