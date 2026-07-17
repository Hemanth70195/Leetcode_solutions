class Solution {
public:

    int CanEat(vector<int>& piles,int h,int speed)
    {
        long long hour=0;
        for(int pile : piles)
        {
            // hour+=ceil((double)pile/speed);
            hour+=(pile+speed-1)/speed;
        }
        if(hour>h)
            return false;

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;

        for(int pile : piles)
            high = max(high,pile);

        int ans = high;
        while(low <= high)
        {
            int mid=low+(high-low)/2;

            if(CanEat(piles,h,mid))
            {
                ans = mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};