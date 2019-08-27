#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 2005;
const int INF = 1e8;

int dp[MAXN][MAXN], sum[MAXN], vis[MAXN][MAXN], a[MAXN];

int main() {
	int N;
	ios::sync_with_stdio(false);
	sum[0] = 0;
	while(cin >> N) {
		//模拟为长度为2*N的一维串
		for(int i = 1; i <= N; i++) {
			cin >> a[i];
			a[i+N] = a[i];
			dp[i][i] = dp[i+N][i+N] = 0;
			vis[i][i] = i;
			vis[i+N][i+N] = i+N;
		}
		for(int i = 1; i <= N*2; i++) {
			sum[i] = sum[i-1]+a[i];
			
		}
		for(int len = 2; len <= N; len++) {
			for(int i = 1; i + len -1 <= N*2; i++) {
				int j = i + len -1;
				dp[i][j] = INF;
				for(int k = vis[i][j-1]; k <=vis[i+1][j]; k++) {
					int temp = dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
					if(temp < dp[i][j]){
						dp[i][j] = temp;
						vis[i][j] = k;
					}
				}
			}
		}
		int ans = INF;
		for(int i = 1; i <= N; i++) {
			ans = min(ans, dp[i][i+N-1]);
		}
		cout << ans << endl;
	}
}

//难点：四边形不等式，s[i][j] = k; s[i][j-1] >= s[i][j] >= s[i+1][j]

