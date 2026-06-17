/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int solve(TreeNode* root,int maxSoFar){
        if(root == nullptr) return 0;
        int cnt = 0;
        if(root->val >= maxSoFar){
            cnt = 1;
            maxSoFar = root->val;
        }
        cnt += solve(root->right,maxSoFar);
        cnt += solve(root->left,maxSoFar);
        return cnt;
    }
    int goodNodes(TreeNode* root) {
        return solve(root,root->val);
    }
};