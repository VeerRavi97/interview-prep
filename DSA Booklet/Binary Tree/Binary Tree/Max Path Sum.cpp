
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode *root, int &global_max)
{
    if (!root)
        return 0;
    int left = dfs(root->left, global_max);
    int right = dfs(root->right, global_max);
    int op1 = root->val;
    int op2 = root->val + left;
    int op3 = root->val + right;
    int op4 = root->val + left + right;
    int branchSum = max(op1, max(op2, op3));
    int local_max = max(branchSum, op4);
    global_max = max(global_max, local_max);
    return max(branchSum, 0);
}
int maxPathSum(TreeNode *root)
{
    int global_max = INT_MIN;
    dfs(root, global_max);
    return global_max;
}