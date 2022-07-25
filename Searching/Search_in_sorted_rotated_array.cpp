//PROBLEM STATEMENT:Search an element in sorted and rotated array 
//Given a sorted and rotated array A of N distinct elements which 
//is rotated at some point, and given an element K. The task is to 
//find the index of the given element K in the array A.
//Example 1:

// Input:
// N = 9
// A[] = {5 6,7,8,9,10,1,2,3}
// K = 10
// Output: 5
// Explanation: 10 is found at index 5.

//NAIVE: USE LINEAR Search to find the index of the given element
//EFFICIENT: Take into consideration the first example, if you want to search 10, then using BS the mid=(0+8)/2=>4,
//then check if mid element greater than low element, which implies that array is sorted till mid element[5,6,7,8,9]
//Then enter the section and check if element to be searched is greater than low and less than mid and discard section after mid
//otherwise discard section before mid.
//Similarly write the else statement IF ELEMENTS ARE SORTED AFTER MID.
//TC:O(log N)
//SC:O(1)

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> vec, int K) {
    //code here
    int low=0;
    int high=vec.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(vec[mid]==K)
            return mid;
        else if(vec[low]<=vec[mid]){
            //LOW TO MID IS SORTED<MONOTONICALLY INCREASING>
            if(vec[low]<=K && vec[mid]>K)
                high=mid-1;
            else
                low=mid+1;
        }else{
            //MID TO HIGH IS SORTED
            if(K>vec[mid] && K<=vec[high])
                low=mid+1;
            else
                high=mid-1;
        }
    }
    return -1;
}