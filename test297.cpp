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
int pre[maxn], in[maxn], post[maxn];//先序、中序、后序
int n;//结点个数

//当前二叉树的后续序列曲线为[postL, postR]，中序序列区间为[inL, inR]
//creat函数返回构建出的二叉树的根节点地址
node* create(int postL, int postR, int inL, int inR){
	if(postL > postR){
		return NULL;//后序序列长度小于等于0，直接返回 
	}
	node* root = new node;//新建一个新的节点，用来存放当前二叉树的根节点
	root->data = post[postR];//新节点的数据域为根节点的值
	int k;
	for(k = inL; k <= inR; k++){
		if(in[k] == post[postR]){//在中序序列中找到in[k] == pre[L]的节点 
			break;
		}
	} 
	int numLeft = k - inL;//左子树的节点的个数
	//返回左子树的根节点地址，赋值给root的左指针
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
	//返回右子树的根节点地址，赋值给root的右指针
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
	return root; //返回根节点地址 
} 
int num = 0; //已输出节点个数 
void BFS(node* root){
	queue<node*> q;//注意队列里是存地址
	q.push(root);//将根节点地址入队
	while(!q.empty()){
		node* now = q.front();//取出队首元素
		q.pop();
		printf("%d",now->data);//访问队首元素 
		num++;
		if(num < n){
			printf(" ");
		} 
		if(now->lchild != NULL){//左子树非空 
			q.push(now->lchild); 
		}
		if(now->rchild != NULL){//右子树非空 
			q.push(now->rchild);
		}
		
	} 
} 

int main(void){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &post[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &in[i]);
	}
	node* root = create(0, n - 1, 0, n -1); //建树
	BFS(root);   //层序遍历 
} 

