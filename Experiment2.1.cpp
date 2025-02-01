//Problem Statement1: Given an array of integers nums and an integer target, return the indices of the two numbers such that they add up to target. Each input has exactly one solution, and you cannot use the same element twice.
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; 
            if (seen.find(complement) != seen.end()) { 
                return {seen[complement], i};
            }
            seen[nums[i]] = i; 
        }
        return {}; 
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "[" << result1[0] << ", " << result1[1] << "]" << endl;

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "[" << result2[0] << ", " << result2[1] << "]" << endl;

    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "[" << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}
