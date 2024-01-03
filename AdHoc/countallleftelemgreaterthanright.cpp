/*  PROBLEM STATEMENT: Let's assume you have two arrays and you want to count all possible pairs of elements where ArrLeft[i]>ArrRight[j]




*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int countLElemGreatertThanR(vector<int> arr1, vector<int> arr2, int n, int m)
  {
    int L, R = 0;
    int xcount = 0;
    while (L < n)
    {
      if (arr1[L] > arr2[R])
      {
        xcount += (n - L);
        R++;
      }
      else
      {
        L++;
      }
    }
    return xcount;
  }
};

int main()
{
  int n, m;

  cin >> n >> m;
  vector<int> arr1(n);
  vector<int> arr2(m);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    arr1[i] = x;
  }

  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    arr2[i] = x;
  }
  Solution ob;
  cout << ob.countLElemGreatertThanR(arr1, arr2, n, m) << endl;
  return 0;
}