int maxPathSum1(struct TreeNode* root, int *max){
    if (!root)
        return 0;
    else
    {
        int left, right;
        left = maxPathSum1(root->left, max);
        right = maxPathSum1(root->right, max);
        if (left + right + root->val > *max)
        {
            *max = left + right + root->val;
        }
        if (right + root->val > 0 || left + root->val > 0)
            return (left + root->val > right + root->val ? left + root->val : right + root->val);
        else
            return 0;
    }
    
}

int maxPathSum(struct TreeNode* root){
    int max = INT_MIN;
    if (!root)
        return 0;
    maxPathSum1(root, &max);
    return max;
}