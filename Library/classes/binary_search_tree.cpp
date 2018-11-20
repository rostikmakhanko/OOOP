#include "binary_search_tree.hpp"

BinarySearchTree :: TreeNode :: TreeNode(Book val1)
{
    val=val1;
    left=NULL; right=NULL; parent=NULL;
}

void BinarySearchTree :: inorder_traversal(TreeNode* cur)
{
    if (cur==NULL) {return;}
    inorder_traversal(cur->left);
    cur->val.print_info();
    inorder_traversal(cur->right);
}

BinarySearchTree :: TreeNode* BinarySearchTree :: find(BinarySearchTree :: TreeNode* cur,Book val1)
{
    if (cur==NULL) {return cur;}
    if (cur->val==val1) {return cur;}
    if (val1<cur->val) {return find(cur->left,val1);}
    else {return find(cur->right,val1);}
}

BinarySearchTree :: TreeNode* BinarySearchTree :: find_min(BinarySearchTree :: TreeNode* cur)
{
    if (cur==NULL) {return cur;}
    if (cur->left==NULL) {return cur;}
    return find_min(cur->left);
}

BinarySearchTree :: TreeNode* BinarySearchTree :: find_max(BinarySearchTree :: TreeNode* cur)
{
    if (cur==NULL) {return cur;}
    if (cur->right==NULL) {return cur;}
    return find_max(cur->right);
}

BinarySearchTree :: TreeNode* BinarySearchTree :: insert(BinarySearchTree :: TreeNode* cur,Book val1)
{
    if (cur==NULL)
    {
        cur=new TreeNode(val1);
    }
    else if (val1<cur->val)
    {
        cur->left=insert(cur->left,val1);
    }
    else if (cur->val<val1)
    {
        cur->right=insert(cur->right,val1);
    }
    return cur;
}

BinarySearchTree :: TreeNode* BinarySearchTree :: erase(BinarySearchTree :: TreeNode* cur,Book val1)
{
    if (cur==NULL) {return cur;}
    if (val1<cur->val)
    {
        cur->left=erase(cur->left,val1);
    }
    else if (cur->val<val1)
    {
        cur->right=erase(cur->right,val1);
    }
    else if (cur->left!=NULL&&cur->right!=NULL)
    {
        TreeNode* cur1=find_min(cur->right);
        cur->val=cur1->val;
        cur->right=erase(cur->right,cur->val);
    }
    else
    {
        TreeNode* cur1=cur;
        if (cur->left==NULL)
        {
            cur=cur->right;
        }
        else if (cur->right)
        {
            cur=cur->left;
        }
        delete cur1;
    }
    return cur;
}

BinarySearchTree :: BinarySearchTree()
{
    root=NULL;
    size=0;
}

void BinarySearchTree :: paste(Book val1)
{
    root=insert(root,val1);
    size++;
}

void BinarySearchTree :: remove(Book val1)
{
    if (find(root,val1)==NULL) {return;}
    root=erase(root,val1);
    size--;
}

bool BinarySearchTree :: find(Book val1)
{
    if (find(root,val1)==NULL) {return 0;}
    else {return 1;}
}

void BinarySearchTree :: print()
{
    cout<<"Now library have these books:"<<endl;
    cout<<endl;
    inorder_traversal(root);
    cout<<"-----------------------------------"<<endl;
}

