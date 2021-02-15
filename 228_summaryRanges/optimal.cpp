class Solution {
public:
  vector<string> result;
  vector<string> summaryRanges(vector<int>& nums) {
    int start = 0; // starting index of the sample ranges
    if(!nums.size()) return result;
    
    for(int i=1; i<nums.size(); i++){
    // if consecutive then we just continue as range is not decided yet
      if(nums[i-1] + 1 == nums[i]) continue; 
      helper(start, i, nums);
      start = i; // as i is start of next range (num[i] > 1 + num[i-1])
    }
    // taking care of the last range in the array. This is required as the loop exits without recording the last range 
    helper(start, nums.size(), nums); 
    return result;
  }
  void helper(int start, int end, vector<int>& nums){ // NOTE: end is always the start of next range
    string temp = "";
    // case 1 : range is a single number we just have to append "nums[start]" to result
    if(end-1 == start) temp += to_string(nums[start]);
    
    // case 2 : range is from [start,end) 
    else temp += to_string(nums[start]) + "->" + to_string(nums[end-1]);
    result.push_back(temp);
    return;
  }
};
