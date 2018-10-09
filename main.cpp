#include <iostream>

using namespace std;

class BinarySearchTree
{
    private:
    struct TreeNode
    {
        int val;
        TreeNode *left,*right,*parent;

        TreeNode(int val1)
        {
            val=val1;
            left=NULL; right=NULL; parent=NULL;
        }
    };

    TreeNode* root;
    int size;

    void inorder_traversal(TreeNode* cur)
    {
        if (cur==NULL) {return;}
        inorder_traversal(cur->left);
        cout<<cur->val<<" ";
        inorder_traversal(cur->right);
    }

    TreeNode* find(TreeNode* cur,int val1)
    {
        if (cur==NULL) {return cur;}
        if (cur->val==val1) {return cur;}
        if (val1<cur->val) {return find(cur->left,val1);}
        else {return find(cur->right,val1);}
    }

    TreeNode* find_min(TreeNode* cur)
    {
        if (cur==NULL) {return cur;}
        if (cur->left==NULL) {return cur;}
        return find_min(cur->left);
    }

    TreeNode* find_max(TreeNode* cur)
    {
        if (cur==NULL) {return cur;}
        if (cur->right==NULL) {return cur;}
        return find_max(cur->right);
    }

    TreeNode* insert(TreeNode* cur,int val1)
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

    TreeNode* erase(TreeNode* cur,int val1)
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

    public:
    BinarySearchTree()
    {
        root=NULL;
        size=0;
    }

    void paste(int val1)
    {
        root=insert(root,val1);
        size++;
    }

    void remove(int val1)
    {
        if (find(root,val1)==NULL) {return;}
        root=erase(root,val1);
        size--;
    }

    bool find(int val1)
    {
        if (find(root,val1)==NULL) {return 0;}
        else {return 1;}
    }

    void print()
    {
        inorder_traversal(root);
        cout<<endl;
    }
};

int main()
{
    BinarySearchTree a;
    a.paste(5);
    a.print();
    a.paste(2);
    a.print();
    a.paste(3);
    a.print();
    a.remove(2);
    a.print();
    a.remove(1);
    a.print();
    cout<<a.find(3)<<endl;
    cout<<a.find(1)<<endl;
    return 0;
}