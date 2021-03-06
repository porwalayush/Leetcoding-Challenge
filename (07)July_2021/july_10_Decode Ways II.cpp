class Solution {
public:
    int numDecodings(string s) {
        long res = s[0] == '*' ? 9 : (s[0] != '0'), las = 1;
        int n = s.size();
        for(int i = 1, k1, k2; i < n; ++i){
            k1 = s[i] == '*' ? 9 : (s[i] != '0');
            switch(s[i-1]){
                case '1':
                    k2 = k1 + (k1 == 0); 
                    break;
                case '2':
                    k2 = s[i] < '7'? (s[i] == '*' ? 6 : 1) : 0; 
                    break;
                case '*':
                    k2 = k1 + (k1 == 0) + (s[i] < '7'? (s[i] == '*' ? 6 : 1) : 0);
                    break;
                default :
                    k2 = 0;
            }
            las = (res * k1 + las * k2) % 1000000007;
            swap(las, res);
        }
        return res;
    }
};