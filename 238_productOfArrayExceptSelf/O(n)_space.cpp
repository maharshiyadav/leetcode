class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    // left vector has product of all elements to the left of curr element and right has product of all right elements
    vector<int> left(nums.size(), 1), right(nums.size(), 1), result(nums.size()); 
    
    // fill left array
    for(int i=1; i<nums.size(); i++) left[i] = left[i-1] * nums[i-1];
    // fill right array
    for(int i=nums.size()-2; i>=0; i--) right[i] = right[i+1] * nums[i+1];
    
    // update result
    for(int i=0; i<nums.size(); i++){
      result[i] = left[i] * right[i];
    }
    return result;
  }
};
