//Heightof a binary tree
/*
Input:
      1
    /  \
   2    3
   
Output: 2
*/

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* root){
        // code here 
        
        if(root==NULL){
            return 0;
        }
        return max(height(root->right), height(root->left))+1;
        
    }
};