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

void print(TreeNode* r, int cnt)
{
    if(!r) {
        return;
    }
    cnt++;
    print(r->right, cnt);
    for (int i = 0; i < cnt-1; i++) {
        cout << "..." ;
    }
    cout << "* " << r->val << endl;
    print(r->left, cnt);
}

main() 
{
    TreeNode* root = 0;
    int n, x, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
            insert(root, x);
    }
    print(root, cnt);
}