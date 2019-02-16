#include <iostream>

using namespace std;

typedef int valueType;

struct TreeNode
{
    valueType val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(valueType val, TreeNode* left=0, TreeNode* right=0)
        : val(val), left(left), right(right) {}
};

void insert(TreeNode*& r, valueType x)
{
    if(!r) {
        r = new TreeNode(x);
    } else if(x < r->val) {
        insert(r->left, x);
    } else if(x > r->val) {
        insert(r->right, x);
    }
}

TreeNode* find(TreeNode* r, valueType x)
{  
    if(!r) {
        return 0; 
    } else if(x == r->val) { 
        return r; 
    } else if(x < r->val) {
        find(r->left, x);
    } else if(x > r->val) {
        find(r->right, x);
    }
}

TreeNode* findBeforeLast(TreeNode* r)
{
    while (r->left != 0) {
        r = r->left;
    }
    return r;
}

TreeNode* deleteNode(TreeNode*& p, valueType x)
{
    if (p == 0) {
        return p;
    } else if (x < p->val) {
        p->left = deleteNode(p->left, x);
    } else if (x > p->val) {
        p->right = deleteNode(p->right, x);
    } else {
        if (p->left == 0 && p->right == 0) {
            delete p;
            p = NULL;
        }
        else if (p->left == 0 && p->right != 0) {
            TreeNode* tmp = p;
            p = p->right;
            delete tmp;
            tmp = NULL;
        }
        else if (p->left != 0 && p->right == 0) {
            TreeNode* tmp = p;
            p = p->left;
            delete tmp;
            tmp = NULL;
        }
        else {
            TreeNode* tmp = findBeforeLast(p->right);
            p->val = tmp->val;
            p->right = deleteNode(p->right, tmp->val);
        }
    }
    return p;
}

main() 
{
    TreeNode* root = 0;
    int m, k, x;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k >> x;
        if (k == 1) {
            insert(root, x);
        } else if (k == 2) {
            if (find(root, x)) {
                cout << 1 << endl;
            }
            else cout << 0 << endl;
        } else if (k == 3) {
            root = deleteNode(root, x);
        }
    }
}