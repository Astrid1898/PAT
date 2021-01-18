#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
int the_most_wrong_time=0;
class answer
{
    private:
        int score;
        int t_asw_num;
        string t_asw;
		int ans_num;
    public:
        map<char,int> map_asw;
        friend istream &operator>>(istream &input,answer &asw);
        friend class stu;
};
class stu
{
    private:
        vector<int> stu_ans_num;
        vector<string> stu_asw;
        double stu_score; 
    public:
        stu(string& );
        void caculatute_the_score(answer&,int&);
        double get_score()
        {
            return stu_score;
        }
};
istream &operator>>(istream &input,answer &asw)
{
    input>>asw.score>>asw.ans_num>>asw.t_asw_num;
    for(int i=0;i<asw.t_asw_num;i++)
    {
        char temp;
        input>>temp;
        asw.t_asw.push_back(temp);
    }
    return input;
}
stu::stu(string& str)
{
    stu_score=0.0;
    string temp;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        {
            stu_ans_num.push_back(str[++i]-'0');
            continue;
        }
        else if((str[i]-'a')>=0&&(str[i]-'a')<25)
        {
            temp.push_back(str[i]);
        }
        else if(str[i]==' ')
        {
            continue;
        }
        else if(str[i]==')')
        {
            stu_asw.push_back(temp);
            temp="";
        }
    }
}
void stu::caculatute_the_score(answer& ans,int& index)
{
    int sign=0;
	int sign2=0;
    for(int i=0;i<ans.t_asw.size();i++)
    {
        if(stu_asw[index].find(ans.t_asw[i])==string::npos)
        {
            ans.map_asw[ans.t_asw[i]]++;
            if(ans.map_asw[ans.t_asw[i]]>the_most_wrong_time)
                the_most_wrong_time=ans.map_asw[ans.t_asw[i]];
            sign=1;
        }
    }
	for(int i=0;i<stu_asw[index].size();i++)
	{
		if(ans.t_asw.find(stu_asw[index][i])==string::npos)
        {
            ans.map_asw[stu_asw[index][i]]++;
            if(ans.map_asw[ans.t_asw[i]]>the_most_wrong_time)
                the_most_wrong_time=ans.map_asw[ans.t_asw[i]];
			sign2=1;
        }
	}
    if(sign2)
    {
        return;
    }
    else if(!sign&&!sign2)
    {
        stu_score+=double(ans.score);
        return;
    }
    else if(sign&&!sign2)
    {
        stu_score+=double(ans.score)/2.0;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    answer right_ans[m];
    for(int j=0;j<m;j++)
        cin>>right_ans[j];
    getchar();
    for(int i=0;i<n;i++)
    {
        string str;
        getline(cin,str);
        stu temp(str);
        for(int j=0;j<m;j++)
        {
            temp.caculatute_the_score(right_ans[j],j);
        }
		cout<<setiosflags(ios::fixed)<<setprecision(1);
		cout<<temp.get_score()<<endl;
    }
    if(the_most_wrong_time==0)
    {
        cout<<"Too simple"<<endl;
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        map<char,int>::iterator it=right_ans[i].map_asw.begin();
        for(;it!=right_ans[i].map_asw.end();it++)
        {
            if(it->second==the_most_wrong_time)
                cout<<the_most_wrong_time<<" "<<i+1<<'-'<<it->first<<endl;
        }
    }
    return 0;
}
