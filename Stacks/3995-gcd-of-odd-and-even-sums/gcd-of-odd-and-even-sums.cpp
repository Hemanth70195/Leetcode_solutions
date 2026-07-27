class Solution {
public:

    int gcd(int evensum, int oddsum)
    {
        while(oddsum!=0)
        {
            int temp=oddsum;
            oddsum=evensum % oddsum;
            evensum=temp;

        }
        return evensum;
    }


    int gcdOfOddEvenSums(int n) 
    {
        int oddsum=0;
        int evensum=0;
        for(int i=1,j=2;i<2*n && j<=2*n;i+=2,j+=2)
        {
            oddsum+=i;
            evensum+=j;
        }
        int g = gcd(evensum,oddsum);
        return g;
    }
};