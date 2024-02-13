class Solution {
public:
    string intToRoman(int num) {
        if (num > 3999 || num < 1) return ""; // beyond constraints
        
        int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string syms[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};\

        string ans;
        
        for (int i = 0; i < 13 && num > 0; i++) {
            while (vals[i] <= num) {
                num = num - vals[i];
                ans += syms[i];
            }
        }

        return ans;
    }
};