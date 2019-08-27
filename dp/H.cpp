#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 205;
const int INF = 1e8;
int a[MAXN];
int dp[MAXN][MAXN];
int sum[MAXN];
int main() {
	ios::sync_with_stdio(false);
	int N;
	while(cin >> N) {
		sum[0] = 0;
		for(int i = 1; i <= N; i++) {
			cin >> a[i];
			sum[i] = sum[i-1] + a[i];
		}

		//区间dp的循环和背包有区别
		for(int len = 1; len <= N; len++) {
			for(int i = 1; i <= N-len+1; i++) {
				int j = i + len-1;
				if(i == j) 
					dp[i][j] = 0;
				else 
					dp[i][j] = INF;
				for(int k = i; k <= j; k++) {
					dp[i][j] = min(dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1], dp[i][j]);
					//前缀和sum[j]-sum[i-1], 最好从1开始。
				}
			}

		}
		cout  << dp[1][N] << endl;
	}
	return 0;

}
