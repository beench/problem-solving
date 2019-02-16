#include <iostream>
#include <stdio.h>

using namespace std;

typedef int valueType;

struct TreeNode
{
    valueType val;
    TreeNode* left;
    TreeNode* right;
    valueType more;

    TreeNode(valueType val, TreeNode* left=0, TreeNode* right=0, valueType more = 0)
        : val(val), left(left), right(right), more(more) {}
};

void insert(TreeNode*& r, valueType x)
{
    if(!r) {
        r = new TreeNode(x);
    } else if(x < r->val) {
        insert(r->left, x);
    } else if(x > r->val) {
        r->more++;
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

int find_greater_than(TreeNode* r, valueType x)
{
    int countBST = 0, cnt = 0;
    if (!r) {
        return 0;
    } else if (x < r->val) {
        countBST += r->more + 1;
        countBST += find_greater_than(r->left, x);
    } else if (x > r->val){
        countBST += find_greater_than(r->right, x);
    } else if (x == r-> val) {
        countBST += r->more;
    }
    return countBST;
}

int main() 
{
    int n, option, x, cnt;
    cin >> n;
    TreeNode* root = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &option);
        scanf("%d", &x);
        if (option == 1) {
            insert(root, x);
            int more = 0;
        }
        else if (option == 2) {
            cnt = find_greater_than(root, x);
            printf("%d\n", cnt);
        }
    }
}