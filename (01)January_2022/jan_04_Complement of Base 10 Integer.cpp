class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        long long ans=0;
        long long pow[32];
        pow[0]=1;
        for(int i=1;i<32;i++)
            pow[i]=pow[i-1]*2;
        int pos=0;
        while(n)
        {
            if(n%2==0)
                ans+=pow[pos];
            pos++;
            n>>=1;
        }
        return ans;
    }
};