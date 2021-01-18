#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class problem
{
    public:
        problem()
        {
            wrong_times=0;
        }
        friend istream &operator>>(istream& input,problem& temp);
		friend class stu_ans;
		int  get_wrong_time()
		{
			return wrong_times;
		}
    private:
        int score;
        int num_of_option;
        int num_of_right_op;
        vector<char> right_ans;
        int wrong_times;
};
class stu_ans
{
    public:
        stu_ans(const string&);
        friend class problem;
        void caculate_the_score(problem&,int );
        void show_score()
        {
            cout<<final_score<<endl;
        }
    private:
        vector<int> num_of_stu_op;
        vector<string> stu_anss;
        int final_score;
};
void stu_ans::caculate_the_score(problem& pro,int k)
{
    if(num_of_stu_op[k]!=pro.num_of_right_op)
    {
        pro.wrong_times++;
        return;
    }
    for(int i=0;i<pro.num_of_right_op;i++)
    {
        if(stu_anss[k].find(pro.right_ans[i])==string::npos)
        {
            pro.wrong_times++;
            return;
        }
    }
    final_score+=pro.score;
	return;
}
istream &operator>>(istream& input,problem& temp)
{
    input>>temp.score>>temp.num_of_option>>temp.num_of_right_op;
    char c;
    for(int i=0;i<temp.num_of_right_op;i++)
    {
        input>>c;
        temp.right_ans.push_back(c);
    }
    return input;
}
stu_ans::stu_ans(const string& str)
{
	final_score=0;
    string temp="";
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        {
            num_of_stu_op.push_back(str[++i]-'0');
        }
        else if(str[i]==' ')
            continue;
        else if((str[i]-'a')>=0&&(str[i]-'a')<26)
            temp.push_back(str[i]);
        else if(str[i]==')')
        {
            stu_anss.push_back(temp);
            temp="";
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    problem test[m];
    vector<stu_ans> stu;
    for(int i=0;i<m;i++)
        cin>>test[i];
    string str; 
    getchar();
    for(int i=0;i<n;i++)
    {
        getline(cin,str);
        stu_ans temp(str);
		stu.push_back(temp);
    }
    for(int stu_num=0;stu_num<n;stu_num++)
    {
        for(int pro_num=0;pro_num<m;pro_num++)
            stu[stu_num].caculate_the_score(test[pro_num],pro_num);
        stu[stu_num].show_score();
    }
	int most_wrong_time=0,temp=0,sign=1;
	for(int i=0;i<m;i++)
	{
		temp=test[i].get_wrong_time();
		if(temp>=most_wrong_time)
		{	
			most_wrong_time=temp;
		}
	}
	if(most_wrong_time==0)
		cout<<"Too simple";
	else
	{
		for(int i=0;i<m;i++)
		{
			if(test[i].get_wrong_time()==most_wrong_time&&sign==1)
			{
				cout<<test[i].get_wrong_time()<<' '<<i+1;
				sign--;
			}
			else if(test[i].get_wrong_time()==most_wrong_time&&sign==0)
				cout<<' '<<i+1;
		}
	}
    return 0;
}
