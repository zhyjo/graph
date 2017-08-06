#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 300;

int match[MAXN];
bool map[MAXN][MAXN], used[MAXN];

int V, E;


int dfs(int v) {
	for(int i = 1; i <= V; i++) {
		if(!used[i] && map[v][i]) {
			used[i] = true;
		        if(match[i] == -1 || dfs(match[i])) {
			       match[i] = v;
			       return true;

		       }	
		}
	}
	return false;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		memset(map, 0, sizeof(map));
		memset(match, -1, sizeof(match));
		cin >> V >> E;
		for(int i = 1; i <= E; i++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = true;
		}
		int ans = 0;
		for(int i = 1; i <= V; i++) {
			memset(used, false, sizeof(used));
			if(dfs(i)) ans++;		
		}
		cout << V-ans << endl;
	}
}


