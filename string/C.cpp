#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

const int MAXN = 100000;

struct node {
	int v;
	node* next[26];
	node* fail;
	node() {
		for(int i = 0 ; i < 26; i++) next[i] = NULL;
		fail = NULL;
		v = 0;
	}
}*root;
void insert(string s) {
	int l = (int)s.length();
	node *p = root;
	for(int i = 0; i < l; i++) {
		int id = s[i] - 'a';
		if(p->next[id] == NULL) p->next[id] = new node();
		p = p->next[id];
	}
	p->v = 1;
}

queue<node> q;

void build_fail() {
	q.push(*root);//根结点进入队列
	node  *temp, *p;

	//temp为当前广搜的节点
	//p为temp失败后转移的节点
	while(!q.empty()) {
		temp = &q.front();
		q.pop();

		
		for(int i = 0; i < 26; i++) {
			if(temp->next[i]) {
				if(temp == root) {
					temp->next[i]->fail = root;
				}
				else {
					p = temp->fail;
					while(p) {
						if(p->next[i]) {
							temp->next[i]->fail = p->next[i];
							break;
						}
						p = p->fail;//回溯
					}
					if(p == NULL) temp->next[i]->fail = root;
					//回溯到root
				}
				q.push(*(temp->next[i]));//进队列
			}
		}
	}
	

}

void ac(string s) {
	int cnt = 0;
	node *p = root;
	int l = (int)s.length();
	for(int i = 0; i < l; i++) {
		int id = s[i] = 'a';
		//找到匹配位置
		while(!p->next[id] && p != root) p = p->fail;
		p = p->next[id];
		if(!p) p = root;
		node *temp = p;
		while(temp != root) {
			if(temp->v >= 0) {
				cnt += temp->v;
				temp->v = -1;
			}
			else 
				break;
			temp = temp->fail;
		}
		

	}
}
