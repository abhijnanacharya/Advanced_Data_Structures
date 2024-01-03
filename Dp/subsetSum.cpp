#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> dp;

  bool solve(vector<int> &arr, int n, int index, int target)
  {
    // Base
    if (target == 0)
    {
      return true;
    }

    if (index >= n)
      return false;

    if (dp[index][target] != -1)
      return dp[index][target];

    // Recursive
    // Take
    bool take = false;
    if (arr[index] <= target)
    {
      take = solve(arr, n, index + 1, target - arr[index]) || solve(arr, n, index + 1, target);
    }

    // Not take
    bool notTake = solve(arr, n, index + 1, target);

    return dp[index][target] = (take || notTake);
  }

  int subsetSum(vector<int> &arr, int n, int target)
  {
    dp.assign(n, vector<int>(target + 1, -1));
    return solve(arr, n, 0, target);
  }
};

int main()
{
  int t;
  cin>>t;
  while (t--)
  {
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      arr[i] = x;
    }
    cin >> m;
    Solution ob;
    cout << ob.subsetSum(arr, n, m) << endl;
  }
  return 0;
}
