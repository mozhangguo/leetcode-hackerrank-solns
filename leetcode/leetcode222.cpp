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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int cnt = 0;
        traversalHelper(root, cnt);
        return cnt;
    }

    void traversalHelper(TreeNode* root, int& cnt) {
        cnt++;
        if (root == nullptr) { return; }
        if (root->left != nullptr) traversalHelper(root->left, cnt);
        if (root->right != nullptr) traversalHelper(root->right, cnt);
        return;
    }
};
