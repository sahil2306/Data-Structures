/*
Input:
        19
     /     \
    10      8
  /    \
 11    13
Output: 11 13 10 8 19
*/

vector <int> postOrder(Node* root)
{
  // Your code here
  vector <int> ans;
    
        if (root == NULL){
            return ans;
        }
        
        vector <int> x;
        x  = postOrder(root->left);
        ans.insert(ans.end(),x.begin(),x.end());
        
        x = postOrder(root->right);
        ans.insert(ans.end(),x.begin(),x.end());
        
        ans.push_back(root->data);
        
        return ans;
}