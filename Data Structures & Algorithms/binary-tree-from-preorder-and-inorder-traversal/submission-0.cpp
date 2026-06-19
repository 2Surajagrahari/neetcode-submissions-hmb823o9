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
    // Helper function to keep track of indices
    TreeNode* construct(vector<int>& preorder, int preStart, int preEnd, 
                        vector<int>& inorder, int inStart, int inEnd) {
        
        // Base case: if there are no elements left to process
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        // 1. The first element of the current preorder range is ALWAYS the root
        TreeNode* root = new TreeNode(preorder[preStart]);

        // 2. Find where this root value sits in the inorder array
        int inRootIndex = inStart;
        while (inRootIndex <= inEnd) {
            if (inorder[inRootIndex] == root->val) {
                break; // Found the root in inorder array
            }
            inRootIndex++;
        }

        // 3. Count how many nodes belong to the left subtree
        int numsLeft = inRootIndex - inStart;

        // 4. Recursively build the left and right subtrees by adjusting the index ranges
        root->left = construct(preorder, preStart + 1, preStart + numsLeft, 
                               inorder, inStart, inRootIndex - 1);
                               
        root->right = construct(preorder, preStart + numsLeft + 1, preEnd, 
                                inorder, inRootIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return construct(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};
