#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define F(i, a, b) for(int i = a; i < b; i++)

int c[6];
int dp[500000];
int num;
int sum;
int k = 1;

int main() {
	//ios_base::sync_with_stdio(false);
	while(1) {
		//init
		num = sum = 0;
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;

		F(i, 0, 6) {
			cin >> c[i];
			sum += c[i] * (i+1);
			num += c[i];
		}
		if(!num) break;
		//剪枝
		cout << "Collection #" << k++ << ":" << endl;
		if(sum%2) {
			cout << "Can't be divided." << endl << endl;
			continue;
		}
		//dp[i+1][j] = after used i , if made up the j ,the value is number of resting the c[i], otherwise is -1
		//----> c[i] (dp[i][j] >= 0)
		//----> -1 (dp[i][j-a[i]] < 0 || j < a[i])
		//----> dp[i][j-i+1] - 1 (otherwise)
		F(i, 0, 6) {
			F(j, 0, sum/2+1) {
				if(dp[j] >= 0) dp[j] = c[i];
				else if(j < i+1 || dp[j-(i+1)] <= 0) dp[j] = -1;
				else dp[j] = dp[j-(i+1)]-1;
				
			}
			//F(i, 0, sum/2) cout << dp[i] << " ";
			//cout << endl;
		}
		if(dp[sum/2] >= 0) cout << "Can be divided." << endl << endl;
		else cout << "Can't be divided." << endl << endl;
	}
	return 0;
}
