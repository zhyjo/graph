/*
给一个N*N的包括负数的矩阵，求子矩阵的最大和

1 最大连续子串和（贪心）
2 矩阵压缩（前缀和）
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 200;
int map[MAXN][MAXN];
int dp[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cin >> map[i][j];
			map[i][j] += map[i-1][j];

		}
	}
	int maxn = map[1][1];
	for(int i = 0; i <= N-1; i++)  {
		for(int j = i+1; j <= N; j++) {
			memset(dp, 0, sizeof(dp));	
			for(int k = 1; k <= N; k++) {
				if(dp[k-1] >= 0) dp[k] = dp[k-1] + map[j][k] - map[i][k];
				else dp[k] = map[j][k] - map[i][k];
				if(dp[k] > maxn) maxn = dp[k];
			}
			
		}
	}
	cout  << maxn << endl;
	return 0;
}
