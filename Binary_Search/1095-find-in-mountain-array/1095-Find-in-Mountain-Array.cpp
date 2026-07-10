/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

    int findTarget(int target,MountainArray &mountainArr,int left,int right,int flag)
    {
        if(flag==1)
        {
            while(left<=right)
            {
                int mid=left+(right-left)/2;
                int midd=mountainArr.get(mid);
                if(midd == target)
                    return mid;
                else if(target > midd)
                    left=mid+1;
                else
                    right=mid-1;
            }
        }
        else
        {
            while(left<=right)
            {
                int mid=left+(right-left)/2;
                int midd=mountainArr.get(mid);
                if(midd == target)
                    return mid;
                else if(target > midd)
                    right=mid-1;
                else
                    left=mid+1;
            }
        }
        return -1;
    }

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int res,len=mountainArr.length(),left =0,right=len-1;

        while(left<right)
        {
            int mid = left+(right-left)/2;
            int midd=mountainArr.get(mid);

            if (midd < mountainArr.get(mid+1)) 
            {
                left= mid+1;
            }
            else    right= mid;
        }
        int peak=left;
        //if the peak is found then traverse left and right till u get the target and return the lowest targetted index
        res = findTarget(target,mountainArr,0,peak,1);
        if(res!=-1) return res;
        return res =findTarget(target,mountainArr,peak+1,len-1,2);
    }
};