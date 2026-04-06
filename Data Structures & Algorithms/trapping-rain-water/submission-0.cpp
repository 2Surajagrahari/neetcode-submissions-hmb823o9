class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int res = 0;
        int left_max = 0;
        int right_max = 0;

        for(int i=0;i<n;i++){
            int left_max = height[i];
            int right_max = height[i];
            for(int j=0;j<i;j++){
                left_max = max(left_max,height[j]);
            }

            for(int j=i+1;j<n;j++){
                right_max = max(right_max,height[j]);
            }

            res += min(left_max,right_max) - height[i];

        }
        return res;
    }
};
