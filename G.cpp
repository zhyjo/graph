#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

struct edge {
	int to, cap, rev;
};
const int MAXN = 1100;
const int INF =  0x3f3f3f3f;

vector<edge> G[MAXN];
bool used[MAXN];

//邻接表存图，注意反向边的在邻接表中的存储方法
void add_edge(int from, int to, int cap) {
	G[from].push_back((edge){to, cap,(int) G[to].size()});
	G[to].push_back((edge){from, 0, (int)G[from].size()-1});//反向边的初始容量为0
}

int dfs(int v, int t, int f) {
	if(v == t) return f;//找到终点，返回最后的流量
	used[v] = true;//标记这里更方便，第一个元素无需初始化
	for(int i = 0; i < (int)G[v].size(); i++) {
		edge &e = G[v][i];
		if(!used[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));//将当前最大流沿该路径递归
			if(d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t) {
	int flow = 0;
	for(;;) {
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, INF);//每次只找一条路，修改容量，直至最后一次找到的最大流为0
		if(f == 0) break;
		flow += f;
	}
	return flow;
}


int main() {
	ios::sync_with_stdio(false);
	int E, V;
	while(cin >> E >> V) {
		for(int i = 1; i <= V; i++) G[i].clear();
		while(E--) {
			int x, y, z;
			cin >> x >> y >> z;
			add_edge(x, y, z);
		}
		cout << max_flow(1, V) << endl;
	}
	return 0;
}



