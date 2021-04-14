//Recursive

class Solution
{
    public:
    //Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root)
    {
      // Your code here
        vector <int> ans;
    
        if (root == NULL){
            return ans;
        }
        
        vector <int> x;
        x  = inOrder(root->left);
        ans.insert(ans.end(),x.begin(),x.end());
        
        ans.push_back(root->data);
        
        x = inOrder(root->right);
        ans.insert(ans.end(),x.begin(),x.end());
        
        return ans;
    }
};

//Iterative

vector<int> inOrder(Node* root)
{
    //code here
    stack<Node *> st;
    Node *curr = root;
    vector<int> ans;
    
    while(curr!=NULL || st.empty()==false){
        
        while(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }
        
        
        curr = st.top();
            st.pop();
            ans.push_back(curr->data);
        
        curr=curr->right;
    }
    
    return ans;
}