/*
已知一个数串， 0 可以成为任何数， 求 LIS

1 每个数减去它前面的0的个数， 为0预留空间
2 LIS模版，结果加上o的个数
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


const int INF = 1000005;
const int MAXN = 100005;
int dp[MAXN], a[MAXN], c[MAXN], b[MAXN], deq[MAXN];

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int kk = 1;
	while(N--) {
		int M;
		cin >> M;
		int k = 0;
		int c = 0;
		for(int i = 0; i < M; i++) {
			cin >> a[i];
			if(!a[i]) c++;
			else b[k++] = a[i] - c;
		}
		memset(dp, INF, sizeof(dp));
		for(int i = 0; i < k; i++) {
			*lower_bound(dp, dp+k, b[i]) = b[i];
		}
		int ans = lower_bound(dp, dp+k, INF) - dp;
		cout << "Case #" << kk++ << ": " << ans+c << endl;
		
	}
}

