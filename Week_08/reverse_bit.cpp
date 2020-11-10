class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t s = 0, p = 31;
        while (n != 0) {
            s += ((n & 1) << p);
            n = n >> 1;
            p --;
        }
        return s;
    }
};
