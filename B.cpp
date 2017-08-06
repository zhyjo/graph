#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 1000000;
const int MAXN = 1000000;
int mincost[MAXN], cost[MAXN][MAXN];
bool used[MAXN];
int V;

int prim();

int main() {
	ios::sync_with_stdio(false);
	while(cin >> V, V) {
		for(int i = 0; i < V*(V-1)/2; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			cost[x][y] = cost[y][x] = z;
		}
		int ans = prim();
		cout << ans << endl;
	}
	return 0;
}

//保证图为联通图
int prim() {
	//初始化
	for(int i = 1; i <= V; i++) {
		mincost[i] = INF;
	        used[i] = false;	
	}
	//一定是先放第一个顶点，默认的mincost = 0;
	mincost[1] = 0;
	int res  = 0;
	while(true) {
		int v = -1;
		//从不属于集合X里找到离X最近的顶点
		for(int u = 1; u <= V; u++) {
			//在没用过的顶点里找到min（mincost[u])
			if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
			
		}
		if(v == -1) break;//如果所有的顶点都已经被添加，则会跳出while
		used[v] = true;
		res += mincost[v];

		//因为有新的顶点加入到X，所以更新mincost
		for(int u = 1; u <= V; u++) {
			mincost[u] = min(mincost[u], cost[v][u]);
		}
	}
	return res;
}
