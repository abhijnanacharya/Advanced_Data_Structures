//PROBLEM STATEMENT:Largest subarray of 0's and 1's 
//Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

//Example 1:

// Input:
// N = 4
// A[] = {0,1,0,1}
// Output: 4
// Explanation: The array from index [0...3]
// contains equal number of 0's and 1's.
// Thus maximum length of subarray having
// equal number of 0's and 1's is 4.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        // Your code here
        //Optimized Approach: Replace the 0s with -1s. 
        //Store the prefix sum of the array along with the index in a hashmap.
        //If you have any repeated index in the prefix sum that implies there is
        //presence of negative elements that reduce the sum of the prefix sum.
        //Therefore compare store the max length of the subarray.
        //Edge case: Check if anywhere the sum is zero that implies there exists a subarray from index 0
        //therefore you can store the max length of the subarray as i+1.
        //TC:O(N)
        //SC:O(N) for the hashmap
        for(int i=0; i<N; i++){
            arr[i]=arr[i]==0?-1:1;
        }
        unordered_map<int,int> mpp;
        int maxLength=0;
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
            if(sum==0) maxLength=i+1;
            if(mpp.find(sum)!=mpp.end()){
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
    freopen("output.txt","w",stdout);
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends