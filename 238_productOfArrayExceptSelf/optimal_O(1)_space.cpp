class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 1);
    // we update result array same as left array
    for(int i=1; i<nums.size(); i++) result[i] = nums[i-1] * result[i-1];
    // instead of right array we just use one right variable
    int right = 1;
    for(int i=nums.size()-1; i>=0; i--){
      // update result array
      result[i] = result[i] * right;
      // update right variable
      right = right * nums[i];
    }
    
    return result;
  }
};
