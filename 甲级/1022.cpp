/*简单的图书查找程序，几乎是c语言课程必备作业，只不过这个作业的功能复杂的多
*这样用vector的结构当然没错，只是效率低点而已，若或许可以用散列表或二叉树的
*数据结构重写一下，应该运行速度会快很多*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Book //保存一本书的信息
{
        string id;
        string title;
        string author;
        string keyWord;
        string publisher;
        string publishedYear;
};
bool cmp(const Book& a,const Book &b)	//将图书馆里的数按照ID号排序
{
    return a.id<b.id;
}
class Library	//图书馆类
{
    public:
        void addBook(Book &b)
        {
            books.push_back(b);
        }
        void sortBook()
        {
            sort(books.begin(),books.end(),cmp);
        }
        void searchBook(int t,const string& str);
    private:
        vector<Book> books;
        void printBook(vector<int>& v);
};
int main()
{
    int n,m;
    cin>>n;
    getchar();
    Library lib;
    while(n--)
    {
        Book b;
        getline(cin,b.id);
        getline(cin,b.title);
        getline(cin,b.author);
        getline(cin,b.keyWord);
        getline(cin,b.publisher);
        getline(cin,b.publishedYear);
        lib.addBook(b);
    }
    lib.sortBook();
    cin>>m;
    getchar();
    while(m--)
    {
        string str;
        getline(cin,str);
        cout<<str<<endl;
        int type=str[0]-'0';
        string queryStr=str.substr(3);
        lib.searchBook(type,queryStr);
    }
    return 0;
}
void Library::searchBook(int t,const string& str)
{
    vector<int> findedBooks;
    switch(t)
    {
        case 1 :
        {
            for(int i=0;i<books.size();i++)
            {
                int n;
                if(n=books[i].title.find(str)!=string::npos)
                {
                    findedBooks.push_back(i);
                }
            }
            break;
        }
        case 2:
        {
            for(int i=0;i<books.size();i++)
            {
                if(books[i].author==str)
                {
                    findedBooks.push_back(i);
                }
            }
			break;
        }
        case 3:
        {
            int n;
            for(int i=0;i<books.size();i++)
            {
                if(n=books[i].keyWord.find(str)!=string::npos)
                {
                    findedBooks.push_back(i);
                }
            }
            break;
        }
        case 4:
        {
            for(int i=0;i<books.size();i++)
            {
                if(books[i].publisher==str)
                {
                    findedBooks.push_back(i);
                }
            }
            break;
        }
        case 5:
        {
            int n;
            for(int i=0;i<books.size();i++)
            {
                if(n=books[i].publishedYear.find(str)!=string::npos)
                {
                    findedBooks.push_back(i);
                }
            }
            break;
        }
        default:
            break;
    }
    printBook(findedBooks);
}
void Library::printBook(vector<int>& v)
{
    if(!v.size())
    {
        cout<<"Not Found"<<endl;
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<books[v[i]].id<<endl;
    }
}
