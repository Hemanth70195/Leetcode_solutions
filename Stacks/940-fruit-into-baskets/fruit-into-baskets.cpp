class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int left=0,maxf=0;
        unordered_map<int,int> fcount;

        for(int right =0;right<fruits.size();right++)
        {
            fcount[fruits[right]]++;

            while(fcount.size()>2)
            {
                fcount[fruits[left]]--;
            if(fcount[fruits[left]] == 0)
                fcount.erase(fruits[left]);
            left++;
        }
            maxf = max(maxf,right-left+1);
        }

        return maxf;
    }
};