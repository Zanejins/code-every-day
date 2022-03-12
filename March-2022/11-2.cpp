class Solution {
public:
    /**
     * 旋转数组
     * @param n int整型 数组长度
     * @param m int整型 右移距离
     * @param a int整型vector 给定数组
     * @return int整型vector
     */
    void reverse(vector<int>& a,int sta,int end) {
        while(sta<end) {
            swap(a[sta],a[end]);
            sta++;
            end--;
        }
    }
    vector<int> solve(int n, int m, vector<int>& a) {
        // write code here
        m=m%n;
        reverse(a,0,n-1);
        reverse(a,0,m-1);
        reverse(a,m,n-1);
        return a;
    }
    
};
