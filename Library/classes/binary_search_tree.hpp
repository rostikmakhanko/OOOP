#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include "book/book.hpp"

using namespace std;

class BinarySearchTree
{
    private:
    struct TreeNode
    {
        Book val;
        TreeNode *left,*right,*parent;

        TreeNode(Book val1);
    };

    TreeNode* root;
    int size;

    void inorder_traversal(TreeNode* cur);

    TreeNode* find(TreeNode* cur,Book val1);

    TreeNode* insert(TreeNode* cur,Book val1);

    TreeNode* erase(TreeNode* cur,Book val1);

    TreeNode* find_min(TreeNode* cur);

    TreeNode* find_max(TreeNode* cur);

    public:
    BinarySearchTree();

    void paste(Book val1);

    void remove(Book val1);

    bool find(Book val1);

    void print();
};

#endif // BINARY_SEARCH_TREE_H
