#include<iostream>
#include<cctype>
using namespace std;
int main()
{
    string words_to_be_printed,words_printed;
    cin>>words_to_be_printed>>words_printed;
    for(int i=0;i<words_printed.size();i++)
    {
        words_printed[i]=toupper(words_printed[i]);
    }
    string bad_key;
    for(int i=0;i<words_to_be_printed.size();i++)
    {	
        if(words_printed.find(toupper(words_to_be_printed[i]))==string::npos && bad_key.find(toupper(words_to_be_printed[i]))==string::npos)
{
            bad_key.push_back(toupper(words_to_be_printed[i]));
}
    }
    cout<<bad_key;
    return 0;
}
