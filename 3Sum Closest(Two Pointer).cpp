//Given an integer array nums of length n and an integer target,
//find three integers in nums such that the sum is closest to target.
//ex: nums = [-1,2,1,-4], target = 1
//Output: 2 (2+1+(-1))
//Two Pointer
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ansSum = 100000;
        for(int i=0;i<nums.size()-2;++i){
            int realtarget = target - nums[i];
            int Start = i+1, End = nums.size()-1;
            while(Start < End){
                int sum = nums[Start] + nums[End];
                if(sum < realtarget){
                    Start++;
                    int total = sum+nums[i];
                    ansSum = (abs(ansSum-target) < abs(total-target)) ? ansSum : total;
                }
                else if(sum == realtarget){
                    return target;
                }
                else{
                    End--;
                    int total = sum+nums[i];
                    ansSum = (abs(ansSum-target) < abs(total-target)) ? ansSum : total;
                }
            }
        }
    return ansSum;
}
int main(){
	vector<int> v{-1,2,1,-4};
	cout << threeSumClosest(v,1);
}
