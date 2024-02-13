class Solution {
public:
    int reverse(int x) {
        if (x == 0) return x;
        long xd = x;
        bool negFlag = signbit(xd); 
        xd = negFlag ? -xd : xd;
        
        long val = 0;
        int i = log10(xd);
        while (xd != 0) {
            val += pow(10, i) * (xd % 10);
  
            xd = xd/10;
            i--;
        }
        
        if (val > INT_MAX || val < INT_MIN) return 0;
        
        return negFlag ? -val : val;
    }

    int reverse(int x) {
        int rev = 0;

        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }

        return rev;
    }
};