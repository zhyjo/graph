#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
const int MAXN = 15;
char s[MAXN];
using namespace std;

struct node {
	int v;
	node* next[26];
	node() {
		for(int i = 0; i < 26; i++) next[i] = NULL;
		v = 0;
	}
}*root;

void insert(char *s) {
	int l = strlen(s);
	node* p = root; 
	for(int i = 0; i < l; i++) {
		int id = s[i]-'a';
		if(p->next[id] == NULL) p->next[id] = new node();
		p = p->next[id];
		p->v++;	      
		
	}
}


int find(string s) {
	int l = (int)s.length();
	node* p = root;
	for(int i = 0 ; i < l; i++) {
		int id = s[i]-'a';
	        if(p->next[id] == NULL) return 0;
	        p = p->next[id];		
	       
	}
	return  p->v;
}

void clear(node* root) {
	node* p = root;
	for(int i = 0; i < 26; i++) {
		if(p->next[i] != NULL) {
			clear(p->next[i]);
		}
	}
	delete p;
}
int main() {
	//不用string因为string不能读空字符串，所以无法跳出循环
	ios::sync_with_stdio(false);
	root = new node();
	while(gets(s) && s[0] != '\0') {
		insert(s);
	}
	
	string s;
	while(cin >> s) {
		cout << find(s) << endl;
	}
	clear(root);
}

