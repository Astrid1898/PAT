/*根据题目的要求，这里当然可以不用建二叉树，
*不过建个树联系一下也无妨*/

#include<iostream>
#include<queue>
using namespace std;
struct TreeNode
{
    int data{0};
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};
};
TreeNode* bulidTree(int postorder[],int inorder[],int size);
void printTraversalOrder(TreeNode* tree);
int main()
{
    int n;
    cin>>n;
    int postorder[n];
    int inorder[n];
    for(int i=0;i<n;i++)
    {
        cin>>postorder[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
    }
    TreeNode* tree=nullptr;
    tree=bulidTree(postorder,inorder,n);
    printTraversalOrder(tree);
    return 0;
}
TreeNode* bulidTree(int postorder[],int inorder[],int size)
{
    TreeNode *tmpTree=nullptr;
    if(size==0)
    {
        return tmpTree;	//设定递递归的基
    }
	tmpTree=new TreeNode;
    int index,tmp=postorder[size-1];
    for(int i=0;i<size;i++)
    {
        if(inorder[i]==tmp)
        {
            index=i;
            break;
        }
    }
    tmpTree->data=tmp;
    int leftPostorder[index],rightPostorder[size-index-1];
    int leftInorder[index],rightInorder[size-index-1];
    for(int i=0;i<index;i++)
    {
        leftInorder[i]=inorder[i];	//根据后序遍历找出左子树的中序遍历
    }
    for(int i=0;i<index;i++)
    {
        leftPostorder[i]=postorder[i];	//左子数的后序遍历
    }
	int cnt=0;
    for(int i=index;i<size-1;i++)
    {
        rightPostorder[cnt]=postorder[i];		//右子树后序遍历
		cnt++;
    }
	cnt=0;
    for(int i=index+1;i<size;i++)
    {
        rightInorder[cnt]=inorder[i];	//右子树中序遍历
		cnt++;
    }
    tmpTree->left=bulidTree(leftPostorder,leftInorder,index); //递归建立左子树
    tmpTree->right=bulidTree(rightPostorder,rightInorder,size-index-1);	//递归建立右子树
    return tmpTree;
}
void printTraversalOrder(TreeNode* tree)
{
    if(!tree)
    {
        return;
    }
    queue<TreeNode*> toPrint;
    toPrint.push(tree);
    if(toPrint.front()->left)
    {
        toPrint.push(toPrint.front()->left);
    }
    if(toPrint.front()->right)
    {
        toPrint.push(toPrint.front()->right);
    }
    cout<<toPrint.front()->data;
    delete toPrint.front();
    toPrint.pop();
    while(!toPrint.empty())
    {
        if(toPrint.front()->left)
        {
            toPrint.push(toPrint.front()->left);
        }
        if(toPrint.front()->right)
        {
            toPrint.push(toPrint.front()->right);
        }
        cout<<" "<<toPrint.front()->data;
        delete toPrint.front();
        toPrint.pop();
   }
}
