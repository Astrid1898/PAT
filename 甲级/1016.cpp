/*这道题主要是费用的计算，这是参考网上的代码，巧妙地计算每个记录相对月初的绝对费用和绝对时间算相对费用与相对时间*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
typedef struct 
{
	int month, day, hour, minu, flag, time;
	double p;
}record;
std::vector<record> records[1005];
int n, cnt = 0;
double price[24], one_day_price = 0;
map<string, int>mp;
map<int, string>mp2;
void getprice_time(record &x){
	x.p = one_day_price * (x.day - 1);
	x.time = 1440* (x.day - 1);
	for(int i = 0; i < x.hour; ++ i)
		x.p += price[i];
	x.time += x.hour * 60;
	x.p += (price[x.hour] / 60) * x.minu;
	x.time += x.minu;
}
int main(){
	for(int i = 0; i < 24; ++ i){
		scanf("%lf", &price[i]);
		price[i] *= 0.6;
		one_day_price += price[i];
	}
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i){
		string name, tempflag;
		record temprecord;
		cin >> name;
		scanf("%d:%d:%d:%d",&temprecord.month, &temprecord.day, &temprecord.hour, &temprecord.minu);
		cin >> tempflag;
		temprecord.flag = (tempflag[1] == 'n' ? 0 : 1);
		getprice_time(temprecord);
		if(mp.find(name) == mp.end()){
			mp[name] = cnt;
			mp2[cnt ++] = name;
		}
		records[mp[name]].push_back(temprecord);
	}
	std::vector<int> rank(cnt);
	for(int i = 0; i < cnt; ++ i)
		rank[i] = i;
	sort(rank.begin(), rank.end(),[](int a, int b){return mp2[a] < mp2[b];});
	for(int i = 0; i < cnt; ++ i){
		int id = rank[i];
		sort(records[id].begin(), records[id].end(), [](record a, record b){return a.time < b.time;});
		double sum = 0.0;
		int lastflag = 1, lastindex = 0;
		for(int j = 0; j < records[id].size(); ++ j){
			if(lastflag == 1 && records[id][j].flag == 0){
				lastindex = j;
				lastflag = 0;
			}
			else if(lastflag == 0 && records[id][j].flag == 1){
				double tempp = (records[id][j].p - records[id][lastindex].p);
				int temptime = (records[id][j].time - records[id][lastindex].time);
				if(sum == 0)
					printf("%s %02d\n", mp2[id].c_str(), records[id][j].month);
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", records[id][lastindex].day, records[id][lastindex].hour, records[id][lastindex].minu, records[id][j].day, records[id][j].hour, records[id][j].minu, temptime, tempp);
				sum += tempp;
				lastflag = 1;
				lastindex = j;
			}
			else if(lastflag == 0)
				lastindex = j;
		}
		if(sum != 0)
			printf("Total amount: $%.2f\n", sum);
	}

}
