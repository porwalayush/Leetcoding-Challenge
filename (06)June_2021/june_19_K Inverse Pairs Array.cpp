class Solution {
public:
    const int M = 1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> t(n+1, vector<int>(k+1));
        t[0][0] = 1;
        for(int i = 1; i<=n; i++) {
            long long cumSum = 0;
            for(int j = 0; j<=k; j++) {
                if(j == 0) {
                    t[i][j] = 1;
                    cumSum += 1;
                }
                else {
                    cumSum += t[i-1][j];
                    if(j-i >= 0)
                        cumSum -= t[i-1][j-i];
                    t[i][j] = cumSum%M;
                }
            }
        }
		
        return t[n][k];
    }
};