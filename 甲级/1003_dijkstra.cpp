/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2021-01-05 23:55:58
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-05 00:07:27
 */
#include <iostream>
using namespace std;
#define inf 99999999
int map[510][510];	   //储存边权
int t[510] = {0};	   //储存点权
int visit[510] = {0};  //是否录入
int dist[510];		   //储存最短路长度
int weight[510] = {0}; //储存最多点权
int num[510] = {0};	   //储存到达每个点的最短路数量
int main()
{
	int a, b, c, v;
	int n, m, c1, c2;
	cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	for (int i = 0; i < n; i++) //初始化map
		for (int j = 0; j < n; j++)
			map[i][j] = inf;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		map[a][b] = c;
		map[b][a] = c;
	}
	v = c1;
	num[v] = 1;		  //设置初始的num
	weight[v] = t[v]; //设置初始的weight
	dist[v] = 0;
	visit[v] = 1;				//录入
	for (int i = 0; i < n; i++) //初始化数据
	{
		dist[i] = map[v][i];
		num[i] = num[v];
		if (i != v)
			weight[i] = weight[v] + t[i]; //更新每个点的最大救援队数量
	}
	while (1)
	{
		int min = inf;
		v = -1;
		for (int i = 0; i < n; i++) //寻找未被录入且dist最小的点
		{
			if (min > dist[i] && visit[i] == 0)
			{
				min = dist[i];
				v = i;
			}
		}
		if (v == -1 || v == c2) //无符合的点或者已经到达c2,结束
			break;
		visit[v] = 1;
		for (int i = 0; i < n; i++) //更新dist,num,weight
		{
			if (visit[i] == 0 && map[v][i] != inf) //未被录入且与v邻接
			{
				if (dist[i] > dist[v] + map[v][i]) // dist会变小
				{
					dist[i] = dist[v] + map[v][i]; //修改dist
					num[i] = num[v];			   //更新num
					weight[i] = weight[v] + t[i];  //更新每个点的最大救援队数量
				}
				else if (dist[i] == dist[v] + map[v][i]) // num增加
				{
					num[i] += num[v];				  // dist[v]+map[v][i]也是最短路径,所以num[i]也是最短路数量.
					if (weight[i] < weight[v] + t[i]) //相同路长度,优先weight大的.
						weight[i] = weight[v] + t[i];
				}
			}
		}
	}
	cout << num[c2] << " " << weight[c2];
	return 0;
}
