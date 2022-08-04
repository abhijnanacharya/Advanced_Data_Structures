//PROBLEM STATEMENT:Count the number of possible triangles
//Given an unsorted array arr[] of n positive integers. 
//Find the number of triangles that can be formed with three 
//different array elements as lengths of three sides of triangles. 

// Input: 
// n = 5
// arr[] = {6, 4, 9, 7, 8}
// Output: 
// 10
// Explanation: 
// There are 10 triangles
// possible  with the given elements like
// (6,4,9), (6,7,8),...

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.

//Approach: On Sorting the array, take the last element as the largest side and place smallest at 0 and the middle element 
//at largest-1. Check if the condition arr[l]+arr[r]> arr[largest] is satisfied and if it is satisfied then all 
//the elements from l to r-1 will also satisfy the condition as the array is sorted. Increment and count by (r-l) and 
//decrement r pointer.
//If the condition is not satisfied then increment l pointer and check. DONE!! 
//TC: O(N^2)
//SC: O(1)
    int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        sort(arr, arr+n);
        int count=0;
        for(int i=n-1; i>=2; i--){
            int l=0;
            int r=i-1;
            
            while(l<r){
                if(arr[l]+arr[r]> arr[i]){
                    count+=(r-l);
                    r--;
                }else{
                    l++;
                }
            }
        }
        return count;
    }
};


// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}  // } Driver Code Ends