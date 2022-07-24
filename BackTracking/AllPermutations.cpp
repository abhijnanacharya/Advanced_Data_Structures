#include<bits/stdc++.h>
using namespace std;

void PermutateAll(int idx, vector<int> &nums, vector<vector<int>> &ans){
	//Base Condition: If the index reaches the end of the array no more combinations 
	//can be constructed so push it in a result vector
	if(idx==nums.size()){
		ans.push_back(nums);
		return;
	}
	//Recursive Case: For each index swap with all the valid postions and call the recursive case
	for(int i=idx;i<nums.size();i++){
		swap(nums[idx],nums[i]);
		//Call the Recursive function on the following index
		PermutateAll(idx+1,nums,ans);
		//BackTracking Step: The Following line is executed to revert back the changes done to the array by the above swap function	
		swap(nums[idx],nums[i]);
	}
}
int main(){
	int n;
	cin>>n;
	vector<int>nums; int x;
	for(int i=0;i<n;i++){
		cin>>x;
		nums.push_back(x);

	}
	cout<<endl;
	vector<vector<int>>ans;
	PermutateAll(0,nums,ans);

	for (int i = 0; i < ans.size(); i++){
      for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j];
        cout << endl;
    }

    return 0;

}