//最小生成树
//
//1 判断是否为联通图可以通过顶点和边得出
//2 prim 保证为联通图
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN = 250;
const int INF = 100000000;
double cost[MAXN][MAXN], d[MAXN];
bool used[MAXN];
int V;

struct coo {
	double x, y;
}map[MAXN];

double length(coo a, coo b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y-b.y)*(a.y-b.y));

}
//一个标准的prim版,如果不确定是联通图，则可以在外面判定
double prim() {
	//初始化
	for(int i = 1; i <= V; i++) {
		d[i] = INF;
		used[i] = false;
	}
	d[1] = 0;
	double res = 0;
	while(true) {
		int v = -1;//作用为每次第一个不再X里的顶点作初值进行比较
			for(int u = 1;  u <= V; u++) {
			if(!used[u] && (v == -1 || d[u] < d[v]))  v = u;			
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
	int T;
	cin >> T;
	while(T--) {
		int c = 0;
		cin >> V;
		for(int i = 1; i <= V; i++) {
			int x, y;
			cin >> x >> y;
			map[i].x = x;
			map[i].y = y;
		}

		for(int i = 1; i <= V; i++) {
			for(int j = 1; j <= V; j++) {
				if(i == j) cost[i][j] = 0;
				else {
					double temp = length(map[i], map[j]);
					if(temp <= 1000 && temp >= 10) {
						cost[i][j] = temp;
						c++;
					}
					else 
						cost[i][j] = INF;
				}
			}
		}
		//判断图是否联通
		if(c < V-1) 	printf("oh!\n");
		else 
			printf("%.1f\n",prim()*100);
	}
	return 0;
}
