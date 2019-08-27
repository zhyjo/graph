#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 10;


struct node{
	int v;
	node* next[MAXN];
	node() {
		v = 0;
		for(int i = 0; i < MAXN; i++) next[i] = NULL;
	}
}*root;

int insert(string str) {
	int l = (int)str.length();
	node *p = root;
	for(int i = 0; i < l; i++) {
		int id = str[i] - '0';
		if(p->next[id] == NULL) {
			p->next[id] = new node();		
		}
		p = p->next[id];//下一位
	}
	p->v++;
	return p->v;
}
void clear(node* root) {
	node* p = root;
	for(int i = 0; i < MAXN; i++) {
		if(p->next[i] != NULL) clear(p->next[i]);	
	}
	delete p;
}
int main() {
	ios::sync_with_stdio(false);
	int N;
	while(cin >> N) {
		//初始化
		int ans = 0;
		root = new node();
		while(N--) {
			string s;
			cin >> s;
			//处理前面的0
			int l = (int)s.length();
			int i;
			for(i = 0; i < l; i++) {
				if(s[i] != '0') {
					s.erase(0, i);
					break;
				}
			}
			if(i == l && i != 0) s = '0';
			
			ans = max(ans, insert(s));
		}
		cout << ans << endl;
		clear(root);
	}
	return 0;
	
}


