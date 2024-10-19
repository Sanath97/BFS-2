// Time Complexity : O(n) where n is number of nodes in the binary tree
// Space Complexity : O(d) d is the diameter of the tree or level with maximum number of nodes
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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=size-1;i>=0;i--)
            {
                TreeNode* top = q.front();
                q.pop();
                if(i==0)
                    res.push_back(top->val);
                if(top->left!=NULL)
                    q.push(top->left);
                if(top->right!=NULL)
                    q.push(top->right);
            }
        }
        return res;
    }
};