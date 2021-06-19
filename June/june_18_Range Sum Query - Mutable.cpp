class NumArray {
private:
    vector<int> bit;
    int tt;
public:
    NumArray(vector<int>& nums) {
        bit.resize(30010);
        for(int i=0;i<=30005;i++)
            bit[i]=0;
        tt=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            int pos=i+1,inc=nums[i];
              while(pos<=tt)
              {
                 bit[pos]+=inc;
                 pos=pos+(pos&(-pos));
              }
        }
    }
    
    void update(int index, int inc) {
        int pos=index+1;
        int f=query(pos)-query(pos-1);
        inc=inc-f;
              while(pos<=tt)
              {
                 bit[pos]+=inc;
                 pos=pos+(pos&(-pos));
              }
        
    }
int query(int n)
{
  int ans=0;
  while(n>=1)
  {
     ans+=bit[n];
     n=n-(n&(-n));
  }
  return ans;
}
    
    int sumRange(int left, int right) {
        return query(right+1)-query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */