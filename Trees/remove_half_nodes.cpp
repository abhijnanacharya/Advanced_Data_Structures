//PROBLEM STATEMENT:Remove Half Nodes
//Given A binary Tree. Your task is to remove all the half nodes (which has only one child).

// Example 1:

// Input:
//          7
//        /   \
//       7     8
//      / 
//     2
// Output: 2 7 8 

//Example 2:

// Input:
//          2
//        /   \
//       7     5
//        \      \
//         9      1
//        /  \
//       11   4
// Output: 11 9 4 2 1 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
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
    Node* root = new Node(stoi(ip[0]));
        
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
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
void inorder(Node * node)
{
    if(node==NULL)
        return;
    
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
Node* RemoveHalfNodes(Node* root) ;

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Node * fresh = RemoveHalfNodes(root);
        inorder(fresh);
        cout<<endl;
    }
    return 1;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the root of the modified tree after removing all the half nodes.
Node *RemoveHalfNodes(Node *root)
{
   //add code here.
   if(!root) return root;
   //LEAF
   if(!root->left && !root->right)
        return root;
    //Right Missing
    if(!root->right){
        Node* newNode=root->left;
        free(root);// Avoiding Memory Leak
        return RemoveHalfNodes(newNode);
    }
    //Left Missing 
    if(!root->left){
        Node* newNode=root->right;
        free(root);// Avoiding Memory Leak
        return RemoveHalfNodes(newNode);
    }
    //Both present
    root->left=RemoveHalfNodes(root->left);
    root->right=RemoveHalfNodes(root->right);
    
    return root;
}