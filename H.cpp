#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 300;
const int INF = 1000000;
bool used[MAXN], map[MAXN][MAXN];
int match[MAXN];
int m, n;


//一个最大匹配的优化版。
bool dfs(int u) {
	for(int i = 1; i < n+m; i++) {//这里邻接矩阵 比 邻接表 会有浪费
		if(!used[i] && map[u][i]) {
			used[i] = true;
			//暂时没有和他匹配的 || 让原来和他匹配的那个点重新找一个
			//之所以可以重新，是因为这个点used已经标记，不会再找上他了
			if(match[i] == -1 || dfs(match[i])) {
				match[i] = u;
				return true;

			}
	
		}
	}
	return false;
}



int main() {
	while(cin >> n, n) {
		memset(match, -1, sizeof(match));
		memset(map, false, sizeof(map));
		int k;
		cin >> m >> k;
		for(int i = 0; i < k; i++) {
			int temp, x, y;
			cin >> temp >> x >> y;//读入边
			if(!x || !y) continue;
			map[x][y+n] = true; //邻接矩阵存储
			
		}
		int ans = 0;
		//所有边的端点都保证属于1-n的顶点集，只要计算1-n个顶点的最大匹配
		//每次dfs都是在原来找到的匹配基础上进行的优化
		//本质类似于匈牙利算法
		for(int i = 1; i < n; i++) {
			memset(used, false, sizeof(used));
			if(dfs(i)) ans++;
		}
		cout << ans << endl;
	}
}
