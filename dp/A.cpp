#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define MAXN 50005

int Max[MAXN][30];
int Min[MAXN][30];
int a[MAXN];
int M, N;

void RMQ();

int main() {
	ios_base::sync_with_stdio(false);
	cin >> M >> N;
	for(int i= 1; i <= M; i++) {
		int x;
		cin >> x;
		Max[i][0] = Min[i][0] = x;
	}
	RMQ();

	for(int i = 0; i < N; i++) {
		int l, r;
		cin >> l >> r;
		int k = floor(log(r-l+1)/log(2));
		int nmin = min(Min[l][k], Min[r-(1<<k)+1][k]);
		int nmax = max(Max[l][k], Max[r-(1<<k)+1][k]);
		cout << nmax-nmin << endl;
	}	
	return 0;
}


void RMQ() {
	for(int j = 1; (1<<j) <= M; j++) {
		for(int i = 1; i+(1 << j)-1 <= M; i++) {
			Max[i][j] = max(Max[i][j-1], Max[i + (1 << (j-1))][j-1]);
			Min[i][j] = min(Min[i][j-1], Min[i + (1 << (j-1))][j-1]);
			
		}		
	}
}

