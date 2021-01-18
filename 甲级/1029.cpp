/*这道题也是我作为练习了，尝试着写了一下二叉堆，虽然输出
*已经是排好序的根本用不上。用写的优先队列也存在有时候最后
*一个测试点偶尔超时的问题*/
#include<iostream>
#include<vector>
using namespace std;
class BinaryHeap	//二叉堆类
{
    public:
        explicit BinaryHeap(int capacity=100):array(capacity+1),currentSize{0}{}	//构造函数
        explicit BinaryHeap(const vector<long> &items);	//用vector初始化的构造函数
        bool isEmpty()const;	//判断是否非空
        void insert(const long &x);	//插入一个元素
        long findMin()	//找到最小元素
        {
            return array[1];
        }
        void deleteMin();	//删除最小元素
    private:
        void buildHeap()	//建立二叉堆
        {
            for(int i=currentSize/2;i>0;i--)
            {
                percolateDown(i);
            }
        }
        unsigned long currentSize;	//记录堆中元素个数
        vector<long> array;	//实际是使用数组保存数据
        void percolateDown(int hole);	//下滤
};
BinaryHeap::BinaryHeap(const vector<long> &items):array(items.size()+10),currentSize{items.size()}
{   
    for(int i=0;i<items.size();i++)
    {
        array[i+1]=items[i];
    }
    buildHeap();
}
void BinaryHeap::percolateDown(int hole)
{
    int child;
    long tmp=std::move(array[hole]);
    for(;hole*2<=currentSize;hole=child)
    {
        child=hole*2;
        if(child!=currentSize&&array[child+1]<array[child])
        {
            ++child;
        }
        if(array[child]<tmp)
        {
            array[hole]=std::move(array[child]);
        }
        else
        {
            break;
        }
    }
    array[hole]=std::move(tmp);
}
bool BinaryHeap::isEmpty()const
{
    return currentSize==0?true:false;
}
void BinaryHeap::insert(const long &x)
{
    if(currentSize==array.size()-1)
    {
        array.resize(array.size()*2);
    }
    int hole=++currentSize;
    long copy=x;
    array[0]=std::move(copy);
    for(;x<array[hole/2];hole=hole/2)
    {
        array[hole]=std::move(array[hole/2]);
    }
    array[hole]=std::move(array[0]);
}
void BinaryHeap::deleteMin()
{
    array[1]=std::move(array[currentSize--]);
    percolateDown(1);
}
int main()
{
    long sizeofS1,sizeofS2;
    cin>>sizeofS1;
    vector<long> *s1=new vector<long>(sizeofS1);
    for(long i=0;i<sizeofS1;i++)
    {
        cin>>(*s1)[i];
    }
    BinaryHeap s1Binary(*s1);
    delete s1;
    cin>>sizeofS2;
    vector<long> *s2=new vector<long>(sizeofS2);
    for(long i=0;i<sizeofS2;i++)
    {
        cin>>(*s2)[i];
    }
    BinaryHeap s2Binary(*s2);
    delete s2;
    long k=(sizeofS1+sizeofS2-1)/2;
    while(k--)	//执行k次从两个堆中删除最小元的操作
    {
        long tmp1,tmp2;
        if((!s1Binary.isEmpty())&&(!s2Binary.isEmpty()))
        {
            tmp1=s1Binary.findMin();
            tmp2=s2Binary.findMin();
            if(tmp1<tmp2)
            {
                s1Binary.deleteMin();
            }
            else
            {
                s2Binary.deleteMin();
            }
        }
        else if(!s1Binary.isEmpty())
        {
            s1Binary.deleteMin();
        }
        else if(!s2Binary.isEmpty())
        {
            s2Binary.deleteMin();
        }
    }
    if(!s1Binary.isEmpty()&&!s2Binary.isEmpty())
    {
        long tmp1=s1Binary.findMin();
        long tmp2=s2Binary.findMin();
        if(tmp1<tmp2)
        {
            cout<<tmp1<<endl;
        }
        else
        {
            cout<<tmp2<<endl;
        }
    }
    else if(!s1Binary.isEmpty())
    {
        cout<<s1Binary.findMin()<<endl;
    }
    else if(!s2Binary.isEmpty())
    {
        cout<<s2Binary.findMin()<<endl;
    }
    return 0;
}
