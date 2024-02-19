class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majnum_cnt = 0;
        int majnum_holder = 0;
        for (auto num : nums) {
            if (majnum_cnt == 0) majnum_holder = num;
            majnum_cnt += (num == majnum_holder) ? 1 : -1;
        }
        return majnum_holder;
    }
};
