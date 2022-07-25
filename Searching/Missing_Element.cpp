// PROBLEM STATEMENT: Index Of an Extra Element
// Given two sorted arrays of distinct elements. There is only 1 difference between the arrays.
// First array has one element extra added in between. Find the index of the extra element.
// Input:
// N = 7
// A[] = {2,4,6,8,9,10,12}
// B[] = {2,4,6,8,10,12}
// Output: 4
// Explanation: In the second array, 9 is
// missing and it's index in the first array
// is 4.
// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 2<=N<=104
// 1<=Ai<=105


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    int findExtra(int a[], int b[], int n) {
        // add code here.
        // int i=0; 
        // int j=0;
        
        // while(i<n && j<n-1){
        //     if(a[i]!=b[j])
        //         return i;
        //     i++;j++;
        //}
        //The above is the most naive solution; Take two pointers and since both are
        //sorted the different element will point to the extra element
        //The below is the most efficient solution as TC=O(log N) 
        //Since the array is sorted you can use BS to extract the mid and check if
        //it is the same; If found same that means the missing element HAS to be after
        //mid index hence discarding the previous section Therefore low=mid+1
        //Similarly if it is different that means that it can be the different element
        //OR The different element had occurred previously Therefore store the index as a
        //Answer and narrow your search space by discarding elements to the right of mid. :)
        int index=n;
        int low=0;
        int high=n-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(a[mid]==b[mid]){
                low=mid+1;
            }else{
                index=mid;
                high=mid-1;
            }
        }
        return index;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        Solution obj;
        cout << obj.findExtra(a, b, n) << endl;
    }
}  // } Driver Code Ends