//Problem Statement2: You are given a 0-indexed array nums of length n. You are initially positioned at nums[0]. Each element nums[i] represents the maximum length of a forward jump from index i. Return the minimum number of jumps to reach nums[n - 1].

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0; 

        int jumps = 0;
        int current_end = 0; 
        int farthest = 0; 

        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]); 
            if (i == current_end) { 
                jumps++;
                current_end = farthest; 
                if (current_end >= n - 1) break; 
            }
        }

        return jumps;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << solution.jump(nums1) << endl; 

    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << solution.jump(nums2) << endl; 

    return 0;
}