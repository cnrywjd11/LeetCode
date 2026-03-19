class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            int sumWithoutCarry = (a ^ b);
            a = sumWithoutCarry;
            b = carry;
        }
        return a;
    }
};