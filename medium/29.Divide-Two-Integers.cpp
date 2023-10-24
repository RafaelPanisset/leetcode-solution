class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long long  ans = 0;
        long divindTemp = abs(dividend), divisorTemp = abs(divisor);
        while (divindTemp >= divisorTemp) {
            int currAns = 1;
            long currValue = divisorTemp;
            while (currValue << 1 <=  divindTemp) {
                currValue <<= 1;
                currAns <<= 1;
            }
            divindTemp -= currValue;
            ans += currAns;
        }
        int signalOk = (divisor > 0) == (dividend > 0);
        if (signalOk)
            return ans;

        if (ans == INT_MIN && divisor == -1)
            return INT_MAX;
        else
            return -ans;
    }
};