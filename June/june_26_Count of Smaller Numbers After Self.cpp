#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        pbds s;
        vector<int> ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[i]=s.order_of_key(nums[i]);
            s.insert(nums[i]);
        }
        return ans;
    }
};