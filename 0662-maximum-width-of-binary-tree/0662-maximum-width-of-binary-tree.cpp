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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxWidth=0;
        if(!root) return maxWidth;
        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();
            long long first = q.front().second;
            long long last;

            while(size--){
                auto [node, idx] = q.front();
                q.pop();
                long long i=idx-first;
                last = i;

                if(node->left) q.push({node->left, 2*i+1});
                if(node->right) q.push({node->right, 2*i+2});
            }
            maxWidth = max(maxWidth, last + 1);
        }
        return maxWidth;
    }
};