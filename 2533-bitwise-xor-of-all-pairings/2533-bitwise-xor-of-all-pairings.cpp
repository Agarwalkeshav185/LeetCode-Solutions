class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if( n%2 == 0 && m%2 == 0) return 0;

        int a = 0, b=0;
        for(auto it: nums2)  a ^= it;
        for(auto it: nums1)  b^= it;

        if( n&1 && m%2==0)
            return a;
        else if(m&1 && n%2==0)
            return b;
        return a^b;
    }
};