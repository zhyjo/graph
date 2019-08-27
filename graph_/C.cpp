//diljkstra 两点最短路径 的模版题
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 300;
const int INF = 3000000;

int cost[MAXN][MAXN];
bool used[MAXN];
int d[MAXN];//从固定点出发到i的最短距离
int V, E;


void dijkstra(int s);
int main() { 
	ios::sync_with_stdio(false);
	while(cin >> V >> E) {
		memset(cost, 0, sizeof(cost));
		for(int i = 0; i < E; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			if(z < cost[x][y] || !cost[x][y])
				cost[x][y] = cost[y][x] = z;
		}
		int S,T;
		cin >> S >> T;
		dijkstra(S);
		if(d[T] == INF) cout << -1 << endl;
		else cout << d[T] << endl;
	}
	return 0;
}

void dijkstra(int s) {
	//初始化
	for(int i = 0; i < V; i++) {
		d[i] = INF;
		used[i] = false;
	}
	d[s] = 0;
	while(true) {
		int v = -1;
		for(int u = 0; u < V; u++) {
			if(!used[u] && (v == -1 || d[u] < d[v])) v = u;

		}
		if(v == -1) break;
		used[v] = true;
		for(int u = 0; u < V; u++) {
			if(cost[v][u])
				d[u] = min(d[u], d[v]+cost[v][u]);
		}
	}

}
