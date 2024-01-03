//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    //ll dp[100001][2];
	const int mod = 1e9 + 7;
	ll solve(int i, int j, int n)
	{
	    if(i == n) return 1;
	    // if(dp[i][j] != -1) return dp[i][j];
	    if(j == 0)
	    {
	        return  (solve(i+1,0,n)%mod + solve(i+1,1,n)%mod)%mod;
	    }
	    return  solve(i+1,0,n)%mod;
	}
	ll countStrings(int n) {
	    // code here
	    //memset(dp,-1,sizeof(dp));
	    return solve(0,0,n)%mod;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends