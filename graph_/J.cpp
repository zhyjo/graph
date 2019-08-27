#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

const int MAXN = 1005;

bool map[MAXN][MAXN], used[MAXN];
int match[MAXN];

int V;

int dfs(int v) {
	for(int i = 0; i < V; i++) {
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

int max_matching() {
	int res = 0;
	memset(match, -1, sizeof(match));
	for(int i = 0; i < V; i++) {
		memset(used, false, sizeof(used));
		if(dfs(i)) res++;
	}
	return res;
}

int main() {
	while(cin >> V) {
		ios::sync_with_stdio(false);
		memset(map, false, sizeof(map));
		for(int i = 0; i < V; i++) {
			string s;
			cin >> s;
			int x = (int)(s[0]-'0');
			cin >> s;
			int l = (int)(s[1]-'0');
			for(int i = 0; i < l; i++) {
				int y;
				cin >> y;
				map[x][y] = true;
			}
			
		}
		//cout << V - max_matching()/2 << endl;
	}
	
	return 0;
}
