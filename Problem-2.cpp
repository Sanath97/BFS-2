// Time Complexity : O(n+n+n+n) where each n is for depth of two nodes and parents of two nodes
// Space Complexity : O(d) d is depth of tree this is size for DFS stack
// Did this code successfully run on Leetcode : yes
// Any problem you faced while coding this : no
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
    int depth(TreeNode* root, int node, int depth_val)
    {
        if(root == NULL)
            return 0;

        if(root->val == node)
            return depth_val;
        
        int dleft = depth(root->left, node, depth_val+1);
        int dright = depth(root->right, node, depth_val+1);
        return dleft+dright;
    }

    TreeNode* parent(TreeNode* root, int node, TreeNode* prev)
    {
        if(root == NULL)
            return NULL;

        if(root->val == node)
            return prev;
        
        prev = root;
        TreeNode* l = parent(root->left, node, root);
        TreeNode* r = parent(root->right, node, root);
        return (l==NULL)? r:l ;
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        int d1 = depth(root, x, 0);
        int d2 = depth(root, y, 0);
        TreeNode* p1 = parent(root, x, NULL);
        TreeNode* p2 = parent(root, y, NULL);
        if(d1 == d2 && p1 != p2)
            return true;
        return false;
    }
};