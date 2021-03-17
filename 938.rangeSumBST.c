/*
938. Range Sum of BST
Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range [low, high].

 

Example 1:


Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Example 2:


Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
 

Constraints:

The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void help(struct TreeNode* root,int low,int high,int *isum)
{
   
     if(root!=NULL)
    {
         if(root->val>=low && root->val<=high)
            (*isum)+=root->val;
        help(root->left,low,high,isum);
        
        help(root->right,low,high,isum);
       // printf("%p\t",*isum);
        
            
    }
}
int rangeSumBST(struct TreeNode* root, int low, int high){
    int isum=0;
    if(root==NULL)
        return 0;
    help(root,low,high,&isum);
    printf("%d\t",isum);
    return isum;
}
