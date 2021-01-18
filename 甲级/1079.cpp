/*
我之前的做法有点问题，最后一个测试点会超时，下面是
从https://blog.csdn.net/Ashe_1994/article/details/103873675找来的
比较好的做法，用了DFS的方法;
还是错在没有好好读题，简单的DFS就没看出来，以为和微博那个是一样的
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct node {
    double data;
    vector<int> child;
};  //存储每个distributor的信息
vector<node> v;
double ans = 0.0, p, r; //p是price，r是每级加的利润

void dfs(int index, int depth) {
    if(v[index].child.size() == 0) {
        ans += v[index].data * pow(1 + r, depth);
        return ;    //到达retailer的时候就计算利润
    }
    for(int i = 0; i < v[index].child.size(); i++)
        dfs(v[index].child[i], depth + 1);
}
int main() {
    int n, k, c;
    scanf("%d %lf %lf", &n, &p, &r);
    r = r / 100;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        if(k == 0) {    //retalier处特殊处理
            scanf("%lf", &v[i].data);
        } else {
            for(int j = 0; j < k; j++) {
                scanf("%d", &c);
                v[i].child.push_back(c);
            }
        }
    }
    dfs(0, 0);  //从supplier处开始处理
    printf("%.1f", ans * p);
    return 0;
}
