//PROBLEM STATEMENT:Largest subarray with 0 sum
//Given an array having both positive and negative integers.
//The task is to compute the length of the largest subarray with sum 0.

//Example 1:

// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5
// Explanation: The largest subarray with
// sum 0 will be -2 2 -8 1 7.

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/
//Optimized Approach: 
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int , int >mpp;
        int sum=0;
        int maxLength=0;
        for(int i=0; i<n ;i++){
            sum+=A[i];
            if(sum==0)
                maxLength=i+1;
            else if(mpp.find(sum)!=mpp.end()){
                maxLength=max(maxLength, i-mpp[sum]);
            }else{
                mpp[sum]=i;
            }
        }
        return maxLength;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends