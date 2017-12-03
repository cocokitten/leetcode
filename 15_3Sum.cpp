class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
        int a,b,c,low,high;
        sort(nums.begin(), nums.end());           //important
        int  n = nums.size();
        
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            a = nums[i];
            low = i+1;
            high = n-1;
            while(low<high){
                b = nums[low];
                c = nums[high];
                if(a+b+c==0){
                    vector<int> v;
                    v.push_back(a);
                    v.push_back(b);
                    v.push_back(c);
                    res.push_back(v);
                    while(low<n-1 && nums[low]==nums[low+1]) low++;
                    while(high>0 && nums[high]==nums[high-1]) high--;
                    low++;
                    high--;
                }else if(a+b+c>0){
                    while(high>0 && nums[high]==nums[high-1]) high--;
                    high--;
                }else{
                    while(low<n-1 && nums[low]==nums[low+1]) low++;
                    low++;
                }
            
            }
        
        }
        return res;
    }
};