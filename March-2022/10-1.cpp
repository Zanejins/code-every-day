class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        // write code here
        int l=0;
        int r=nums.size()-1;
        if(l>r) return -1;
        while(l<r) {
            int mid=l+r >> 1;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        if(nums[l]!=target) return -1;
        else return l;
    }
};
