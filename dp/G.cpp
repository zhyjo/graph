/*
已知一个二维数组，求最长连续上升子序列

1 最长连续上升子序列（贪心）
2 函数 dp 改成 dfs 
3 数组 vis 改成 dp 
4 dp 或者 单调队列 解决 LIS ， 连续的LIS ，一维 可以直接贪心，二维 dfs

*/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define MAXN 10000

int map[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int M, N;
int dp(int x, int y);
int is_inside(int x, int y);

int main() {
	cin >> M >> N;
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			ans = max (ans , dp(i, j));
		}
	}
	cout << ans << endl;
	return 0;
}

int dp(int x, int y) {
	int ms = 0;
	if(vis[x][y] != 0) {
		return vis[x][y];
	}
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(is_inside(nx, ny) && map[x][y] > map[nx][ny]) {
			int s = dp(nx, ny);
			ms = max(ms, s);
		}
	}
	vis[x][y] = ms+1;
	return ms+1;

}


int is_inside(int x, int y) {
	if(x >= 0 && x < M && y >= 0 && y < N) return 1;
	return 0;
}

