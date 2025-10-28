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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>s;
        TreeNode* temp = root;
        while(true){
            if(temp){
                s.push(temp);
                temp = temp->left;
            }
            else{
                if(s.empty()) break;
                temp = s.top();
                s.pop();
                ans.push_back(temp->val);
                temp = temp->right;
            }
        }
        return ans;
    }
};