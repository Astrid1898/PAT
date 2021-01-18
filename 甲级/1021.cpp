/*一开始用DFS算法硬算没法通过，因为写的混乱导致测试点3段错误，参考了网上这种怪异的代码后可以通过了*/
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
struct Node {
	int num;
	int floor;
};
vector<vector<int>>G; //图
vector<int>node;
int n;
set<int>s;
//并查集  findRoot（） unions（）
int findRoot(int i) {
	while (node[i] != i) {
		i = node[i];
	}
	return i;
}
void unions(int a,int b) {
	int aRoot = findRoot(a);
	int bRoot = findRoot(b);
	if (aRoot != bRoot)
		node[aRoot] = bRoot;
}
//第一次BFS找到所有叶子节点并加入集合s中
int findTreeRoot(vector<Node>nodes) {
	queue<Node>q;
	nodes[1].floor = 1;
	q.push(nodes[1]);
	int maxFloor = 1;
	while(!q.empty()){
		Node temp = q.front();
		q.pop();
		for (int i = 0;i < G[temp.num].size();i++) {
			if (nodes[G[temp.num][i]].floor == 0) {
				nodes[G[temp.num][i]].floor = temp.floor + 1;
				q.push(nodes[G[temp.num][i]]);
				maxFloor = temp.floor + 1;
			}
		}
	}
	int root = 1;
	for (int i = 1;i <= n;i++) {
		if (nodes[i].floor == maxFloor) {
			root = i;
			s.insert(i);
		}
	}
	return root;
}
//第二次BFS找到所有叶子节点加入集合s中
void deepestRoot(vector<Node>nodes,int root) {
	
	queue<Node>q;
	nodes[root].floor = 1;
	q.push(nodes[root]);
	int maxFloor = 1;
	while (!q.empty()) {
		Node temp = q.front();
		q.pop();
		for (int i = 0;i < G[temp.num].size();i++) {
            //如果该节点没有被访问过则更新该节点的信息，之所以可以这么做，是因为第二次查找的时候是倒过来的，并不会用到第一次的临接矩阵值
			if (nodes[G[temp.num][i]].floor == 0) {
				nodes[G[temp.num][i]].floor = temp.floor + 1;
				q.push(nodes[G[temp.num][i]]);
				maxFloor = temp.floor + 1;
			}
		}
	}
	//将最深的节点加入s中
	for (int i = 1;i <= n;i++) {
		if (nodes[i].floor == maxFloor) {
			s.insert(i);
		}
	}
    //输出结果
	for (auto i = s.begin();i != s.end();i++) {
		printf("%d\n", *i);
	}
	return;
}
int main() {
	cin >> n;
	G.resize(n + 1);
	node.resize(n + 1, 0);
	for (int i = 1;i <= n;i++)
		node[i] = i;
    //建立树
	for (int i = 1;i <= n - 1;i++) {
		int n1, n2;
		scanf("%d%d", &n1, &n2);
		G[n1].push_back(n2);
		G[n2].push_back(n1);
		unions(n1, n2);
	}
	int count = 0;//记录连通分量个数数
	for (int i = 1;i <= n;i++) {
		if (node[i] == i)
			count++;
	}
	if(count==1){
		vector<Node>ns(n + 1);
		for (int i = 1;i <= n;i++) {
			ns[i].num = i;
			ns[i].floor = 0;
		}
		int root = findTreeRoot(ns);
		deepestRoot(ns, root);
	}
	else {
		printf("Error: %d components", count);
	}
    return 0;
}
