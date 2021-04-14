/*
Input:
        1
     /      \
   10      39
  /
5

Output: 4

*/

int getSize(Node* root)
{
   // Your code here
   if(root==NULL){
       return 0;
   }
   return(1+getSize(root->right)+getSize(root->left));
}