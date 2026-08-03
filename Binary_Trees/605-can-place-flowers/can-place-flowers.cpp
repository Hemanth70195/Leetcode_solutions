class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        if(n==0)    return true;
        int size=a.size();
        if(size==1)
        {
            if(a[0] == 0 && n==1)   return true;
        }

        for(int i=0;i<size;i++)
        {
            if(i==0)
            {
                if(a[i] == 0 && a[i+1] == 0)    
                {
                    n--;
                    //  if(n==0)return true;
                    a[i]=1;
                }
            }
            else if(i==size-1)
            {
                if(a[size-1] == 0 && a[size-2] == 0)
                {
                    n--;
                    // if(n==0)    return true;
                    a[i]=1;
                }

            }
            else
            {
                if(a[i] ==0 && a[i-1] == 0 && a[i+1] == 0)
                {
                    n--;
                    // if(n==0)    return true;
                    a[i]=1;
                }
            }
            if(n==0)    return true;

        }
        return false;
    }
};