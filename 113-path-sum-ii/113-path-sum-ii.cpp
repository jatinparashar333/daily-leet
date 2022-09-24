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
    vector<vector<int>> vec;
    int sum=0;
    void func(TreeNode* root,vector<int> &v,int k){
        if(!root){
            
            return;
        }
        sum+=root->val;
        v.push_back(root->val);
        if(sum==k && !(root->left) && !(root->right)){
                vec.push_back(v);
            }
        
        func(root->left,v,k);
        
       if(root->right){
            func(root->right,v,k);
       }
        sum-=root->val;
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return vec;
        }
        if(root->val==targetSum && !(root->left) && !(root->right)){
            vec.push_back({root->val});
            return vec;
        }
        vector<int> v;
        func(root,v,targetSum);
        return vec;
    }
};