class Solution {
public:
    int func(vector<int>& piles, int hourly){
        long long total = 0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            total += (piles[i]+hourly-1)/hourly;
        }
        return total;
    }
    int findmax(vector<int>& piles){
        int n = piles.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = findmax(piles);
        int ans = high;
        while(low<=high){
            int mid = low + (high - low)/2;
            long long total = func(piles,mid);
            if(total<=h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
};
