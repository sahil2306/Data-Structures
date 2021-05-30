// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

 // } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
    public:

    vector<int> v;
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2)
    {
       //Your code here
       
        if(root==NULL){return NULL;}
        
        if(root->data==n1 || root->data==n2){
            v.push_back(root->data);
            return root;
        }
        
        Node* lca1 = lca(root->right, n1,n2);
        Node* lca2 = lca(root->left, n1,n2);
        
        if(lca1!=NULL && lca2!=NULL){v.push_back(root->data);return root;}
        
        if(!lca1){v.push_back(lca2->data);return lca2;}
        else{v.push_back(lca1->data);return lca1;}
        
    }

    void print(){
        cout<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};

// { Driver Code Starts.

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        cout<<"HII";
        int a,b;
        a=40;
        b=60;
        //cout<<"Enter Input : "<<endl;
        //cin>>a>>b;
        string st;
        cout<<"Enter string : ";
        getline(cin,st);
        cout<<st<<endl;
        Node* root = buildTree(st);
        Solution ob;
        cout<<"Output : "<<endl;
        cout<<ob.lca(root,a,b)->data<<endl;
        ob.print();
    }
    return 0;
}
  // } Driver Code Ends