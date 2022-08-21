/*PROBLEM STATEMENT:Two Mirror Trees
Given a Two Binary Trees, write a function that returns true if one is mirror of other, else returns false.
Example 1:

Input:
T1:     1     T2:     1
      /   \         /   \
     2     3       3     2
Output: 1
Example 2:

Input:
T1:     10      T2:   10
       /  \          /  \
      20  30        20  30
     /  \          /  \
    40   60       40  60
Output: 0

*/
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
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
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */
class Solution
{
    public:
    int areMirror(Node* a, Node* b) {
    // Your code here
    //BASE CASE 1: Both nodes are NULL RETURN 1 
    if(!a && !b) return 1;
    //BASE CASE 2: Either of the node is NULL, definitely NOT MIRROR IMAGE
    if(!a || !b) return 0; 
    //Validation step
    if(a->data != b->data)
        return 0;
    //RECURSIVELY TRAVEL and Validate Left and Right && Validate Right and Left
    return areMirror(a->left, b->right)&& areMirror(a->right, b->left);
        
    }

};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);

        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);

        Solution ob;
        cout << ob.areMirror(root1, root2) << "\n";
    }
    return 0;
}
// } Driver Code Ends