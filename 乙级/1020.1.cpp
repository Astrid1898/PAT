#include<iostream>
#include<algorithm>

using namespace std;

//除了市场需求是整数
int main()
{
	int N;
	int D;
	cin >> N >> D;
	double* stock = new double[N];//库存量
	double* price = new double[N];//月饼单价
	double* density = new double[N]; //月饼的价值密度
	int i;
	for (i = 0; i < N; i++) cin >> stock[i];
	for (i = 0; i < N; i++) {
		cin >> price[i];
		density[i] = price[i] / stock[i];
	} 
	
	double profit = 0; //总收益
	while (D) {//分配需求量
		double* max = max_element(density, density + N);
		int index = max - density; //最大价值密度的位置
		double allocation = stock[index] < D ? stock[index] : D;
		D -= allocation; //需求量降低
		profit += allocation*density[index]; //计算已得利益
		density[index] = 0; //已经分配的
	}
	printf("%.2f", profit);
	cout << endl;

	delete[] stock, price, density;
	system("pause");
	return 0;
}
--------------------- 
作者：Philomath丶 
来源：CSDN 
原文：https://blog.csdn.net/Africa_South/article/details/87937299 
版权声明：本文为博主原创文章，转载请附上博文链接！
