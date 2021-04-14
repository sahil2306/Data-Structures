#include<bits/stdc++.h>

// Input:
//         1      
//       /          
//     4    
//   /    \   
// 4       2
// Output: 1 4 4 2 

//Recursive

vector <int> preorder(Node* root)
{
  // Your code here
  //pre()
    vector <int> ans;
    
    if (root == NULL){
        return ans;
    }
    
    vector <int> x;
    ans.push_back(root->data);
    x  = preorder(root->left);
    ans.insert(ans.end(),x.begin(),x.end());
    x = preorder(root->right);
    ans.insert(ans.end(),x.begin(),x.end());
    
    return ans;
}


//Iterative
vector <int> preorder(Node* root)
{
  // Your code here
  //pre()
    vector <int> ans;
    
    if (root == NULL){
        return ans;
    }
    
    vector <int> x;
    ans.push_back(root->data);
    x  = preorder(root->left);
    ans.insert(ans.end(),x.begin(),x.end());
    x = preorder(root->right);
    ans.insert(ans.end(),x.begin(),x.end());
    
    return ans;
} 