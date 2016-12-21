#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 50;
struct node{
	int data;
	node* lchild;
	node* rchild;
}; 
int pre[maxn], in[maxn], post[maxn]
