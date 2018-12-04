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

/**
    Traversal for getting vector of titles of all books in library

    @param Node of tree
    @return Vector of books' titles in library
*/
vector<string> BinarySearchTree :: title_traversal(TreeNode* cur)
{
    vector<string> ans;
    queue<TreeNode*> q;
    TreeNode* cur1=cur;
    while (cur1!=NULL)
    {
        ans.push_back(cur1->val.get_title());
        q.push(cur1->left);
        q.push(cur1->right);
        while (!q.empty())
        {
            cur1=q.front();
            q.pop();
            if (cur1!=NULL) {break;}
        }
    }
    return ans;
}

/**
    Finding in tree book with title same as val1 have

    @param Node of tree, book which want to find
    @return NULL if there's no book with such title, pointer on Node of founded book else
*/
BinarySearchTree :: TreeNode* BinarySearchTree :: find(BinarySearchTree :: TreeNode* cur,Book val1)
{
    if (cur==NULL) {return cur;}
    if (cur->val==val1) {return cur;}
    if (val1<cur->val) {return find(cur->left,val1);}
    else {return find(cur->right,val1);}
}

/**
    Finding first book in alphabetic order

    @param Node of tree in which we're doing search
    @return @return NULL if there's no book in library, pointer on Node of founded book else
*/
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

vector<string> BinarySearchTree :: get_books_titles()
{
    return title_traversal(root);
}

void BinarySearchTree :: print()
{
    cout<<"Now library has these "<<size<<" books:"<<endl;
    cout<<endl;
    inorder_traversal(root);
    cout<<"-----------------------------------"<<endl;
    cout<<endl;
}

