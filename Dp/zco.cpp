// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//   public:
//   int solve(vector<int>arr, int n, int i){
//     //Base
//     // if(idx<=2)
//     //   return arr[idx];
//     // if(dp[idx]!=-1) return dp[idx];
//     // //Recursive
//     // return dp[idx]= arr[idx]+min({
//     //                                 solve(arr,i-1,n,dp),
//     //                                 solve(arr,i-2,n,dp),
//     //                                 solve(arr,i-3,n,dp)
//     //                               });
//     //Base
//     if(i<3) return min({arr[0],arr[1],arr[2]});

//     //Recursive
//     int ans=arr[i]+min({solve(arr,n,i-1),solve(arr,n,i-2),solve(arr,n,i-3)});
//     cout<<"Ans :"<<ans<<endl;
//     return ans;

//   }
//   int pickMinTasks(vector<int> tasks, int n){
//     return solve(tasks,n,n-1);

    
//   }
// };

// int main(){

//   int t;
//   cin>>t;

//   while(t--){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//       int x;
//       cin>>x;
//       arr.push_back(x);
//     }
//      Solution ob;
//         int ans = ob.pickMinTasks(arr,n);
//         cout << ans << "\n";
//   }

//  return 1;
// }


// // #include<bits/stdc++.h>

// // using namespace std;

// // int main()
// // {
// // 	// freopen("input.txt", "r", stdin);
// // 	// freopen("output.txt", "w", stdout);

// // 	int n;
// // 	cin >> n;

// // 	int a[n], dp[n];

// // 	for (int i = 0; i < n; i++) {
// // 		cin >> a[i];
// // 	}

// // 	dp[0] = a[0];
// // 	dp[1] = a[1];
// // 	dp[2] = a[2];

// // 	for (int i = 3; i < n; i++) {
// // 		dp[i] = min({dp[i - 1], dp[i - 2], dp[i - 3]}) + a[i];
// // 	}

// // 	for (int i = 0; i < n; i++) {
// // 		cout << dp[i] << " ";
// // 	} cout << '\n';

// // 	cout << min({dp[n - 1], dp[n - 2], dp[n - 3]});










// // 	return 0;
// // }



#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int min_supw_minutes(int N, vector<int>& minutes, int day, int consecutive_days) {
    // Base case: No more days left
    if (day >= N) {
        return 0;
    }

    // If Nikhil takes SUPW duty on the current day
    int option1 = minutes[day] + min_supw_minutes(N, minutes, day + 1, 1);

    // If Nikhil skips SUPW duty on the current day
    int option2 = INT_MAX;
    if (consecutive_days < 2) {
        option2 = min_supw_minutes(N, minutes, day + 1, consecutive_days + 1);
    }

    // Choose the minimum of the two options
    return min(option1, option2);
}

int main() {
    // Input
    int N;
    cin >> N;

    vector<int> minutes(N);
    for (int i = 0; i < N; ++i) {
        cin >> minutes[i];
    }

    // Call the function with initial parameters
    int result = min_supw_minutes(N, minutes, 0, 0);

    // Output the result
    cout << result << endl;

    return 0;
}
