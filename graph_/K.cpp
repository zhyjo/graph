#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 305;
const int INF = 0x3f3f3f3f;

bool used1[MAXN], used2[MAXN];
int map[MAXN][MAXN], lx[MAXN], ly[MAXN], match[MAXN], slack[MAXN];
int V;
//匈牙利算法
bool dfs(int v) {
	used1[v] = true;
	for(int i = 0; i < V; i++) {
		int temp = lx[v] + ly[i] - map[v][i];
	        if(used2[i]) continue;
		if(!temp) {
			used2[i] = true;
			if(match[i] == -1 || dfs(match[i])) {
				match[i] = v;
				return true;
			}
		}	
		else {
			slack[i] = min(slack[i], temp);
		}
			
	}
	return false;
}

int KM() {
	//初始化
	memset(match, -1, sizeof(match));
	memset(ly, 0, sizeof(ly));
	for(int i = 0; i < V; i++) {
		lx[i] = map[i][0];
		for(int j = 1; j < V; j++) {
			lx[i] = max(lx[i], map[i][j]);
		}
	}
	
	for(int i = 0; i < V; i++) {
		memset(slack, INF, sizeof(slack));
		while(true) {
			memset(used1, false, sizeof(used1));
			memset(used2, false, sizeof(used2));
			if(dfs(i)) break;

			int d = INF;
			for(int j = 0; j < V; j++) {
				if(!used2[j]) d = min(d, slack[j]);
			}
			for(int j = 0; j < V; j++) {
				if(used1[j]) lx[j] -= d;
				if(used2[j]) ly[j] += d;
				else slack[j] -= d;
			}
		}
	}

	int res = 0;
	for(int i = 0; i < V; i++) {
		res += map[match[i]][i];
	}
	return res;
}



int main() {
	ios::sync_with_stdio(false);
	while(cin >> V) {
		for(int i = 0; i < V; i++) {
			for(int j = 0; j < V; j++) {
				cin >> map[i][j];
			}
		}
		cout << KM() << endl;
	}
	return 0;
}

