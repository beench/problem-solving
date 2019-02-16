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

void find(TreeNode* r, valueType x)
{  
    if(!r) {
        cout << 0 << endl; 
    } else if(x == r->val) { 
        cout << 1 << endl; 
    } else if(x < r->val) {
        find(r->left, x);
    } else if(x > r->val) {
        find(r->right, x);
    }
}

main() 
{
    TreeNode* root = 0;
    int m, k, x;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        if (k == 1) {
            cin >> x;
            insert(root, x);
        } else if (k == 2) {
            cin >> x;
            find(root, x);
        }
    }
}