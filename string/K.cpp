#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int MAXN = 1000005;

int Next[MAXN];

void getnext(string s) {
	int l = (int)s.length();
	Next[0] = -1;
	int j = 0;
	for(int i = 1; i < l;) {//Next数组会递推越界一个
		if(j == -1 || s[i] == s[j]) {
			i++, j++;
			Next[i] = s[i] == s[j] ? Next[j] : j;
		}
		else j = Next[j];
	}
}


int kmp(string s1, string s2) {
	int c = 0;
	getnext(s2);
	int l1 = (int)s1.length();
	int l2 = (int)s2.length();
	for(int i = 0, j = 0; i < l1;) {
		while(!(j == -1 || s1[i] == s2[j])) j = Next[j];
		i++, j++;

		if(j == l2) {
			c++;
			j = Next[j];
		}
	}
	return c;
}

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	string s1, s2;
	while(N--) {
		cin >> s2 >> s1;
		cout << kmp(s1, s2) << endl;
	}
}
