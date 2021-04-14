/*
Input:
       1
     /   \
    4     3
   /  \
  5    N
Output: 0
Explanation: Here, 1 is the root node
and 4, 3 are its child nodes. 4 + 3 =
7 which is not equal to the value of
root node. Hence, this tree does not
satisfy the given conditions.
*/
int isSumProperty(Node *root)
{
 // Add your code here
    if(root==NULL){
        return 1;
    }
    
    if(root->right==NULL and root->left==NULL){
        return 1;
    }
    
    int sum=0;
    if(root->right!=NULL){
        sum+=root->right->data;
    }
    if(root->left!=NULL){
        sum+=root->left->data;
    }
    
    return( root->data==sum and isSumProperty(root->right) and isSumProperty(root->left));
    
}