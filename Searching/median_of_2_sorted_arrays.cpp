//PROBLEM STATEMENT: Median of 2 Sorted Arrays of Different Sizes 
//Given two sorted arrays array1 and array2 of size m and n respectively.
//Find the median of the two sorted arrays.

//Example 1:
// Input:
// m = 3, n = 4
// array1[] = {1,5,9}
// array2[] = {2,3,6,7}
// Output: 5
// Explanation: The middle element for
// {1,2,3,5,6,7,9} is 5

//APPROACH: USE 2 Pointers to merge both arrays in sorted format in one pass.
//Depending on the size of the array return (k/2)th element or avg of k/2th & (k/2)+1th element.
//TC:O(N)
//SC:O(N)


// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int ptr1=0;
        int ptr2=0;
        vector<int>res;
        while(ptr1<array1.size() && ptr2<array2.size()){
            if(array1[ptr1]<array2[ptr2]){
                res.push_back(array1[ptr1]);
                ptr1++;
            }else{
                res.push_back(array2[ptr2]);
                ptr2++;
            }
        }
        while(ptr1<array1.size()){
            res.push_back(array1[ptr1]);
            ptr1++;
        }
        while(ptr2<array2.size()){
            res.push_back(array2[ptr2]);
            ptr2++;
        }
        double ans;
        int k=res.size();
        if(k%2==0){
            ans= (res[k/2]+res[(k/2) - 1]);
            return ans/2;
        }else{
            ans=res[k/2];
            return ans;
        }
        
    
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends