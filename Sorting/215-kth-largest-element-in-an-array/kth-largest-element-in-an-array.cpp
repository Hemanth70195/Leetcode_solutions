// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int,vector<int>,greater<int>> minheap;
//         for(int i :nums)
//         {
//             minheap.push(i);
//             if(minheap.size() > k)
//             {
//                 minheap.pop();
//             }
//         }
//         return minheap.top();
//     }
// };

class Solution {
public:

    void merge(vector<int> &nums,int st,int mid,int end)
    {   vector<int> temp;
        int i=st;
        int j=mid+1;
        while(i<=mid && j<=end)
        {
            if(nums[i] < nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid)
        {
            temp.push_back(nums[i]);
                i++;
        }
        while(j<=end)
        {
            temp.push_back(nums[j]);
                j++;
        }
        for(int i=0;i<temp.size();i++)
        {
            nums[i+st]= temp[i];
        }
    }


    void mergesort(vector<int> &nums,int st,int end)
    {
        if(st<end)
        {
            int mid = st + (end-st)/2;
            mergesort(nums,st,mid);
            mergesort(nums,mid+1,end);
            merge(nums,st,mid,end);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        mergesort(nums,0,nums.size()-1);
        return nums[nums.size()-k];
    }
};