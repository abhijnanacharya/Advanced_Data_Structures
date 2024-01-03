//PROBLEM STATEMENT: Find triplets with zero sum
//Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero.

// Example 1:

// Input: n = 5, arr[] = {0, -1, 2, -3, 1}
// Output: 1
// Explanation: 0, -1 and 1 forms a triplet
// with sum equal to 0.

//Example 2:

// Input: n = 3, arr[] = {1, 2, 3}
// Output: 0
// Explanation: No triplet with zero sum exists. 

// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

 // } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    //Naive implementation: Use three loops i,j,k to find triplets whose sum is equal to 0. 
    //O(N^3) BAD!!! :(
    //Optimized implementation: First and foremost sort the entire array. 
    //Then start a loop from 0 to n-2 and use a high and a low pointer 
    //that points to element after ith index and the right pointer to the last index of the array
    //Now check if arr[i] == -(arr[l]+arr[r]) {arr[i]+arr[j]+arr[k]==0} return true
    //else if arr[i]>-(arr[l]+arr[r]) then decrement the right pointer in order to reduce the overall sum
    //otherwise increment the left pointer
    //TC:O(N^2)
    //SC:O(1)

    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        sort(arr, arr+n);
        for(int i=0 ;i<n-2; i++){
            int l=i+1;
            int r=n-1;
            
            while(l<r){
                if(arr[i]== -(arr[l]+arr[r]))
                    return true;
                else if(arr[i]> -(arr[l]+arr[r]))
                    r--;
                else
                    l++;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}  // } Driver Code Ends