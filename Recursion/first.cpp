#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> arr, vector<int> &sol, int i)
{   
    if (i == arr.size())
    {
        for (auto it : sol)
        {
            cout << it << " ";
        }
        if(sol.size()==0) cout<<"{}";
        cout << endl;
        return;
    }
    sol.push_back(arr[i]);
    solve(arr, sol, i + 1);
    sol.pop_back();
    solve(arr, sol, i + 1);
}

int main()
{
    vector<int> sol;
    vector<int> res;
    int i = 0;
    res.push_back(3);
    res.push_back(1);
    res.push_back(2);

    solve(res, sol, i);
    return 0;
}