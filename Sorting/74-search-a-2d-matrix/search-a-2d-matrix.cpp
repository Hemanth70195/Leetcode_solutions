class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int left=0,right=row*col-1;

        while(left <= right)
        {
            int mid = left+(right-left)/2;
            int value = matrix[mid/col][mid%col];

            if(target == value)
            {
                return true;
            }
            else if(target > value)
            {
                left=mid+1;
            }
            else    right=mid-1;
        }
       return false; 
    }
};