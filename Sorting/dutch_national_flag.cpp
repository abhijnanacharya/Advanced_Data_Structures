//PROBLEM STATEMENT:Closet 0s 1s and 2s 
//Given an array of 0s, 1s, and 2s. Arrange the array elements 
//such that all 0s come first, followed by all the 1s and then, all the 2s.

// Example 1:

// Input: N = 5, arr[] = {0, 2, 1, 2, 0}
// Output: 0 0 1 2 2


// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    // The function should do the stated modifications in the given array arr[]
    // Do not return anything.
    
    // arr[]: Input Array
    // N: Size of the Array arr[]
    //Function to segregate 0s, 1s and 2s in sorted increasing order.
    //Optimized Approach: Consider three pointers to segregate the elements in the array.
    // Step 1: If you find 0 then swap the element at low with mid and increment both
    //Step 2: If you find 1 then just increment mid by 1
    //Step 3 : If you find 2 then swap mid with high and decrement high--

    //Logic: 0- low-1 is for 0
    //high+1 to n is for 2
    void segragate012(int arr[], int N)
    {
        // Your Code Here
        int low=0;
        int mid=0;
        int high=N-1;
        while(mid<=high){
            switch(arr[mid]){
            
            case 0:
                swap(arr[low++],arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid],arr[high--]);
                break;
            }
        }
        
    }
};

// { Driver Code Starts.
int main() {

    int T;
    cin >> T;

    while(T--){
        int N;
        cin >>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin >> A[i];
        }

        Solution ob;
        ob.segragate012(A, N);

        for(int i=0;i<N;i++){
            cout << A[i]  << " ";
        }

        cout << endl;
        
        
    }

}
  // } Driver Code Ends