class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param cost int整型vector 
     * @return int整型
     */
    int minCostClimbingStairs(vector<int>& cost) {
        // write code here
        int len=cost.size();
        if(len==1) return cost[0];
        vector<int> dp(len+1);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=len;i++) {
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[len];
        
    }
};
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
10-3.cpp [unix] (07:59 01/01/1970)                                       0,1 All
-- INSERT --

