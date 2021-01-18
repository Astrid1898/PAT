#include<iostream>
#include<vector>
#include<string>
using namespace std;
class emoticon
{
    public:
        void input_hand(const string &);
        void input_eye(const string &);
        void input_mouth(const string &);
        void show(int *p);
    private:
        vector<string> hand;
        vector<string> eye;
        vector<string> mouth;
};
void emoticon::input_hand(const string & str_hand)
{
    string temp;
    int sign=0;
    for(int i=0;i<str_hand.size();i++)
        {
            if(str_hand[i]=='[')
            {
                sign=1;
                continue;
            }
            if(str_hand[i]==']')
            {
                hand.push_back(temp);
                temp="";
                sign=0;
                continue;
            }
            if(sign)
                temp.push_back(str_hand[i]);
        }
}
void emoticon::input_eye(const string & str_eye)
{
    string temp;
    int sign=0;
    for(int i=0;i<str_eye.size();i++)
        {
            if(str_eye[i]=='[')
            {
                sign=1;
                continue;
            }
            if(str_eye[i]==']')
            {
                eye.push_back(temp);
                temp="";
                sign=0;
                continue;
            }
            if(sign)
                temp.push_back(str_eye[i]);
        }
}
void emoticon::input_mouth(const string & str_mouth)
{
    string temp;
    int sign=0;
    for(int i=0;i<str_mouth.size();i++)
        {
            if(str_mouth[i]=='[')
            {
                sign=1;
                continue;
            }
            if(str_mouth[i]==']')
            {
                mouth.push_back(temp);
                temp="";
                sign=0;
                continue;
            }
            if(sign)
                temp.push_back(str_mouth[i]);
        }
}
void emoticon::show(int* p)
{
    int size_hand=hand.size();
    int size_eye=eye.size();
    int size_mouth=mouth.size();
    for(int i=0;i<5;i++)
    {
        if(*(p+i)<1)
        {
            cout<<"Are you kidding me? @\\/@"<<endl;
            return;
        }
    }
        if(*(p+0)>size_hand||*(p+1)>size_eye||*(p+2)>size_mouth||*(p+3)>size_eye||*(p+4)>size_hand)
            {
                cout<<"Are you kidding me? @\\/@"<<endl;
                return;
            }
        cout<<hand[*(p+0)-1]<<'('<<eye[*(p+1)-1]<<mouth[*(p+2)-1]<<eye[*(p+3)-1]<<')'<<hand[*(p+4)-1]<<endl;
}
int main()
{
    string str_hand,str_eye,str_mouth;
    getline(cin,str_hand);
    getline(cin,str_eye);
    getline(cin,str_mouth);
    emoticon e;
    e.input_hand(str_hand);
    e.input_eye(str_eye);
    e.input_mouth(str_mouth);
    int k;
    cin>>k;
    int **emoji=new int*[k];
    for(int i=0;i<k;i++)
    {	
		emoji[i]=new int[5];
        for(int j=0;j<5;j++)
		{
            cin>>emoji[i][j];
		}
        e.show(emoji[i]);
        delete[] emoji[i];
    }
    delete[] emoji;
    return 0;
}
