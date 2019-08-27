#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

const int MAXN = 6e6;
int Next[MAXN];
int pos[MAXN];
char ans[MAXN];
int cnt;

void getnext(string s) {
	int l = (int)s.length();
	Next[0] = -1;
	int k = -1;
	int j = 0;
	while(j < l) {
		if(k == -1 || s[j] == s[k]) {
			j++, k++;
			Next[j] = s[j] == s[k] ? Next[k] : k;
		}
		else k = Next[k];
	}
}

void kmp(string s1, string s2) {
	getnext(s2);
	int l1 = (int)s1.length();
	int l2 = (int)s2.length();
	cnt = 0;
	for(int i = 0, j = 0; i < l1; i++) {
		ans[cnt] = s1[i];
		//用while直接找到了模式串的匹配位
		while(!(j == -1 || ans[cnt] == s2[j])) j = Next[j];
		j++, cnt++;
		
		pos[cnt] = j;//标记每一位与模式串匹配的位置，为退回做准备
		//如果与模式串匹配，删除子串，即下表往前退l2
		if(j == l2) {
			cnt -= l2;
			j = pos[cnt];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	string s1, s2;
	while(cin >> s2 >> s1) {
		
		kmp(s1, s2);
		for(int i = 0; i < cnt; i++) {
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
