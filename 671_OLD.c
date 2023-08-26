#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int main() {
    
}

int findSecondMinimumValue(struct TreeNode* root) {
    /*struct TreeNode *min = NULL;
    
    if ( root->left == NULL ) {
        return -1;
    } else
    if ( root->val == root->left->val && root->val == root->right->val ) {
        return -1;
    } else
    if ( root->val == root->left->val ) {
        return root->right->val;
    } else {
        return root->left->val;
    }*/

    struct TreeNode *min = NULL;
    struct TreeNode *minPrev = NULL;

    min = root;

    while ( min->left != NULL ) {
        minPrev = min;
        if ( min->left->val == root->val ) {
            min = min->right;
        } else
        if ( min->right->val == root->val ) {
            min = min->left;
        } else
        if ( min->left->val < min->right->val ) {
            min = min->left; 
        } else
        if ( min->right->val < min->left->val ) {
            min = min->right;
        }
    }

    if ( minPrev->val == root->val ) {
        return -1;
    }
    return minPrev->val;
}