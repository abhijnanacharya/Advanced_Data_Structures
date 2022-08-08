//PROBLEM STATEMENT: Two Sum
//Given an array of positive integers and an integer. Determine whether or not 
//there exist two elements in A whose sum is exactly equal to that integer.

// Example 1:

// Input:
// N = 6, X = 16
// A[] = {1,4,45,6,10,8}
// Output: Yes
// Explanation: 10 and 6 are numbers
// making a pair whose sum is equal to 16.



// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
// User function template for C++

// A[] : the input array of positive integers
// N : size of the array arr[]
// X : the required sum

//Semi Optimized: Sort and use two pointers to find the reqd sum. O(N*Log N)
//Optimized: Use a HashMap to find the complement of the sum. A+B=X => B= X-A
//If you find a number that is already present in the hashMap return true.
//Otherwise exit from the loop and return false.
//TC: O(N)
//SC:O(N)

class Solution
{
    public:
    bool keypair(vector<int> A, int N, int X)
    {
        // Your code goes here
        unordered_map<int, int >mpp;
        for(int i=0 ; i<N; i++){
            int to_Be_Searched=X-A[i];
            if(to_Be_Searched>=0){
                if(mpp.find(to_Be_Searched)!=mpp.end()){
                    return true;
                }else{
                    mpp[A[i]]=i;
                }
            }
        }
        return false ;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> array(n);
        Solution ob;
        
        for (int i = 0; i < n; i++) cin >> array[i];
            cout << (ob.keypair(array, n, x) ? "Yes" : "No") << "\n";
    }
    return 0;
}
  // } Driver Code Ends