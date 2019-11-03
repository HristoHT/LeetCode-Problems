/*

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        vector<int> answ;
        
        if(!nums.size()){
			answ.push_back(-1);
			answ.push_back(-1);
			return answ;
		}
        
        while(start<end){
            int mid = (start+end)/2;        	
            if(nums[mid] < target) start = mid + 1;
        	else end = mid;
		}
		if(nums[end]!=target){
			answ.push_back(-1);
			answ.push_back(-1);
		} else {
			answ.push_back(start);
            int result = start;
            start = 0;
            end =nums.size()-1;
            while(start<end) {
                int mid = (start+end)/2;        	
                if(nums[mid] < target) start = mid + 1;
                else if(nums[mid] > target) end = mid;
                else {
                    result = mid;
                    start = mid+1;
                }
            }
            if(result+1<nums.size() && nums[result+1] == target)
			answ.push_back(result+1);
            else answ.push_back(result);
            
		}
		return answ;
    }
};
int main(){
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(2);

	Solution a;
	vector<int>answ = a.searchRange(vec, 3);
	for(int i=0;i<answ.size();i++)cout<<answ[i]<<" ";
	cout<<endl;
}
