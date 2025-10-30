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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
        return true;

        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()){
            TreeNode* root1 = q1.front();
            q1.pop();

            TreeNode* root2 = q2.front();
            q2.pop();

            if(root1 -> val != root2 -> val)
            return false;

            // Check left child mismatch
            if((root1 -> left && !root2 ->left) || (!root1 -> left && root2 ->left))
            return false; 

            // Check right child mismatch
            if((root1 -> right && !root2 -> right) || (!root1 -> right && root2 -> right))
            return false; 

            // Push children if both exist
            if(root1 -> left && root2 -> left){
                q1.push(root1 -> left);
                q2.push(root2 -> left);
            }

            if(root1 -> right && root2 -> right){
                q1.push(root1 -> right);
                q2.push(root2 -> right);
            }
        }

        return true;
    }
};