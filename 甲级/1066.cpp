/*想不到还有这种题目，还真的让写个AVL树*/

#include<iostream>
using namespace std;
static const int ALLOWED_IMBALANCE=1;	//最大允许高度差1;
struct AvlNode	//节点
{
    int element;
    AvlNode* left;
    AvlNode* right;
    int height;	//存储高度信息
    AvlNode():element{0},left{nullptr},right{nullptr},height{0}{}
    AvlNode(const int& ele,AvlNode* lt,AvlNode* rt,int h=0):element{ele},left{lt},right{rt},height{h}{}
};
int height(AvlNode *t)
{
    return t==nullptr?-1:t->height;	//返回节点高度，注意节点有可能为空，此时高度定义为-1;
}
void rotateWithLeftChile(AvlNode *&k2)	//左旋
{
    AvlNode* k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    k1->height=max(height(k1->left),k2->height)+1;
    k2=k1;
}
void rotateWithRightChile(AvlNode *&k2)	//右旋
{
    AvlNode* k1=k2->right;
    k2->right=k1->left;
    k1->left=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    k1->height=max(k2->height,height(k1->right))+1;
    k2=k1;
}
void doubleWithLeftChild(AvlNode *&k3)	//左边双旋转，注意为了改变指针，必须使用指针引用的方式
{
    rotateWithRightChile(k3->left);
    rotateWithLeftChile(k3);
}
void doubleWithRightChild(AvlNode *&k3)	//右边双旋转
{
    rotateWithLeftChile(k3->right);
    rotateWithRightChile(k3);
}
void balance(AvlNode* &t)	//检查并平衡二叉树
{
    if(t==nullptr)
        return;
    if(height(t->left)-height(t->right)>ALLOWED_IMBALANCE)	
    {
        if(height(t->left->left)>=height(t->left->right))	//等号是为了处理删除时候的情况，这里用不到。删除节点后这两项可能会相等，此时用单旋转
            rotateWithLeftChile(t);
        else
            doubleWithLeftChild(t);
    }
    else if(height(t->right)-height(t->left)>ALLOWED_IMBALANCE)
    {
        if(height(t->right->right)>=height(t->right->left))
            rotateWithRightChile(t);
        else
            doubleWithRightChild(t);
    }
    t->height=max(height(t->left),height(t->right))+1;	
}
void insert(const int &x,AvlNode* &t)
{
    if(t==nullptr)
        t=new AvlNode(x,nullptr,nullptr);
    else if(x<t->element)
        insert(x,t->left);
    else if(t->element<x)
    {
        insert(x,t->right);
    }
    balance(t);	//递归之后检查平衡，因为不平衡点只可能出现在插入的路径上
}
int main()
{
    AvlNode *head=nullptr;
    int n;
    cin>>n;
    while(n--)
    {
        int tmp;
        cin>>tmp;
        insert(tmp,head);
    }
    cout<<head->element<<endl;
    return 0;
}
