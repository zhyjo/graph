#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int MAXN = 220010;
int RL[MAXN];

string Init(string s) {
	string s2 = '#'+s+s;
	int l = (int)s.length();
	for(int i = 0, j = 1; i < l; i++) {
		s2[j++] = s[i];
		s2[j++] = '#';
	}
	return s2;
}

int manacher(string s) {
	string s1 = Init(s); int l = (int)s1.length();

	memset(RL, 0, sizeof(RL));
	int Max = -1;
	int MaxRight = 0;
	int pos = 0;

	for(int i = 1; i < l; i++) {
		if(i < MaxRight) 
			RL[i] = min(RL[2*pos-i], MaxRight-i);
		else 
			RL[i] = 1;

		while(s1[i-RL[i]] == s1[i+RL[i]] && i-RL[i] >= 0 && i+RL[i] < l) RL[i]++;
		//这里判断字符串边界可以优化一下
		//让首字符！= 尾字符

		if(MaxRight < i+RL[i]) {
			pos = i;
			MaxRight = i+RL[i];
		}
		Max = max(Max, RL[i]-1);
		
	}
	return Max;
}

int main() {
	ios::sync_with_stdio(false);
	string s;
	while(cin >> s) {
		cout << manacher(s) << endl;
	}
	return 0;
}
