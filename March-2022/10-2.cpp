class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int findPeakElement(vector<int>& nums) {
        // write code here
        int l=0;
        int r=nums.size()-1;
        if(l>=r) return 0;
        while(l<r) {
            int mid=l+r>>1;
            if(nums[mid]<nums[mid+1]) {
                l=mid+1;
            }
            else r=mid;
        }
        return l;
    }
};


