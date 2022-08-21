//PROBLEM STATEMENT:K distance from root
//Given a Binary Tree of size N and an integer K. 
//Print all nodes that are at distance k from root (root is considered at distance 0 from itself). 
//Nodes should be printed from left to right. If k is more that height of tree, nothing should be printed.

// For example, if below is given tree and k is 2. Output should be 4 5 6.

//           1
//        /     \
//      2        3
//    /         /   \
//   4        5    6 
//      \
//       8


//Example 1:

// Input:
// K = 0
//       1
//     /   \
//    3     2
// Output: 1

// Example 2:

// Input:
// K = 3
//         3
//        /
//       2
//        \
//         1
//       /  \
//      5    3
// Output: 5 3


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
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

vector<int> Kdistance(struct Node *root, int k);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k;
		scanf("%d ",&k);
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = Kdistance(root, k);
        for(int i = 0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
    return 1;
}
// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// function should print the nodes at k distance from root
void solve(Node* root, int k, vector<int>& ans){
    if(!root) return; //BASE
    if(k==0){
        ans.push_back(root->data);
        return; //Save redundant calls :)
    }
    //RECURSIVE CALLS
        solve(root->left, k-1, ans);
        solve(root->right, k-1, ans);
}
vector<int> Kdistance(struct Node *root, int k)
{
  // Your code here
  vector<int>ans;
  solve(root,k,ans);
  return ans;
}