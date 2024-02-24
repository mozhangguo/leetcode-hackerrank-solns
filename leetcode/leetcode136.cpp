class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) return *nums.begin();
        int c = 0;
        for (auto num : nums) c = c^num;
        return c;
    }
};
